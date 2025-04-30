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
    float battery;
    rclcpp::Publisher<tangerbot_msgs::msg::RobotState>::SharedPtr publisher;
    rclcpp::Subscription<tangerbot_msgs::msg::RobotPose>::SharedPtr subscriber;
    rclcpp::TimerBase::SharedPtr timer_;

public:
    /*
     * Constructor
    */
    TangerbotManager() : Node("tangerbot_manager")
    {
        /*
         * Create topic for publishing robot state
        */
        publisher = this->create_publisher<tangerbot_msgs::msg::RobotState>("robot_state", 10); 
        tangerbot_msgs::msg::RobotState msgState;
        msgState.robot_id = "RB1";
        timer_ = this->create_wall_timer(500ms, std::bind(&TangerbotManager::state_callbacks, this));
        publisher->publish(msgState);

        // subscriber = this->create_subscription<tangerbot_msgs::msg::RobotPose>("robot_pose", 10,
        //     std::bind(&TangerbotManager::pose_callbacks, this, std::placeholders::_1));
        

    }

    /*
     * Robot State (Working, Idle)
    */
    void setStatus(int status)
    {
        main_status = status;
    }

    /*
     * Robot State Callback
    */
    void state_callbacks() {
        auto msg = tangerbot_msgs::msg::RobotState();
        msg.main_status = tangerbot_msgs::msg::RobotState::IDLE;
    
        publisher->publish(msg);
    }

    /**
     * * Robot Pose Callback
    */
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