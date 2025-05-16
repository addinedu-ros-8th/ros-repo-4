#include <chrono>
#include <memory>
#include <vector>
#include <string>
#include <limits>
#include <csignal>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "tangerbot_msgs/msg/local_map.hpp"
#include <geometry_msgs/msg/point_stamped.hpp>
#include "tangerbot_msgs/srv/set_follow_mode.hpp"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/cudaimgproc.hpp>
#include <opencv2/ximgproc.hpp>

#include <cuda_runtime.h>
#include <libsgm.h>
#include "vision_server/sample_common.h"
#include "vision_server/shared_memory.hpp"
#include "ament_index_cpp/get_package_share_directory.hpp"

// Camera
struct CameraParameters {
    float fu; float fv;
    float u0; float v0;
    float baseline;
    float height;
    float tilt;
};

using namespace std::chrono_literals;
using namespace shm;
using namespace std;

class Follower : public rclcpp::Node {
public:
    Follower() : Node("follower_node"), shm_seg_(nullptr), active_(false), robot_id_(-1){
        declare_parameter<std::string>("calib_file", ament_index_cpp::get_package_share_directory("vision_server") + "/config/calibration_data.yml");
        get_parameter("calib_file", calib_file_);

        // 공유 메모리 열기
        shm_seg_ = shm::open(false);
        if (!shm_seg_) {
            throw std::runtime_error("shared memory open failed");
        }
        
        // 카메라 파라미터 로드
        loadCalibration();

        // SGM 초기화
        initSGM();

        service_ = this->create_service<tangerbot_msgs::srv::SetFollowMode>(
            "set_follower_mode",
            std::bind(&Follower::handle_set_follower, this, std::placeholders::_1, std::placeholders::_2)
        );

        // HumanPose 서브스크라이버
        human_sub_ = create_subscription<geometry_msgs::msg::PointStamped>(
            "object_pixel", 10, std::bind(&Follower::point_callback, this, std::placeholders::_1));

        // FinalHumanPose 퍼블리셔
        point_pub_ = create_publisher<geometry_msgs::msg::PointStamped>("transformed_point", 10);

        // depthmap 생성
        timer_ = create_wall_timer(30ms, std::bind(&Follower::processOnce, this));

        // 테스트
        //robot_id_ = 0;
        //active_ = true;
    }

    ~Follower() override {
        if (shm_seg_) { shm::close(shm_seg_); shm_seg_ = nullptr; }
        cv::destroyAllWindows();
    }

private:
    void handle_set_follower(
        const std::shared_ptr<tangerbot_msgs::srv::SetFollowMode::Request> req,
        std::shared_ptr<tangerbot_msgs::srv::SetFollowMode::Response> res) {
        string tmp = req->robot_id;        
        robot_id_ = stoi(tmp.substr(5));
        robot_id_--;
        active_ = req->mode;        // 동작 on/off
        res->success = true;
        RCLCPP_INFO(get_logger(),
          "[Follower] robot %u %s", robot_id_,
          active_ ? "ENABLED" : "DISABLED"
        );
    }

