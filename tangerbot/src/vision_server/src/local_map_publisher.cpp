#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class LocalMapPublisher : public rclcpp::Node {
public:
    LocalMapPublisher() : Node("local_map_publisher"), count_(0) {
        
    }
private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
}
