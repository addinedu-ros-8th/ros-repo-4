#include "rclcpp/rclcpp.hpp"
#include "tangerbot_msgs/srv/handle_command.hpp"
#include "tangerbot_msgs/srv/path_planning.hpp"
#include "tangerbot_msgs/srv/get_workload.hpp"
#include "tangerbot_msgs/msg/robot_state.hpp"
#include "tangerbot_msgs/srv/set_follow_mode.hpp"
#include "tangerbot_msgs/srv/redirect.hpp"

class Brain : public rclcpp::Node {
    using HandleCommand = tangerbot_msgs::srv::HandleCommand;
    using PathPlanning = tangerbot_msgs::srv::PathPlanning;
    using GetWorkload = tangerbot_msgs::srv::GetWorkload;
    using RobotState = tangerbot_msgs::msg::RobotState;
    using SetFollowMode = tangerbot_msgs::srv::SetFollowMode;
    using Redirect = tangerbot_msgs::srv::Redirect;
public:
    Brain();
private:
    rclcpp::Service<HandleCommand>::SharedPtr handle_command_server;
    rclcpp::Client<PathPlanning>::SharedPtr path_planning_client;
    rclcpp::Client<GetWorkload>::SharedPtr get_workload_client;
    rclcpp::Subscription<RobotState>::SharedPtr robot_state_subscriber;
    rclcpp::Client<SetFollowMode>::SharedPtr set_follow_mode_client;
    rclcpp::Client<Redirect>::SharedPtr redirect_client;
    void handle_command_callback(const std::shared_ptr<HandleCommand::Request> request,
                                std::shared_ptr<HandleCommand::Response> response);

    void robot_state_callback(const RobotState::SharedPtr msg);
};