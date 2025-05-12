#include "rclcpp/rclcpp.hpp"
#include "tangerbot_server/brain.h"
#include "tangerbot_msgs/srv/handle_command.hpp"
#include "tangerbot_msgs/srv/path_planning.hpp"
#include "tangerbot_msgs/srv/get_workload.hpp"
#include "tangerbot_msgs/msg/robot_state.hpp"
#include "tangerbot_msgs/srv/set_follow_mode.hpp"
#include <cstring>

using HandleCommand = tangerbot_msgs::srv::HandleCommand;
using PathPlanning = tangerbot_msgs::srv::PathPlanning;
using GetWorkload = tangerbot_msgs::srv::GetWorkload;
using RobotState = tangerbot_msgs::msg::RobotState;
using SetFollowMode = tangerbot_msgs::srv::SetFollowMode;
using Redirect = tangerbot_msgs::srv::Redirect;

Brain::Brain() : rclcpp::Node("brain") {
    using namespace std::placeholders;
    handle_command_server = this->create_service<HandleCommand>(
        "handle_command",
        std::bind(&Brain::handle_command_callback, this, _1, _2)
    );
    path_planning_client = this->create_client<PathPlanning>("path_planning");
    get_workload_client = this->create_client<GetWorkload>("get_workload");
    robot_state_subscriber = this->create_subscription<RobotState>(
        "robot_state", 10, std::bind(&Brain::robot_state_callback, this, _1)
    );
    set_follow_mode_client = this->create_client<SetFollowMode>("set_follow_mode");
    redirect_client = this->create_client<Redirect>("redirect");
}

void Brain::handle_command_callback(const std::shared_ptr<HandleCommand::Request> request,
    std::shared_ptr<HandleCommand::Response> response)
{
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Handle Command!");
}

void Brain::robot_state_callback(const RobotState::SharedPtr msg) {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Robot ID: %s", msg->robot_id.c_str());
}

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Brain>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
