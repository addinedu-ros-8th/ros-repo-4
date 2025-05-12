#include <iostream>
#include <string>
#include <cstdint>
#include <chrono>
using std::string;

#include "rclcpp/rclcpp.hpp"
#include "tangerbot_msgs/msg/robot_state.hpp"
#include "tangerbot_msgs/msg/robot_pose.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;


class TangerbotManager : public rclcpp::Node
{
private:
    string robot_id;
    int main_status;
    int motion_status;
    float battery=100.0f;

    rclcpp::Publisher<tangerbot_msgs::msg::RobotState>::SharedPtr state_publisher;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_publisher;

    rclcpp::Subscription<tangerbot_msgs::msg::RobotPose>::SharedPtr pose_subscriber;
    rclcpp::Subscription<tangerbot_msgs::msg::RobotPose>::SharedPtr goal_pose_subscriber;
    rclcpp::Subscription<tangerbot_msgs::msg::RobotPose>::SharedPtr person_pose_subscriber;

    rclcpp::TimerBase::SharedPtr timer_;

    geometry_msgs::msg::PoseStamped current_pose; 
    geometry_msgs::msg::PoseStamped goal_pose;


public:
    /************************************************
     * * CONSTRUCTOR 
     * @node_name: tangerbot_manager
     * @description: This node is responsible for managing the robot's state and pose.
     ************************************************/
    TangerbotManager() : Node("tangerbot_manager")
    {
        //initalization
        this->main_status = tangerbot_msgs::msg::RobotState::IDLE;
        this->goal_pose = geometry_msgs::msg::PoseStamped();
        this->motion_status = tangerbot_msgs::msg::RobotState::STOP;

        //publisher
        state_publisher = this->create_publisher<tangerbot_msgs::msg::RobotState>("robot_state", 10); 
        cmd_vel_publisher = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
        timer_ = this->create_wall_timer(500ms, std::bind(&TangerbotManager::state_callbacks, this));
        
        //subscriber
        pose_subscriber = this->create_subscription<tangerbot_msgs::msg::RobotPose>(
            "robot_pose", 10, std::bind(&TangerbotManager::pose_callbacks, this, std::placeholders::_1));
        goal_pose_subscriber = this->create_subscription<tangerbot_msgs::msg::RobotPose>(
            "goal_pose", 10, std::bind(&TangerbotManager::goal_pose_callbacks, this, std::placeholders::_1));
        person_pose_subscriber = this->create_subscription<tangerbot_msgs::msg::RobotPose>(
            "person_pose", 10, std::bind(&TangerbotManager::person_pose_callbacks, this, std::placeholders::_1));
        
        // Initialize the robot ID

    }
    //TODO (revise parameter?)
    /************************************************
     * * Set Robot State
     * Robot Status: [Idle, Working], [Moving, Following, Stop, Loading]
     * @param robotID, mainStatus, motionStatus, battery  
    *************************************************/
    void set_state(string robotID, int mainStatus, int motionStatus, float battery) {
        auto msg = tangerbot_msgs::msg::RobotState();
        msg.robot_id = robotID;
        msg.main_status = mainStatus;
        msg.motion_status = motionStatus;
        msg.battery = battery;
        state_publisher->publish(msg);

        RCLCPP_INFO(this->get_logger(), "Published Robot State: %s, %d, %d, %.2f%%", robotID.c_str(), mainStatus, motionStatus, battery);
    }

    /************************************************
     * * Goal Pose Callbacks
     * * A new goal pose is received
     * Updates the internal goal_pose variable with the received position and orientation
     * @msg: incoming goal pose 
    *************************************************/
    void goal_pose_callbacks(const tangerbot_msgs::msg::RobotPose::SharedPtr msg) {
        goal_pose.pose.position.x = msg->pose.pose.position.x;
        goal_pose.pose.position.y = msg->pose.pose.position.y;
        goal_pose.pose.orientation.z = msg->pose.pose.orientation.z;
        RCLCPP_INFO(this->get_logger(), "Received new goal pose: x=%.2f, y=%.2f, theta=%.2f", 
                    msg->pose.pose.position.x, msg->pose.pose.position.y, msg->pose.pose.orientation.z);
    }

    /************************************************
     * * Pose Callbacks
     * * A current pose is updated
     * Store the current pose and triggers control logic
     * @msg: incoming current pose
    *************************************************/
    void pose_callbacks(const tangerbot_msgs::msg::RobotPose::SharedPtr msg){
        current_pose.pose.position.x = msg->pose.pose.position.x;
        current_pose.pose.position.y = msg->pose.pose.position.y;
        current_pose.pose.orientation.z = msg->pose.pose.orientation.z;

        control(current_pose); 

    }
    /************************************************
     * * Person Pose Callbacks
     * * A new person pose is received
     * Updates the internal person_pose variable with the received position and orientation
     * @msg: incoming person pose
    *************************************************/
    void person_pose_callbacks(const tangerbot_msgs::msg::RobotPose::SharedPtr msg) {
        auto person_pose = geometry_msgs::msg::PoseStamped();
        person_pose.pose.position.x = msg->pose.pose.position.x;
        person_pose.pose.position.y = msg->pose.pose.position.y;
        person_pose.pose.orientation.z = msg->pose.pose.orientation.z;
        RCLCPP_INFO(this->get_logger(), "Received new person pose: x=%.2f, y=%.2f, theta=%.2f", 
                    msg->pose.pose.position.x, msg->pose.pose.position.y, msg->pose.pose.orientation.z);
    }     

