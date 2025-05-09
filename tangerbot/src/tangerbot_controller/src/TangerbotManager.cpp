#include <iostream>
#include <string>
#include <cstdint>
#include <chrono>
using std::string;

#include "rclcpp/rclcpp.hpp"
#include "tangerbot_msgs/msg/robot_state.hpp"
#include "tangerbot_msgs/msg/robot_pose.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
using namespace std::chrono_literals;


class TangerbotManager : public rclcpp::Node
{
private:
    string robot_id;
    int main_status;
    int motion_status;
    float battery=100.0f;

    rclcpp::Publisher<tangerbot_msgs::msg::RobotState>::SharedPtr state_publisher;
    rclcpp::Subscription<tangerbot_msgs::msg::RobotPose>::SharedPtr subscriber;
    rclcpp::TimerBase::SharedPtr timer_;
    geometry_msgs::msg::PoseStamped current_pose;
    geometry_msgs::msg::PoseStamped goal_pose;


public:
    /* CONSTRUCTOR */
    TangerbotManager() : Node("tangerbot_manager")
    {
        /************************************************
         * * initialization
        ************************************************/
       `this->main_status = tangerbot_msgs::msg::RobotState::IDLE;
        this->goal_pose = None;

        /************************************************
         * * publisher list
         * * 1. Robot State (state, motion, battery)
        ************************************************/
        state_publisher = this->create_publisher<tangerbot_msgs::msg::RobotState>("robot_state", 10); 
        cmd_vel_publisher = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
        timer_ = this->create_wall_timer(500ms, std::bind(&TangerbotManager::state_callbacks, this));
        
        /************************************************
         * * subscriber list
         * * 1. Robot Pose
         * * 2. Goal Pose
         * * 3. Person Pose
        ************************************************/
        pose_subscriber = this->create_subscription<tangerbot_msgs::msg::RobotPose>(
            "robot_pose", 10, std::bind(&TangerbotManager::pose_callbacks, this, std::placeholders::_1));
        goal_pose_subscriber = this->create_subscription<tangerbot_msgs::msg::RobotPose>(
            "goal_pose", 10, std::bind(&TangerbotManager::goal_pose_callback, this, std::placeholders::_1));
        person_pose_subscriber = this->create_subscription<tangerbot_msgs::msg::RobotPose>(
            "person_pose", 10, std::bind(&TangerbotManager::person_pose_callback, this, std::placeholders::_1));
        

    }

    void set_state(int state){
        msg = tangerbot_msgs::msg::RobotState();
        msg.robot_id = robot_id;
        msg.main_status = state;
        
        state_publisher->publish(msg);
    }



    /***********************************************
     * * callbacks function
     * * 1. void state_callbacks() //Robot State
     * * 2. void pose_callbacks() //Robot Pose
    ************************************************/
    void state_callbacks() {
        auto msg = tangerbot_msgs::msg::RobotState();
        msg.robot_id = robot_id;
        msg.main_status = tangerbot_msgs::msg::RobotState::IDLE;
        msg.motion_status = tangerbot_msgs::msg::RobotState::STOP;
        msg.battery = battery;

        /* ASSUMPTION OF BATTERY SCENARIO */
        msg.main_status = tangerbot_msgs::msg::RobotState::WORKING;  
        msg.motion_status = tangerbot_msgs::msg::RobotState::MOVING;
    
        // Decrease 0.1% per cycle (every 500ms)
        float consumption_rate = 0.05f;  // Default
        if (msg.motion_status == tangerbot_msgs::msg::RobotState::MOVING) consumption_rate = 0.1f;
        else if (msg.motion_status == tangerbot_msgs::msg::RobotState::LOADING) consumption_rate = 0.15f;
        battery -= consumption_rate;
        if (battery < 0.0f)
            battery = 0.0f;
        
        // Rechrage battery when idle
        if (msg.main_status == tangerbot_msgs::msg::RobotState::IDLE && battery < 100.0f) {
            battery += 0.2f;  // Charge while idle
            if (battery > 100.0f)
                battery = 100.0f;
        }

        msg.battery = battery;
    
        RCLCPP_INFO(this->get_logger(), "Publishing Battery: %.2f%%", battery);
        publisher->publish(msg);
    
    }

    // void pose_callbacks(const tangerbot_msgs::msg::RobotPose::SharedPtr msg)
    // {
    //     rclcpp_info(this->get_logger(), "Received pose: x=%.2f, y=%.2f", msg->x, msg->y);
    // }
    
};


int main(int argc , char **argv)
{
    rclcpp::init(argc, argv);
    auto pub = std::make_shared<TangerbotManager>();
    rclcpp::spin(pub);
    rclcpp::shutdown();
    return 0;
}


