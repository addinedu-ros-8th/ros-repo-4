#ifndef TANGERBOT_MANAGER_H
#define TANGERBOT_MANAGER_H

#include "rclcpp/rclcpp.hpp"
#include "tangerbot_msgs/msg/robot_state.hpp"
#include "tangerbot_msgs/msg/robot_pose.hpp"
#include "tangerbot_msgs/srv/set_state.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
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

using namespace std;

class TangerbotManager : public rclcpp::Node {
private:
    string robot_id;
    int main_status;
    int motion_status;
    float battery;

    rclcpp::Publisher<tangerbot_msgs::msg::RobotState>::SharedPtr state_publisher;

    rclcpp::Subscription<tangerbot_msgs::msg::RobotPose>::SharedPtr person_pose_subscriber;

    rclcpp::Service<tangerbot_msgs::srv::SetState>::SharedPtr set_state_server;

    rclcpp::TimerBase::SharedPtr timer_;

    void set_state(const std::shared_ptr<tangerbot_msgs::srv::SetState::Request> request,
    std::shared_ptr<tangerbot_msgs::srv::SetState::Response> response);
    void person_pose_callbacks(const tangerbot_msgs::msg::RobotPose::SharedPtr msg);
    void state_callbacks();
    void update_battery();

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