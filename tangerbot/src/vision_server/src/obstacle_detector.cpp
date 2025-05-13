#include <chrono>
#include <memory>
#include <vector>
#include <string>
#include <limits>
#include <csignal>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "tangerbot_msgs/msg/local_map.hpp"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/cudaimgproc.hpp>
#include <opencv2/ximgproc.hpp>

#include <cuda_runtime.h>
#include <libsgm.h>
#include "vision_server/sample_common.h"			// device_buffer, ASSERT_MSG, colorize_disparity
#include "vision_server/shared_memory.hpp"		// Slot, Segment, shm::open(), MAX_IMG
#include "ament_index_cpp/get_package_share_directory.hpp"

// Camera & Top‑Down Helper
struct CameraParameters {
	float fu; float fv;
	float u0; float v0;
	float baseline;
	float height;
	float tilt;
};

struct TopDownView {
	TopDownView(const CameraParameters& cam, float res, float max_z, float max_x)
		: cam_(cam), res_(res), max_z_(max_z), max_x_(max_x) {
		bf_		= cam_.baseline * cam_.fu;
		inv_fu_ = 1.f / cam_.fu;
		grid_w_ = static_cast<int>(2.f * max_x_ / res_);
		grid_h_ = static_cast<int>(	 max_z_ / res_);
		grid_	= cv::Mat::zeros(grid_h_, grid_w_, CV_8U);
		std::cout << "[TopDownView] grid " << grid_w_ << " x " << grid_h_ << "  res=" << res_ << "m  bf=" << bf_ << '\n';
	}

	// disparity (CV_32F) → grid_ (미터 X‑Z 평면)
	void createGrid(const cv::Mat& disp32f) {
		grid_.setTo(0);
		const float min_disp = 1.f;
		const float max_disp = 128.f;
		const float max_dist = max_z_;
		for (int y = 0; y < disp32f.rows; y++) {
			for (int x = 0; x < disp32f.cols; x++) {
				float d = disp32f.at<float>(y, x);
				if (d < min_disp || d > max_disp) continue;
				float Z = bf_ / d;
				if (Z > max_dist) continue;
				float X = (x - cam_.u0) * Z * inv_fu_;
				// 좌우 뒤집힘 보정: -X
				int gx = static_cast<int>((-X + max_x_) / res_);
				int gz = static_cast<int>( Z		  / res_);
				if (gx >= 0 && gx < grid_w_ && gz >= 0 && gz < grid_h_)
					grid_.at<uchar>(gz, gx) = 255;
			}
		}
	}
	void draw(cv::Mat& out) const {
		cv::cvtColor(grid_, out, cv::COLOR_GRAY2BGR);
		int rx = static_cast<int>(max_x_ / res_);
		cv::circle(out, {rx, 0}, 5, {0, 255, 0}, -1);	 // robot pose
	}
	
	int grid_w_, grid_h_;
	cv::Mat grid_;
private:
	CameraParameters cam_;
	float bf_, inv_fu_;
	float res_, max_z_, max_x_;
};


// ROS2 Node
using namespace std::chrono_literals;
using namespace shm;

class ObstacleDetector : public rclcpp::Node {
public:
	ObstacleDetector()
		: Node("obstacle_detector_node"), shm_seg_(nullptr) {
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

			// Top‑Down 뷰 초기화
			tdv_ = std::make_unique<TopDownView>(cam_param_, 0.05f, 1.0f, 1.0f);

			// LocalMap 퍼블리셔
			map_pub_ = create_publisher<tangerbot_msgs::msg::LocalMap>("local_map", 10);

			// 주기 타이머 (30 ms)
			timer_ = create_wall_timer(30ms, std::bind(&ObstacleDetector::processOnce, this));

			// 디버그 창
			cv::namedWindow("Left",		  cv::WINDOW_NORMAL);
			cv::namedWindow("Right",	  cv::WINDOW_NORMAL);
			cv::namedWindow("Disparity",  cv::WINDOW_NORMAL);
			cv::namedWindow("TopDown",	  cv::WINDOW_NORMAL);
		}

