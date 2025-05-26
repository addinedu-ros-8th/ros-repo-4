
#ifndef TANGERBOT_SERVER_BRAIN_H
#define TANGERBOT_SERVER_BRAIN_H

//ros
#include <rclcpp/rclcpp.hpp>
#include "rclcpp_action/rclcpp_action.hpp"

//action
#include "tangerbot_msgs/action/path_planning.hpp"
#include "nav2_msgs/action/follow_path.hpp"
#include "tangerbot_msgs/action/parking.hpp"

//service
#include "tangerbot_msgs/srv/handle_command.hpp"
#include "tangerbot_msgs/srv/set_follow_mode.hpp"
#include "tangerbot_msgs/srv/set_state.hpp"
#include "tangerbot_msgs/srv/sign_up.hpp"
//#include "tangerbot_msgs/srv/sign_in.hpp"

//message
#include "tangerbot_msgs/msg/robot_state.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "std_msgs/msg/bool.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "tangerbot_msgs/msg/call_state.hpp"
#include "tangerbot_msgs/msg/obstacle_bool.hpp"

//sql
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>


#include <chrono>
#include <thread>
#include <unordered_map>
#include <string>

//action
using PathPlanning = tangerbot_msgs::action::PathPlanning;
using FollowPath = nav2_msgs::action::FollowPath;
using Parking = tangerbot_msgs::action::Parking;

//service
using HandleCommand = tangerbot_msgs::srv::HandleCommand;
using SetFollowMode = tangerbot_msgs::srv::SetFollowMode;
using SetState = tangerbot_msgs::srv::SetState;
using SignUp = tangerbot_msgs::srv::SignUp;
//using SignIn = tangerbot_msgs::srv::SignIn;

//message
using RobotState = tangerbot_msgs::msg::RobotState;
using CallState = tangerbot_msgs::msg::CallState;
using Twist = geometry_msgs::msg::Twist;
using ObstacleBool = tangerbot_msgs::msg::ObstacleBool;

struct Quaternion {
    double w, x, y, z;
};

class Brain : public rclcpp::Node {    
public:
    Brain();
    ~Brain();

private:
    rclcpp::Service<HandleCommand>::SharedPtr handle_command_server_;
    rclcpp::Service<SignUp>::SharedPtr signup_server_;
    //rclcpp::Service<SignIn>::SharedPtr signin_server_;
    rclcpp_action::Client<tangerbot_msgs::action::PathPlanning>::SharedPtr path_planning_client_;
    std::unordered_map<std::string, rclcpp_action::Client<FollowPath>::SharedPtr> follow_path_client_;
    std::unordered_map<std::string, rclcpp_action::ClientGoalHandle<nav2_msgs::action::FollowPath>::SharedPtr> goal_handle_;
    std::unordered_map<std::string, rclcpp_action::Client<Parking>::SharedPtr> parking_client_;
    rclcpp::Client<SetFollowMode>::SharedPtr vision_set_follow_mode_client_;
    rclcpp::Client<SetFollowMode>::SharedPtr tserver_set_follow_mode_client_;
    rclcpp::Client<SetFollowMode>::SharedPtr set_human_pose_mode_client_;
    std::unordered_map<std::string, rclcpp::Client<SetState>::SharedPtr> set_state_client_;
    rclcpp::Subscription<RobotState>::SharedPtr robot_states_;
    rclcpp::Subscription<ObstacleBool>::SharedPtr obstacle_subscriber_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_publisher_;
    rclcpp::Publisher<tangerbot_msgs::msg::CallState>::SharedPtr call_state_publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    //declare variable 
    std::string ns[3] = {"robot1", "robot2", "robot3"};
    std::unique_ptr<sql::Connection> db;
    sql::mysql::MySQL_Driver* db_driver_;
    std::shared_ptr<tangerbot_msgs::msg::RobotState> robot_state_;
    std::unordered_map<std::string, RobotState> robot_states_data_;
    std::unordered_map<std::string, geometry_msgs::msg::PoseStamped> section_poses_;
    std::unordered_map<std::string, std::string> robot_home_map_;
    std::unordered_map<std::string, nav_msgs::msg::Path> selected_robot_path_;
    geometry_msgs::msg::PoseStamped goal_pose_;
    std::unordered_map<std::string, std::atomic_bool> obstacle_detected_;
    float current_distance_remaining_ = 0.0;
    float workload_ = 0.0;
    std::string selected_robot_id_;
    std::string section_;
    std::string user_id_;
    std::string selected_storage_;


    
    //thread
    std::unordered_map<std::string, std::thread> threadMove_;
    std::unordered_map<std::string, std::thread> threadReturnStorage_;
    std::unordered_map<std::string, std::thread> threadReturnHome_;
    std::unordered_map<std::string, std::thread> threadParking_;


    // callback
    void signup_callback(const std::shared_ptr<tangerbot_msgs::srv::SignUp::Request> request,
                            const std::shared_ptr<tangerbot_msgs::srv::SignUp::Response> response);
    void robot_state_callback(const tangerbot_msgs::msg::RobotState::SharedPtr msg);
    void handle_command_service_callback(
        const std::shared_ptr<tangerbot_msgs::srv::HandleCommand::Request> request,
        std::shared_ptr<tangerbot_msgs::srv::HandleCommand::Response> response);
    void obstacle_callback(const ObstacleBool::SharedPtr msg);
    void set_robot_state(const std::string& robot_id, int main_status, int motion_status);

    //thread
    void move_to_section(const std::shared_ptr<tangerbot_msgs::srv::HandleCommand::Request> request);
    void return_to_storage(const std::shared_ptr<tangerbot_msgs::srv::HandleCommand::Request> request);
    void return_to_home(const std::shared_ptr<tangerbot_msgs::srv::HandleCommand::Request> request);
    void parking(const std::string selected_robot_id);

    //timer
    void timer_callback();

    //helper
    
    Quaternion yaw_deg_to_quaternion(int yaw_deg);
    std::string select_optimal_robot(const geometry_msgs::msg::PoseStamped &goal_pose);
    std::shared_ptr<tangerbot_msgs::action::PathPlanning::Result> request_path_planning_action(
                            const std::string& robot_id, const geometry_msgs::msg::PoseStamped& goal_pose);
    std::string select_storage(const std::string& robot_id);
    
};

#endif // TANGERBOT_SERVER_BRAIN_H