    void point_callback(const geometry_msgs::msg::PointStamped::SharedPtr msg) {
        if (!active_) return;

        RCLCPP_INFO(this->get_logger(), "Received point: (x: %.2f, y: %.2f, z: %.2f), frame_id: %s",
                    msg->point.x, msg->point.y, msg->point.z, msg->header.frame_id.c_str());

        // publisher message
        auto transformed_msg = geometry_msgs::msg::PointStamped();
        transformed_msg.header = msg->header;
        transformed_msg.point.x = msg->point.x;
        transformed_msg.point.y = msg->point.y;

        int x = static_cast<int>(msg->point.x);
        int y = static_cast<int>(msg->point.y);

        // invalid (x, y)
        if (x < 0 || x >= cam_size_.width || y < 0 || y >= cam_size_.height) {
            RCLCPP_WARN(this->get_logger(), "Point (x: %d, y: %d) is out of image bounds", x, y);
            return; // 퍼블리시 중단
        }

        float disparity;
        if (disp_.type() == CV_8U) {
            disparity = static_cast<float>(disp_.at<uint8_t>(y, x));
        } else if (disp_.type() == CV_16U) {
            disparity = static_cast<float>(disp_.at<uint16_t>(y, x));
        } else {
            RCLCPP_ERROR(this->get_logger(), "Unsupported disparity map type");
            return; // 퍼블리시 중단
        }

        // Invalid disparity
        if (disparity == invalid_disp_ || disparity <= 0) {
            RCLCPP_WARN(this->get_logger(), "Invalid disparity at (x: %d, y: %d): %.2f", x, y, disparity);
            return; // 퍼블리시 중단
        }

        // z = (f * b) / d
        float z = (cam_param_.fu * cam_param_.baseline) / disparity;
        transformed_msg.point.z = z;

        // publish
        point_pub_->publish(transformed_msg);
        RCLCPP_INFO(this->get_logger(), "Published transformed point: (x: %.2f, y: %.2f, z: %.2f)",
                    transformed_msg.point.x, transformed_msg.point.y, transformed_msg.point.z);
    }

    void loadCalibration() {
        cv::FileStorage fs(calib_file_, cv::FileStorage::READ);
        ASSERT_MSG(fs.isOpened(), "cannot open calibration file");

        fs["mtx_l"] >> K1_; fs["dist_l"] >> D1_;
        fs["mtx_r"] >> K2_; fs["dist_r"] >> D2_;
        fs["R"] >> R_;  fs["T"] >> T_;
        fs.release();

        cam_size_ = cv::Size(640, 480);

        cv::Mat R1, R2, P1, P2, Q;
        cv::stereoRectify(K1_, D1_, K2_, D2_, cam_size_, R_, T_,
                          R1, R2, P1, P2, Q, cv::CALIB_ZERO_DISPARITY);

        cv::initUndistortRectifyMap(K1_, D1_, R1, P1, cam_size_, CV_32FC1, map1x_, map1y_);
        cv::initUndistortRectifyMap(K2_, D2_, R2, P2, cam_size_, CV_32FC1, map2x_, map2y_);

        cam_param_.fu = static_cast<float>(K1_.at<double>(0,0));
        cam_param_.fv = static_cast<float>(K1_.at<double>(1,1));
        cam_param_.u0 = static_cast<float>(K1_.at<double>(0,2));
        cam_param_.v0 = static_cast<float>(K1_.at<double>(1,2));
        cam_param_.baseline = static_cast<float>(-T_.at<double>(0,0));
        cam_param_.height = 0.f; cam_param_.tilt = 0.f;

        std::cout << "[Calibration] fu=" << cam_param_.fu << "  baseline=" << cam_param_.baseline << " m\n";
    }

    void initSGM() {
        const int disp_size = 256;
        const int src_depth = 8;
        const int dst_depth = disp_size < 256 ? 8 : 16;
        const int width = cam_size_.width;
        const int height = cam_size_.height;

        sgm::StereoSGM::Parameters params;
        params.P1 = 35;
        params.P2 = 110;
        params.uniqueness = 0.90f;
        params.LR_max_diff = 1;
        params.census_type = sgm::CensusType::SYMMETRIC_CENSUS_9x7;

        sgm_ = std::make_unique<sgm::StereoSGM>(
            width, height,
            disp_size, src_depth, dst_depth,
            sgm::EXECUTE_INOUT_CUDA2CUDA,
            params
        );

        int src_bytes = src_depth * width * height / 8;
        int dst_bytes = dst_depth * width * height / 8;

        d_left_ = std::make_unique<device_buffer>(src_bytes);
        d_right_ = std::make_unique<device_buffer>(src_bytes);
        d_disp_ = std::make_unique<device_buffer>(dst_bytes);

        disp_ = cv::Mat(cam_size_, dst_depth == 16 ? CV_16U : CV_8U);
        disp_color_ = cv::Mat(cam_size_, CV_8UC3);

        invalid_disp_ = sgm_->get_invalid_disparity();
    }

