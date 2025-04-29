#include "rclcpp/rclcpp.hpp"
#include "tangerbot_msgs/srv/handle_command.hpp"

class Brain : public rclcpp::Node {
    using HandleCommand = tangerbot_msgs::srv::HandleCommand;
public:
    Brain();
private:
    rclcpp::Service<HandleCommand>::SharedPtr handle_command_server;
    void handle_command_callback(const std::shared_ptr<HandleCommand::Request> request,
                                std::shared_ptr<HandleCommand::Response> response);
};