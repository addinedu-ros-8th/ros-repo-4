// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tangerbot_msgs:msg/RobotPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/msg/robot_pose.hpp"


#ifndef TANGERBOT_MSGS__MSG__DETAIL__ROBOT_POSE__BUILDER_HPP_
#define TANGERBOT_MSGS__MSG__DETAIL__ROBOT_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tangerbot_msgs/msg/detail/robot_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tangerbot_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotPose_pose
{
public:
  explicit Init_RobotPose_pose(::tangerbot_msgs::msg::RobotPose & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::msg::RobotPose pose(::tangerbot_msgs::msg::RobotPose::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::msg::RobotPose msg_;
};

class Init_RobotPose_robot_id
{
public:
  Init_RobotPose_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotPose_pose robot_id(::tangerbot_msgs::msg::RobotPose::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_RobotPose_pose(msg_);
  }

private:
  ::tangerbot_msgs::msg::RobotPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::msg::RobotPose>()
{
  return tangerbot_msgs::msg::builder::Init_RobotPose_robot_id();
}

}  // namespace tangerbot_msgs

#endif  // TANGERBOT_MSGS__MSG__DETAIL__ROBOT_POSE__BUILDER_HPP_
