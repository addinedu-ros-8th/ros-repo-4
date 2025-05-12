#include "rclcpp/rclcpp.hpp"
#include "tangerbot_msgs/msg/person_pose.hpp"

class Bridge : public rclcpp::Node {
    using PersonPose = tangerbot_msgs::msg::PersonPose;
public:
    Bridge();
private:
    rclcpp::Subscription<PersonPose>::SharedPtr person_pose_subscriber;
    rclcpp::Publisher<PersonPose>::SharedPtr person_pose_publisher;
    rclcpp::TimerBase::SharedPtr person_pose_timer;

    void person_pose_callback(const PersonPose::SharedPtr msg);
    void person_pose_timer_callback();
};