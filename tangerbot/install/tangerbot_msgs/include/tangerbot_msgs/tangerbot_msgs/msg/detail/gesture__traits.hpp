// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tangerbot_msgs:msg/Gesture.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/msg/gesture.hpp"


#ifndef TANGERBOT_MSGS__MSG__DETAIL__GESTURE__TRAITS_HPP_
#define TANGERBOT_MSGS__MSG__DETAIL__GESTURE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tangerbot_msgs/msg/detail/gesture__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'point'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace tangerbot_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Gesture & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << ", ";
  }

  // member: point
  {
    out << "point: ";
    to_flow_style_yaml(msg.point, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Gesture & msg,
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

  // member: point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "point:\n";
    to_block_style_yaml(msg.point, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Gesture & msg, bool use_flow_style = false)
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
  const tangerbot_msgs::msg::Gesture & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::msg::Gesture & msg)
{
  return tangerbot_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::msg::Gesture>()
{
  return "tangerbot_msgs::msg::Gesture";
}

template<>
inline const char * name<tangerbot_msgs::msg::Gesture>()
{
  return "tangerbot_msgs/msg/Gesture";
}

template<>
struct has_fixed_size<tangerbot_msgs::msg::Gesture>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tangerbot_msgs::msg::Gesture>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tangerbot_msgs::msg::Gesture>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TANGERBOT_MSGS__MSG__DETAIL__GESTURE__TRAITS_HPP_
