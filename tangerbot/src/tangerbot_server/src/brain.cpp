#include "rclcpp/rclcpp.hpp"
#include "tangerbot_server/brain.h"
#include "tangerbot_msgs/srv/handle_command.hpp"

using HandleCommand = tangerbot_msgs::srv::HandleCommand;
Brain::Brain() : rclcpp::Node("brain") {
    using namespace std::placeholders;
    handle_command_server = this->create_service<HandleCommand>(
        "handle_command",
        std::bind(&Brain::handle_command_callback, this, std::placeholders::_1, std::placeholders::_2)
    );
}

void Brain::handle_command_callback(const std::shared_ptr<HandleCommand::Request> request,
    std::shared_ptr<HandleCommand::Response> response)
{
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Handle Command!");
}

int main() {
    return 0;
}