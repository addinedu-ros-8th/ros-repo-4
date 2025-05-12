// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tangerbot_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/msg/robot_state.hpp"


#ifndef TANGERBOT_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_
#define TANGERBOT_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tangerbot_msgs/msg/detail/robot_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tangerbot_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotState & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << ", ";
  }

  // member: main_status
  {
    out << "main_status: ";
    rosidl_generator_traits::value_to_yaml(msg.main_status, out);
    out << ", ";
  }

  // member: motion_status
  {
    out << "motion_status: ";
    rosidl_generator_traits::value_to_yaml(msg.motion_status, out);
    out << ", ";
  }

  // member: battery
  {
    out << "battery: ";
    rosidl_generator_traits::value_to_yaml(msg.battery, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << "\n";
  }

  // member: main_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "main_status: ";
    rosidl_generator_traits::value_to_yaml(msg.main_status, out);
    out << "\n";
  }

  // member: motion_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motion_status: ";
    rosidl_generator_traits::value_to_yaml(msg.motion_status, out);
    out << "\n";
  }

  // member: battery
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery: ";
    rosidl_generator_traits::value_to_yaml(msg.battery, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace tangerbot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tangerbot_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tangerbot_msgs::msg::RobotState & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::msg::RobotState & msg)
{
  return tangerbot_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::msg::RobotState>()
{
  return "tangerbot_msgs::msg::RobotState";
}

template<>
inline const char * name<tangerbot_msgs::msg::RobotState>()
{
  return "tangerbot_msgs/msg/RobotState";
}

template<>
struct has_fixed_size<tangerbot_msgs::msg::RobotState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tangerbot_msgs::msg::RobotState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tangerbot_msgs::msg::RobotState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TANGERBOT_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_
