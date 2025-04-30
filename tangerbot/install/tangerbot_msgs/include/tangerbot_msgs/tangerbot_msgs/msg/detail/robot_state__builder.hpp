// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tangerbot_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/msg/robot_state.hpp"


#ifndef TANGERBOT_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
#define TANGERBOT_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tangerbot_msgs/msg/detail/robot_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tangerbot_msgs
{

namespace msg
{

namespace builder
{

class Init_RobotState_battery
{
public:
  explicit Init_RobotState_battery(::tangerbot_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::msg::RobotState battery(::tangerbot_msgs::msg::RobotState::_battery_type arg)
  {
    msg_.battery = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::msg::RobotState msg_;
};

class Init_RobotState_motion_status
{
public:
  explicit Init_RobotState_motion_status(::tangerbot_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_battery motion_status(::tangerbot_msgs::msg::RobotState::_motion_status_type arg)
  {
    msg_.motion_status = std::move(arg);
    return Init_RobotState_battery(msg_);
  }

private:
  ::tangerbot_msgs::msg::RobotState msg_;
};

class Init_RobotState_main_status
{
public:
  explicit Init_RobotState_main_status(::tangerbot_msgs::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_motion_status main_status(::tangerbot_msgs::msg::RobotState::_main_status_type arg)
  {
    msg_.main_status = std::move(arg);
    return Init_RobotState_motion_status(msg_);
  }

private:
  ::tangerbot_msgs::msg::RobotState msg_;
};

class Init_RobotState_robot_id
{
public:
  Init_RobotState_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotState_main_status robot_id(::tangerbot_msgs::msg::RobotState::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_RobotState_main_status(msg_);
  }

private:
  ::tangerbot_msgs::msg::RobotState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::msg::RobotState>()
{
  return tangerbot_msgs::msg::builder::Init_RobotState_robot_id();
}

}  // namespace tangerbot_msgs

#endif  // TANGERBOT_MSGS__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
