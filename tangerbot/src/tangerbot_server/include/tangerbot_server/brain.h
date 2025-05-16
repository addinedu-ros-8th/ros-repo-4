
#ifndef TANGERBOT_SERVER_BRAIN_H
#define TANGERBOT_SERVER_BRAIN_H

//ros
#include <rclcpp/rclcpp.hpp>
#include "rclcpp_action/rclcpp_action.hpp"

//action
#include "tangerbot_msgs/action/path_planning.hpp"
#include "nav2_msgs/action/follow_path.hpp"

//service
#include "tangerbot_msgs/srv/handle_command.hpp"
#include "tangerbot_msgs/srv/get_workload.hpp"
#include "tangerbot_msgs/srv/set_follow_mode.hpp"
#include "tangerbot_msgs/srv/set_state.hpp"
#include "tangerbot_msgs/srv/redirect.hpp"

//message
#include "tangerbot_msgs/msg/robot_state.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "std_msgs/msg/bool.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <thread>
#include <unordered_map>
#include <string>




class Brain : public rclcpp::Node {
    

public:
    //action
    using PathPlanning = tangerbot_msgs::action::PathPlanning;
    using FollowPath = nav2_msgs::action::FollowPath;

    //service
    using HandleCommand = tangerbot_msgs::srv::HandleCommand;
    using GetWorkload = tangerbot_msgs::srv::GetWorkload;
    using SetFollowMode = tangerbot_msgs::srv::SetFollowMode;
    using SetState = tangerbot_msgs::srv::SetState;
    using Redirect = tangerbot_msgs::srv::Redirect;

    //message
    using RobotState = tangerbot_msgs::msg::RobotState;
    using Twist = geometry_msgs::msg::Twist;


    Brain();
    ~Brain();
    
    rclcpp::Client<GetWorkload>::SharedPtr get_workload_client_;
    float request_workload(const std::string &robot_id);


private:
    rclcpp::Service<HandleCommand>::SharedPtr handle_command_server_;
    rclcpp_action::Client<tangerbot_msgs::action::PathPlanning>::SharedPtr path_planning_client_;
    rclcpp_action::Client<FollowPath>::SharedPtr follow_path_client_;
    rclcpp_action::ClientGoalHandle<nav2_msgs::action::FollowPath>::SharedPtr goal_handle_;
    rclcpp::Client<SetFollowMode>::SharedPtr set_follow_mode_client_;
    rclcpp::Client<SetState>::SharedPtr set_state_client_;
    rclcpp::Client<Redirect>::SharedPtr redirect_client_;
    rclcpp::Subscription<RobotState>::SharedPtr robot_states_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr obstacle_subscriber_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_publisher_;

    //declare variable 
    std::shared_ptr<tangerbot_msgs::msg::RobotState> robot_state_;
    std::unordered_map<std::string, RobotState> robot_states_data_;
    std::unordered_map<std::string, geometry_msgs::msg::PoseStamped> section_poses_;
    nav_msgs::msg::Path selected_robot_path_;
    std::atomic_bool obstacle_detected_{false};
    std::string current_robot_id_;

    
    //thread
    std::thread threadMove_;


    // callback
    void robot_state_callback(const tangerbot_msgs::msg::RobotState::SharedPtr msg);
    void handle_command_service_callback(
        const std::shared_ptr<tangerbot_msgs::srv::HandleCommand::Request> request,
        std::shared_ptr<tangerbot_msgs::srv::HandleCommand::Response> response);
    void obstacle_callback(const std_msgs::msg::Bool::SharedPtr msg);

    //thread
    void move_to_section(const geometry_msgs::msg::PoseStamped& goal_pose);

    //helper
    std::string select_optimal_robot(const geometry_msgs::msg::PoseStamped &goal_pose);
    std::shared_ptr<tangerbot_msgs::action::PathPlanning::Result> request_path_planning_action(
                            const std::string& robot_id, const geometry_msgs::msg::PoseStamped& goal_pose);
    bool set_robot_state(const std::string& robot_id, int main_status, int motion_status);
};

#endif // TANGERBOT_SERVER_BRAIN_H