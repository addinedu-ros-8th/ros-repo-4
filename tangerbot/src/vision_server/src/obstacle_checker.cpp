#include <iostream> 
#include <cmath>
#include <algorithm>

#include "rclcpp/rclcpp.hpp"
#include <std_msgs/msg/bool.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>

using namespace std;

class ObstacleChecker : public rclcpp::Node {
public:
    ObstacleChecker() : Node("obstacle_checker") {
        lidar_sub_ = create_subscription<sensor_msgs::msg::LaserScan>(
            "/scan", 10, bind(&ObstacleChecker::scan_callback, this, placeholders::_1));
        
        obs_pub_ = create_publisher<std_msgs::msg::Bool>("obstacle_bool", 10);   
        
        (*this).threshold_distance_ = 0.15f;   // meters
        (*this).roi_angle_ = 30.0f;
        cout << "Start" << endl;
    }
private:
    void scan_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg) {
        ranges_ = msg->ranges;
        angle_min_ = msg->angle_min;
        angle_increment_ = msg->angle_increment;

        // 정면 인덱스 계산
        front_angle_ = M_PI;
        front_index_ = int((front_angle_ - angle_min_) / angle_increment_);

        // ROI 범위설정
        roi_half_angle_ = ((*this).roi_angle_ / 2.0f) * M_PI / 180.0f;
        roi_half_steps_ = int(roi_half_angle_ / angle_increment_);
        
        start_index_ = max(0, int(front_index_ - roi_half_steps_));
        end_index_ = min(int(ranges_.size() - 1), int(front_index_ + roi_half_steps_));

        if (roi_.size() < end_index_ - start_index_) roi_.resize(end_index_ - start_index_);
        copy(ranges_.begin() + start_index_, ranges_.begin() + end_index_, roi_.begin());

        auto min_it = min_element(roi_.begin(), roi_.end());

        detected_ = roi_.size() > 0 && *min_it <= threshold_distance_;

        auto my_msg = std_msgs::msg::Bool();
        my_msg.data = detected_;

        obs_pub_->publish(my_msg);

        return;
    }

    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr lidar_sub_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr obs_pub_;

    float threshold_distance_;
    float roi_angle_;
    float roi_half_angle_;
    float angle_increment_;
    float front_angle_;
    float front_index_;
    float angle_min_;
    float roi_half_steps_;
    int start_index_;
    int end_index_;
    bool detected_;
    vector<float> ranges_;
    vector<float> roi_;
};

int main(int argc, char **argv) {
    cout << "Hi" << '\n';

    rclcpp::init(argc, argv);
    try {
        auto node = make_shared<ObstacleChecker>();
        rclcpp::spin(node);
    } catch (const std::exception& e) {
        cerr << "Fatal: " << e.what() << endl;
    }
    rclcpp::shutdown();
    
    return 0;
}
