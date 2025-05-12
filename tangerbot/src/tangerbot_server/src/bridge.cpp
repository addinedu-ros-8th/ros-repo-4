#include "rclcpp/rclcpp.hpp"
#include "tangerbot_msgs/msg/person_pose.hpp"
#include "tangerbot_server/bridge.h"
#include <cstring>

using PersonPose = tangerbot_msgs::msg::PersonPose;

Bridge::Bridge() : Node("bridge") {
    using namespace std::placeholders;
    using namespace std::chrono_literals;
    person_pose_subscriber = this->create_subscription<PersonPose>(
        "vision/person_pose", 10, std::bind(&Bridge::person_pose_callback, this, _1)
    );
    person_pose_publisher = this->create_publisher<PersonPose>(
        "main/person_pose", 10
    );
    person_pose_timer = this->create_wall_timer(500ms, std::bind(&Bridge::person_pose_timer_callback, this));
}

void Bridge::person_pose_callback(const PersonPose::SharedPtr msg) {
    RCLCPP_INFO(this->get_logger(), "Robot ID: %s", msg->robot_id.c_str());
}

void Bridge::person_pose_timer_callback() {
    auto msg = PersonPose();
    msg.robot_id = "robot1";
    person_pose_publisher->publish(msg);
}

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Bridge>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}