    /************************************************
     * * Control  
     * Controls the robot's behavior based on its current motion status
     * @param current_pose The current position and orientation of the robot
    *************************************************/
    void control(const geometry_msgs::msg::PoseStamped& current_pose){
        geometry_msgs::msg::Twist twist_msg;
    
        if (motion_status ==tangerbot_msgs::msg::RobotState::FOLLOWING){
            twist_msg = handle_following(current_pose);
        } else if (motion_status == tangerbot_msgs::msg::RobotState::MOVING) {
            twist_msg = handle_moving(current_pose);
        } else if (motion_status == tangerbot_msgs::msg::RobotState::STOP) {
            twist_msg = handle_stop();
        } 
        // else if (motion_status == tangerbot_msgs::msg::RobotState::LOADING) {
        //     twist_msg = handle_loading(current_pose);
        // }
        cmd_vel_publisher->publish(twist_msg);
    }
    
    /************************************************
     * * Handle Following
     * @param current_pose The current position and orientation of the robot
     * @return The velocity command for the robot
    *************************************************/
    geometry_msgs::msg::Twist handle_following(const geometry_msgs::msg::PoseStamped& current_pose) {
        auto msg = tangerbot_msgs::msg::RobotState();
        msg.motion_status = tangerbot_msgs::msg::RobotState::FOLLOWING;
        geometry_msgs::msg::Twist twist_msg;
        //TODO 

        return twist_msg;
    }
    /************************************************
     * * Handle Moving
     * @param current_pose The current position and orientation of the robot
     * @return The velocity command for the robot
    *************************************************/
    geometry_msgs::msg::Twist handle_moving(const geometry_msgs::msg::PoseStamped& current_pose) {
        auto msg = tangerbot_msgs::msg::RobotState();
        msg.motion_status = tangerbot_msgs::msg::RobotState::MOVING;
        geometry_msgs::msg::Twist twist_msg;
        
        //TODO
        // For example, set linear velocity towards the goal pose
        twist_msg.linear.x = 0.5;  // Move forward at 0.5 m/s
        twist_msg.angular.z = 0.0; // No rotation
        return twist_msg;
    }
    /************************************************
     * * Handle Stop
     * @return The velocity command for the robot
    *************************************************/
    geometry_msgs::msg::Twist handle_stop() {
        auto msg = tangerbot_msgs::msg::RobotState();
        msg.motion_status = tangerbot_msgs::msg::RobotState::STOP;
        geometry_msgs::msg::Twist twist_msg;
        twist_msg.linear.x = 0.0;  // Stop moving
        twist_msg.angular.z = 0.0; // No rotation
        return twist_msg;
    }
    /************************************************
     * * Handle Loading
     * @param current_pose The current position and orientation of the robot
     * @return The velocity command for the robot
    *************************************************/
    // geometry_msgs::msg::Twist handle_loading(const geometry_msgs::msg::PoseStamped& current_pose){
    //     auto msg = tangerbot_msgs::msg::RobotState();
    //     msg.motion_status = tangerbot_msgs::msg::RobotState::LOADING;
    //     geometry_msgs::msg::Twist twist_msg;
        
    //     //TODO
    //     return current_pose;
    // }

    //TODO
    /***********************************************
     * * update_battery
     * It decreases the battery level based on the robot's motion status and recharges it when idle.
     * @param robotID The ID of the robot
     * @param currentBattery The current battery level
    ************************************************/
    // void TangerbotManager::update_battery(string robotID, float currentBattery) {
    //     auto msg = tangerbot_msgs::msg::RobotState();
    //     msg.robot_id = robotID;

    //     // current robot status
    //     msg.main_status = main_status;
    //     msg.motion_status = motion_status;
    
    //     // Decrease 0.1% per cycle (every 500ms)
    //     float consumption_rate = 0.05f;  // Default
    //     if (msg.motion_status == tangerbot_msgs::msg::RobotState::MOVING) consumption_rate = 0.1f;
    //     else if (msg.motion_status == tangerbot_msgs::msg::RobotState::LOADING) consumption_rate = 0.15f;
    //     currentBattery -= consumption_rate;
        
    //     // Battery can't be negative
    //     if (battery < 0.0f)
    //         battery = 0.0f;
        
    //     // Rechrage battery when idle
    //     if (msg.main_status == tangerbot_msgs::msg::RobotState::IDLE && battery < 100.0f) {
    //         battery += 0.2f;  // Charge while idle
    //         if (battery > 100.0f)
    //             battery = 100.0f;
    //     }

    //     msg.battery = battery;
    
    //     RCLCPP_INFO(this->get_logger(), "Publishing Battery: %.2f%%", battery);
    //     state_publisher->publish(msg);
    
    // }

    //TODO
    /************************************************
     * * State Callbacks
     * @description: This function is called every 500ms to update the robot's state.
    ************************************************/   
    void state_callbacks() {
        auto msg = tangerbot_msgs::msg::RobotState();
        msg.robot_id = robot_id;
        msg.main_status = main_status;
        msg.motion_status = motion_status;
        msg.battery = battery;

        // Simulate battery consumption
        //update_battery(robot_id, battery);
    }

    
};


int main(int argc , char **argv)
{
    rclcpp::init(argc, argv);
    auto pub = std::make_shared<TangerbotManager>();
    rclcpp::spin(pub);
    rclcpp::shutdown();
    return 0;
}


