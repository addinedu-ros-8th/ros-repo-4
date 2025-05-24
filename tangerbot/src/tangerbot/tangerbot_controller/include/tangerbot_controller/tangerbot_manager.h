#ifndef TANGERBOT_MANAGER_H
#define TANGERBOT_MANAGER_H

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "tangerbot_msgs/msg/robot_state.hpp"
#include "tangerbot_msgs/msg/robot_pose.hpp"
#include "tangerbot_msgs/srv/set_state.hpp"
#include "tangerbot_msgs/msg/detected_marker.hpp"
#include "tangerbot_msgs/action/parking.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "geometry_msgs/msg/twist.hpp"

#include <string>
#include <memory>
#include <fstream>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <vector>
#include <cstdint> 
#include <chrono>

#include "tangerbot_controller/pid.h"

using namespace std;

using SetState = tangerbot_msgs::srv::SetState;
using Parking = tangerbot_msgs::action::Parking;
using GoalHandlerParking = rclcpp_action::ServerGoalHandle<Parking>;
using DetectedMarker = tangerbot_msgs::msg::DetectedMarker;
using Twist = geometry_msgs::msg::Twist;

class TangerbotManager : public rclcpp::Node {
private:
    void set_state(const std::shared_ptr<tangerbot_msgs::srv::SetState::Request> request,
        std::shared_ptr<tangerbot_msgs::srv::SetState::Response> response);
    void update_battery();


    void person_pose_callbacks(const tangerbot_msgs::msg::RobotPose::SharedPtr msg);
    void detected_marker_callback(const DetectedMarker::SharedPtr msg);
    void state_callbacks();
    void update_workload();
    

    rclcpp_action::GoalResponse parking_handle_goal(
        const rclcpp_action::GoalUUID &uuid,
        std::shared_ptr<const Parking::Goal> goal
    );
    rclcpp_action::CancelResponse parking_handle_cancel(const std::shared_ptr<GoalHandlerParking> goal_handle);
    void parking_handle_accepted(const std::shared_ptr<GoalHandlerParking> goal_handle);
    void parking_execute(const std::shared_ptr<GoalHandlerParking> goal_handle);


    int find_index(const std::vector<int>& vec, int value);

    void publish_robot_state();


    string robot_id = "robot1";
    string ns;
    int main_status;
    int motion_status;
    float battery;
    int workload = 0;


    DetectedMarker detected_marker_msg;
    std::mutex marker_mutex;
    PID pid_linear, pid_angular;


    rclcpp::Publisher<tangerbot_msgs::msg::RobotState>::SharedPtr state_publisher;
    rclcpp::Publisher<Twist>::SharedPtr cmd_vel_pub;
    rclcpp::Subscription<tangerbot_msgs::msg::RobotPose>::SharedPtr person_pose_subscriber;
    rclcpp::Subscription<DetectedMarker>::SharedPtr detected_marker_sub;

    rclcpp::Service<SetState>::SharedPtr set_state_server;
    
    rclcpp_action::Server<Parking>::SharedPtr parking_server;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::TimerBase::SharedPtr workload_timer;
    
    
public:
    TangerbotManager();
};

class Battery {
public:
    Battery(int min_value = 2396, int max_value = 3215) : min_value_(min_value), max_value_(max_value) {
        // I2C bus 열기
        if ((file_ = open(bus_, O_RDWR)) < 0) {
            std::cerr << "I2C bus open failed\n";
            exit(1);
        }
        // ADS1115 주소 설정
        int addr = 0x48; // 기본 주소
        if (ioctl(file_, I2C_SLAVE, addr) < 0) {
            std::cerr << "Failed to connect to the device\n";
            exit(1);
        }
    }
    ~Battery() {
        close(file_);
    }
    float calculate_percentage(int value);
    float get_battery(int sample_count = 10);
    
private:
    int read_adc_value();

    int file_;
    const char *bus_ = "/dev/i2c-1";
    int min_value_, max_value_;
};

#endif 