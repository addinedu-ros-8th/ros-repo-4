// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tangerbot_msgs:msg/LocalMap.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/msg/local_map.hpp"


#ifndef TANGERBOT_MSGS__MSG__DETAIL__LOCAL_MAP__TRAITS_HPP_
#define TANGERBOT_MSGS__MSG__DETAIL__LOCAL_MAP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tangerbot_msgs/msg/detail/local_map__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace tangerbot_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const LocalMap & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << ", ";
  }

  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: resolution
  {
    out << "resolution: ";
    rosidl_generator_traits::value_to_yaml(msg.resolution, out);
    out << ", ";
  }

  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << ", ";
  }

  // member: height
  {
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << ", ";
  }

  // member: origin_x
  {
    out << "origin_x: ";
    rosidl_generator_traits::value_to_yaml(msg.origin_x, out);
    out << ", ";
  }

  // member: origin_y
  {
    out << "origin_y: ";
    rosidl_generator_traits::value_to_yaml(msg.origin_y, out);
    out << ", ";
  }

  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LocalMap & msg,
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

  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: resolution
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "resolution: ";
    rosidl_generator_traits::value_to_yaml(msg.resolution, out);
    out << "\n";
  }

  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << "\n";
  }

  // member: height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << "\n";
  }

  // member: origin_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "origin_x: ";
    rosidl_generator_traits::value_to_yaml(msg.origin_x, out);
    out << "\n";
  }

  // member: origin_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "origin_y: ";
    rosidl_generator_traits::value_to_yaml(msg.origin_y, out);
    out << "\n";
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LocalMap & msg, bool use_flow_style = false)
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
  const tangerbot_msgs::msg::LocalMap & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::msg::LocalMap & msg)
{
  return tangerbot_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::msg::LocalMap>()
{
  return "tangerbot_msgs::msg::LocalMap";
}

template<>
inline const char * name<tangerbot_msgs::msg::LocalMap>()
{
  return "tangerbot_msgs/msg/LocalMap";
}

template<>
struct has_fixed_size<tangerbot_msgs::msg::LocalMap>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tangerbot_msgs::msg::LocalMap>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tangerbot_msgs::msg::LocalMap>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TANGERBOT_MSGS__MSG__DETAIL__LOCAL_MAP__TRAITS_HPP_