    bool readSharedGray(int robot_id, int cam_idx, cv::Mat& gray) {
        Slot& slot = shm_seg_->cam[robot_id][cam_idx];
        uint32_t size = slot.size.load(std::memory_order_acquire);
        if (size == 0 || size > MAX_IMG) return false;

        std::vector<uint8_t> buf(slot.data.begin(), slot.data.begin() + size);
        cv::Mat img = cv::imdecode(buf, cv::IMREAD_GRAYSCALE);
        if (img.empty()) return false;

        cv::resize(img, gray, cam_size_);
        return true;
    }

    void processOnce() {
        if (!active_) return;

        // 1) Grab two GRAY frames
        cv::Mat gray_l, gray_r;


        /////
        if (!readSharedGray(robot_id_, 0, gray_l)) {
            RCLCPP_WARN(get_logger(), "[Follower] readSharedGray left failed");
            return;
        }
        if (!readSharedGray(robot_id_, 1, gray_r)) {
            RCLCPP_WARN(get_logger(), "[Follower] readSharedGray right failed");
            return;
        }
        /////


        if (!readSharedGray(robot_id_, 0, gray_l) || !readSharedGray(robot_id_, 1, gray_r)) return;

        // 2) Rectify
        cv::remap(gray_l, gray_rect_l_, map1x_, map1y_, cv::INTER_LINEAR);
        cv::remap(gray_r, gray_rect_r_, map2x_, map2y_, cv::INTER_LINEAR);

        // 3) Upload to GPU & SGM
        d_left_->upload(gray_rect_l_.data);
        d_right_->upload(gray_rect_r_.data);

        auto t0 = std::chrono::steady_clock::now();
        sgm_->execute(d_left_->data, d_right_->data, d_disp_->data);
        cudaDeviceSynchronize();
        auto t1 = std::chrono::steady_clock::now();
        double exec_ms = std::chrono::duration<double, std::milli>(t1 - t0).count();

        // 4) Download disparity
        d_disp_->download(disp_.data);

        // 5) disparity → float32
        disp_.convertTo(disp32_, CV_32F, 1.0);

        // 6) 시각화
        colorize_disparity(disp_, disp_color_, 128, disp_ == invalid_disp_);
        cv::putText(disp_color_,
                    cv::format("SGM %.1f ms  FPS %.1f", exec_ms, 1000.0/exec_ms),
                    {30,30}, cv::FONT_HERSHEY_SIMPLEX, 0.7, {255, 255, 255}, 1);

        cv::imshow("Left", gray_rect_l_);
        cv::imshow("Right", gray_rect_r_);
        cv::imshow("Disparity", disp_color_);
        cv::waitKey(1);
    }

    rclcpp::Subscription<geometry_msgs::msg::PointStamped>::SharedPtr human_sub_;
    rclcpp::Publisher<geometry_msgs::msg::PointStamped>::SharedPtr point_pub_;
    rclcpp::TimerBase::SharedPtr timer_;

    // Calibration & Rectification
    std::string calib_file_;
    cv::Mat K1_, K2_, D1_, D2_, R_, T_;
    cv::Mat map1x_, map1y_, map2x_, map2y_;
    cv::Size cam_size_;
    CameraParameters cam_param_;

    // Vision Buffers
    std::unique_ptr<sgm::StereoSGM> sgm_;
    std::unique_ptr<device_buffer> d_left_, d_right_, d_disp_;
    int invalid_disp_;
    cv::Mat gray_rect_l_, gray_rect_r_;
    cv::Mat disp_, disp32_, disp_color_;

    Segment* shm_seg_;

    rclcpp::Service<tangerbot_msgs::srv::SetFollowMode>::SharedPtr service_;
    bool active_;
    uint8_t robot_id_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    try {
        auto node = std::make_shared<Follower>();
        rclcpp::spin(node);
    } catch (const std::exception& e) {
        std::cerr << "Fatal: " << e.what() << std::endl;
    }
    rclcpp::shutdown();
    return 0;
}