	~ObstacleDetector() override {
		if (shm_seg_) { shm::close(shm_seg_); shm_seg_ = nullptr; }
		cv::destroyAllWindows();
	}

private:
	// Calibration 
	void loadCalibration() {
		cv::FileStorage fs(calib_file_, cv::FileStorage::READ);
		ASSERT_MSG(fs.isOpened(), "cannot open calibration file");

		fs["mtx_l"] >> K1_; fs["dist_l"] >> D1_;
		fs["mtx_r"] >> K2_; fs["dist_r"] >> D2_;
		fs["R"]	 >> R_;  fs["T"]	 >> T_;
		fs.release();

		cam_size_ = cv::Size(640, 480);	   // 고정 해상도

		cv::Mat R1, R2, P1, P2, Q;
		cv::stereoRectify(K1_, D1_, K2_, D2_, cam_size_, R_, T_,
						  R1, R2, P1, P2, Q, cv::CALIB_ZERO_DISPARITY);

		cv::initUndistortRectifyMap(K1_, D1_, R1, P1, cam_size_, CV_32FC1, map1x_, map1y_);
		cv::initUndistortRectifyMap(K2_, D2_, R2, P2, cam_size_, CV_32FC1, map2x_, map2y_);

		cam_param_.fu		= static_cast<float>(K1_.at<double>(0,0));
		cam_param_.fv		= static_cast<float>(K1_.at<double>(1,1));
		cam_param_.u0		= static_cast<float>(K1_.at<double>(0,2));
		cam_param_.v0		= static_cast<float>(K1_.at<double>(1,2));
		cam_param_.baseline = static_cast<float>(-T_.at<double>(0,0));
		cam_param_.height	= 0.f; cam_param_.tilt = 0.f;

		std::cout << "[Calibration] fu=" << cam_param_.fu
				  << "  baseline=" << cam_param_.baseline << " m\n";
	}

	/*
	// initSGM
	void initSGM() {
		constexpr int DISP = 128;			// disparity size
		//constexpr int DISP = 256;
		constexpr int SRC_DEPTH = 8;		// input 8 bit
		constexpr int DST_DEPTH = 8;		// output 8 bit

		sgm_ = std::make_unique<sgm::StereoSGM>(
				  cam_size_.width, cam_size_.height,
				  DISP, SRC_DEPTH, DST_DEPTH,
				  sgm::EXECUTE_INOUT_CUDA2CUDA);

		int src_bytes = SRC_DEPTH * cam_size_.area() / 8;
		int dst_bytes = DST_DEPTH * cam_size_.area() / 8;

		d_left_  = std::make_unique<device_buffer>(src_bytes);
		d_right_ = std::make_unique<device_buffer>(src_bytes);
		d_disp_  = std::make_unique<device_buffer>(dst_bytes);

		disp_		= cv::Mat(cam_size_, CV_8U);
		disp_color_ = cv::Mat(cam_size_, CV_8UC3);

		invalid_disp_ = sgm_->get_invalid_disparity();
	}
	*/

