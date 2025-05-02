#include <iostream>
#include <string>
#include <cstdint>
#include <chrono>
using std::string;

#include "rclcpp/rclcpp.hpp"
#include "tangerbot_msgs/msg/robot_state.hpp"
#include "tangerbot_msgs/msg/robot_pose.hpp"
using namespace std::chrono_literals;


class TangerbotManager : public rclcpp::Node
{
private:
    string robot_id;
    int main_status;
    int motion_status;
    float battery=100.0f;

    rclcpp::Publisher<tangerbot_msgs::msg::RobotState>::SharedPtr publisher;
    rclcpp::Subscription<tangerbot_msgs::msg::RobotPose>::SharedPtr subscriber;
    rclcpp::TimerBase::SharedPtr timer_;

public:
    TangerbotManager() : Node("tangerbot_manager")
    {
        /************************************************
         * * publisher list
         * * 1. Robot State (state, motion, battery)
        ************************************************/
        publisher = this->create_publisher<tangerbot_msgs::msg::RobotState>("robot_state", 10); 
        timer_ = this->create_wall_timer(500ms, std::bind(&TangerbotManager::state_callbacks, this));
        
        /************************************************
         * * subscriber list
         * * 1. Robot Pose
         * * 2. Person Pose
        ************************************************/
    }

    /************************************************
     * * Robot State (Working, Idle)
    ************************************************/
    void setStatus(int status)
    {
        main_status = status;
    }

    /***********************************************
     * * callbacks function
     * * 1. Robot State
     * * 2. Robot Pose
    ************************************************/
    void state_callbacks() {
        auto msg = tangerbot_msgs::msg::RobotState();
        msg.robot_id = robot_id;
        msg.main_status = tangerbot_msgs::msg::RobotState::IDLE;
        msg.motion_status = tangerbot_msgs::msg::RobotState::STOP;
        msg.battery = battery;

        /* EXAMPLE OF BATTERY SCENARIO */
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


