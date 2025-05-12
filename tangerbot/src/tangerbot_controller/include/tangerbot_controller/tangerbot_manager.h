#ifndef TANGERBOT_MANAGER_H
#define TANGERBOT_MANAGER_H

#include "rclcpp/rclcpp.hpp"
#include "tangerbot_msgs/msg/robot_state.hpp"
#include "tangerbot_msgs/msg/robot_pose.hpp"
#include "tangerbot_msgs/srv/set_state.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include <string>
#include <memory>

using namespace std;

class TangerbotManager : public rclcpp::Node {
private:
    string robot_id;
    int main_status;
    int motion_status;
    float battery=100.0f;

    rclcpp::Publisher<tangerbot_msgs::msg::RobotState>::SharedPtr state_publisher;

    rclcpp::Subscription<tangerbot_msgs::msg::RobotPose>::SharedPtr person_pose_subscriber;

    rclcpp::Service<tangerbot_msgs::srv::SetState>::SharedPtr set_state_server;

    rclcpp::TimerBase::SharedPtr timer_;

    void set_state(const std::shared_ptr<tangerbot_msgs::srv::SetState::Request> request,
    std::shared_ptr<tangerbot_msgs::srv::SetState::Response> response);
    void person_pose_callbacks(const tangerbot_msgs::msg::RobotPose::SharedPtr msg);
    void state_callbacks();

public:
    TangerbotManager();
};

#endif 