	void initSGM() {
	    const int disp_size = 256;
	    const int src_depth = 8;
	    const int dst_depth = disp_size < 256 ? 8 : 16;
	    const int width = cam_size_.width;
	    const int height = cam_size_.height;

	    sgm::StereoSGM::Parameters params;
	    params.P1 = 50;
	    params.P2 = 200;
	    params.uniqueness = 0.9f;
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

	// Shared Memory JPEG 읽기 -> GRAY 
	bool readSharedGray(int cam_idx, cv::Mat& gray) {
		Slot& slot = shm_seg_->cam[cam_idx];
		uint32_t size = slot.size.load(std::memory_order_acquire);
		if (size == 0 || size > MAX_IMG) return false;

		std::vector<uint8_t> buf(slot.data.begin(), slot.data.begin() + size);
		cv::Mat img = cv::imdecode(buf, cv::IMREAD_GRAYSCALE);
		if (img.empty()) return false;

		cv::resize(img, gray, cam_size_);	
		return true;
	}

	// sgm
	void processOnce() {
		// 1) Grab two GRAY frames
		cv::Mat gray_l, gray_r;
		if (!readSharedGray(0, gray_l) || !readSharedGray(1, gray_r)) return;

		// 2) Rectify
		cv::remap(gray_l, gray_rect_l_, map1x_, map1y_, cv::INTER_LINEAR);
		cv::remap(gray_r, gray_rect_r_, map2x_, map2y_, cv::INTER_LINEAR);

		// 3) Upload to GPU & SGM
		d_left_->upload (gray_rect_l_.data);
		d_right_->upload(gray_rect_r_.data);

		auto t0 = std::chrono::steady_clock::now();
		sgm_->execute(d_left_->data, d_right_->data, d_disp_->data);
		cudaDeviceSynchronize();
		auto t1 = std::chrono::steady_clock::now();
		double exec_ms = std::chrono::duration<double, std::milli>(t1 - t0).count();

		// 4) Download disparity (CV_8U)
		d_disp_->download(disp_.data);

		// 5) Speckle 제거
		//cv::filterSpeckles(disp_, invalid_disp_, 200, 1.0);

		// 6) CUDA Bilateral Filter
		//cv::cuda::GpuMat g_disp(disp_);
		//cv::cuda::GpuMat g_filt;
		//cv::cuda::bilateralFilter(g_disp, g_filt, 5, 50.0, 50.0);
		//g_filt.download(disp_);

		// 7) disparity → float32
		disp_.convertTo(disp32_, CV_32F, 1.0);

		// 8) Top‑Down Grid 생성
		tdv_->createGrid(disp32_);

		// 9) LocalMap 메시지 구성 & 퍼블리시
		tangerbot_msgs::msg::LocalMap msg;
		msg.robot_id	= "1";
		msg.resolution = 0.05;
		msg.width		= tdv_->grid_w_;
		msg.height		= tdv_->grid_h_;
		msg.origin_x	= -0.5f * msg.width  * msg.resolution;
		msg.origin_y	=  0.0f;
		msg.data.resize(msg.width * msg.height);

		for (int r = 0; r < tdv_->grid_h_; ++r)
			for (int c = 0; c < tdv_->grid_w_; ++c)
				msg.data[r * msg.width + c] =
					tdv_->grid_.at<uchar>(r, c) ? 100 : 0;

		map_pub_->publish(msg);

		// 10) 시각화
		colorize_disparity(disp_, disp_color_, 128, disp_ == invalid_disp_);
		cv::putText(disp_color_,
			cv::format("SGM %.1f ms  FPS %.1f", exec_ms, 1000.0/exec_ms),
			{30,30}, cv::FONT_HERSHEY_SIMPLEX, 0.7, {255, 255, 255}, 1);

		cv::Mat td_img;
		tdv_->draw(td_img);

		cv::imshow("Left",		gray_rect_l_);
		cv::imshow("Right",		gray_rect_r_);
		cv::imshow("Disparity", disp_color_);
		cv::imshow("TopDown",	td_img);
		cv::waitKey(1);
	}

	// ROS
	rclcpp::Publisher<tangerbot_msgs::msg::LocalMap>::SharedPtr map_pub_;
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
	int	invalid_disp_;
	cv::Mat	gray_rect_l_, gray_rect_r_;
	cv::Mat	disp_, disp32_, disp_color_;

	std::unique_ptr<TopDownView> tdv_;

	// Shared Memory
	Segment* shm_seg_;

};

// main
int main(int argc, char** argv) {
	rclcpp::init(argc, argv);
	try {
		auto node = std::make_shared<ObstacleDetector>();
		rclcpp::spin(node);
	} catch (const std::exception& e) {
		std::cerr << "Fatal: " << e.what() << std::endl;
	}
	rclcpp::shutdown();
	return 0;
}
