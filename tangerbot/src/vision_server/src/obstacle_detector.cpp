#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "tangerbot_msgs/msg/local_map.hpp"

using namespace std::chrono_literals;

class ObstacleDetector : public rclcpp::Node {
public:
    ObstacleDetector() : Node("local_map_publisher") {
        //publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
        publisher_ = this->create_publisher<tangerbot_msgs::msg::LocalMap>("local_map", 10);
        timer_ = this->create_wall_timer(500ms, std::bind(&ObstacleDetector::timer_callback, this));

        // 라이다 데이터 받아야 한다
        /*
        subscriber_ = this->create_subscription<std_msgs::msg::String>(
            "chatter", 10,
            std::bind(&ObstacleDetector::lidar_callback, this, std::placeholders::_1)
        );
        */
    }
private:
    void timer_callback() {
        auto message = tangerbot_msgs::msg::LocalMap();
        message.robot_id = "1";
        message.resolution = 0.05;
        message.width = 10;
        message.height = 10;
        message.origin_x = -2.5;
        message.origin_y = -2.5;
    
        // 10x10 = 100 셀짜리 더미 데이터
        message.data.resize(message.width * message.height, 0);

        // 예시: 가운데 셀만 장애물로 설정 (Occupied = 100)
        int center = (message.height / 2) * message.width + (message.width / 2);
        message.data[center] = 100;

        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.robot_id.c_str());
        RCLCPP_INFO(this->get_logger(), "Publishing: '%f'", message.resolution);
        publisher_->publish(message);
    }

    // 라이다 데이터
    /*
    void lidar_callback() {
        return;
    }
    */

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<tangerbot_msgs::msg::LocalMap>::SharedPtr publisher_;
    // 라이다 데이터
    //rclcpp::Subscription<다른_타입>::SharedPtr subscriber_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ObstacleDetector>());
    rclcpp::shutdown();

    return 0;
}
