#include <iostream>
#include <string>
#include <cstdint>
#include <chrono>
using std::string;

#include "rclcpp/rclcpp.hpp"
#include "tangerbot_msgs/msg/robot_state.hpp"
using namespace std::chrono_literals;
class TangerbotManager : public rclcpp::Node
{
private:
    string robot_id;
    int main_status;
    int motion_status;
    float battery;
    rclcpp::Publisher<tangerbot_msgs::msg::RobotState>::SharedPtr publisher;
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
        timer_ = this->create_wall_timer(500ms, std::bind(&TangerbotManager::timer_callback, this));

        tangerbot_msgs::msg::RobotState msg;
        msg.robot_id = "RB1";
        publisher->publish(msg);

    }

    /*
     * Robot Status (Working, Idle)
    */
    void setStatus(int status)
    {
        main_status = status;
    }

    /*
     *Timer Callback
    */
    void timer_callback() {
        auto msg = tangerbot_msgs::msg::RobotState();
        msg.main_status = tangerbot_msgs::msg::RobotState::IDLE;
    
        publisher->publish(msg);
    }
    
};


int main(int argc , char **argv)
{
    // printf("Tangerbot Package, TangerbotManager Node is Starting!\n");

    // TangerbotManager bot("RB1"); // Create a robot with ID 42
    // bot.printStatus();        // Should say inactive

    // bot.setStatus(1);         // Activate robot
    // bot.printStatus();        // Should say active

    // return 0;

    rclcpp::init(argc, argv);
    auto pub = std::make_shared<TangerbotManager>();
    rclcpp::spin(pub);
    rclcpp::shutdown();
    return 0;
}