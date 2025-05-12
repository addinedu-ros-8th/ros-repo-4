// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tangerbot_msgs:msg/Gesture.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/msg/gesture.hpp"


#ifndef TANGERBOT_MSGS__MSG__DETAIL__GESTURE__BUILDER_HPP_
#define TANGERBOT_MSGS__MSG__DETAIL__GESTURE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tangerbot_msgs/msg/detail/gesture__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tangerbot_msgs
{

namespace msg
{

namespace builder
{

class Init_Gesture_point
{
public:
  explicit Init_Gesture_point(::tangerbot_msgs::msg::Gesture & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::msg::Gesture point(::tangerbot_msgs::msg::Gesture::_point_type arg)
  {
    msg_.point = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::msg::Gesture msg_;
};

class Init_Gesture_robot_id
{
public:
  Init_Gesture_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Gesture_point robot_id(::tangerbot_msgs::msg::Gesture::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_Gesture_point(msg_);
  }

private:
  ::tangerbot_msgs::msg::Gesture msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::msg::Gesture>()
{
  return tangerbot_msgs::msg::builder::Init_Gesture_robot_id();
}

}  // namespace tangerbot_msgs

#endif  // TANGERBOT_MSGS__MSG__DETAIL__GESTURE__BUILDER_HPP_
