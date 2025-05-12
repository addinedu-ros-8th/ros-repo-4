// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tangerbot_msgs:action/NavigateToPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/action/navigate_to_pose.hpp"


#ifndef TANGERBOT_MSGS__ACTION__DETAIL__NAVIGATE_TO_POSE__TRAITS_HPP_
#define TANGERBOT_MSGS__ACTION__DETAIL__NAVIGATE_TO_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tangerbot_msgs/action/detail/navigate_to_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace tangerbot_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const NavigateToPose_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavigateToPose_Goal & msg,
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

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigateToPose_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace tangerbot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tangerbot_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tangerbot_msgs::action::NavigateToPose_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::action::NavigateToPose_Goal & msg)
{
  return tangerbot_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::action::NavigateToPose_Goal>()
{
  return "tangerbot_msgs::action::NavigateToPose_Goal";
}

template<>
inline const char * name<tangerbot_msgs::action::NavigateToPose_Goal>()
{
  return "tangerbot_msgs/action/NavigateToPose_Goal";
}

template<>
struct has_fixed_size<tangerbot_msgs::action::NavigateToPose_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tangerbot_msgs::action::NavigateToPose_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tangerbot_msgs::action::NavigateToPose_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace tangerbot_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const NavigateToPose_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: error_code
  {
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
    out << ", ";
  }

  // member: error_msg
  {
    out << "error_msg: ";
    rosidl_generator_traits::value_to_yaml(msg.error_msg, out);
    out << ", ";
  }

  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavigateToPose_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: error_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
    out << "\n";
  }

  // member: error_msg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_msg: ";
    rosidl_generator_traits::value_to_yaml(msg.error_msg, out);
    out << "\n";
  }

  // member: robot_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigateToPose_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace tangerbot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tangerbot_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tangerbot_msgs::action::NavigateToPose_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::action::NavigateToPose_Result & msg)
{
  return tangerbot_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::action::NavigateToPose_Result>()
{
  return "tangerbot_msgs::action::NavigateToPose_Result";
}

template<>
inline const char * name<tangerbot_msgs::action::NavigateToPose_Result>()
{
  return "tangerbot_msgs/action/NavigateToPose_Result";
}

template<>
struct has_fixed_size<tangerbot_msgs::action::NavigateToPose_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tangerbot_msgs::action::NavigateToPose_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tangerbot_msgs::action::NavigateToPose_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace tangerbot_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const NavigateToPose_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << ", ";
  }

  // member: distance_remaining
  {
    out << "distance_remaining: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_remaining, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavigateToPose_Feedback & msg,
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

  // member: distance_remaining
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance_remaining: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_remaining, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigateToPose_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace tangerbot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tangerbot_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tangerbot_msgs::action::NavigateToPose_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::action::NavigateToPose_Feedback & msg)
{
  return tangerbot_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::action::NavigateToPose_Feedback>()
{
  return "tangerbot_msgs::action::NavigateToPose_Feedback";
}

template<>
inline const char * name<tangerbot_msgs::action::NavigateToPose_Feedback>()
{
  return "tangerbot_msgs/action/NavigateToPose_Feedback";
}

template<>
struct has_fixed_size<tangerbot_msgs::action::NavigateToPose_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tangerbot_msgs::action::NavigateToPose_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tangerbot_msgs::action::NavigateToPose_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "tangerbot_msgs/action/detail/navigate_to_pose__traits.hpp"

namespace tangerbot_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const NavigateToPose_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavigateToPose_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigateToPose_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace tangerbot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tangerbot_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tangerbot_msgs::action::NavigateToPose_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::action::NavigateToPose_SendGoal_Request & msg)
{
  return tangerbot_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::action::NavigateToPose_SendGoal_Request>()
{
  return "tangerbot_msgs::action::NavigateToPose_SendGoal_Request";
}

template<>
inline const char * name<tangerbot_msgs::action::NavigateToPose_SendGoal_Request>()
{
  return "tangerbot_msgs/action/NavigateToPose_SendGoal_Request";
}

template<>
struct has_fixed_size<tangerbot_msgs::action::NavigateToPose_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<tangerbot_msgs::action::NavigateToPose_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<tangerbot_msgs::action::NavigateToPose_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<tangerbot_msgs::action::NavigateToPose_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<tangerbot_msgs::action::NavigateToPose_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace tangerbot_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const NavigateToPose_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavigateToPose_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigateToPose_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace tangerbot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tangerbot_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tangerbot_msgs::action::NavigateToPose_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::action::NavigateToPose_SendGoal_Response & msg)
{
  return tangerbot_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::action::NavigateToPose_SendGoal_Response>()
{
  return "tangerbot_msgs::action::NavigateToPose_SendGoal_Response";
}

template<>
inline const char * name<tangerbot_msgs::action::NavigateToPose_SendGoal_Response>()
{
  return "tangerbot_msgs/action/NavigateToPose_SendGoal_Response";
}

template<>
struct has_fixed_size<tangerbot_msgs::action::NavigateToPose_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<tangerbot_msgs::action::NavigateToPose_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<tangerbot_msgs::action::NavigateToPose_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace tangerbot_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const NavigateToPose_SendGoal_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
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
  const NavigateToPose_SendGoal_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigateToPose_SendGoal_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace tangerbot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tangerbot_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tangerbot_msgs::action::NavigateToPose_SendGoal_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::action::NavigateToPose_SendGoal_Event & msg)
{
  return tangerbot_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::action::NavigateToPose_SendGoal_Event>()
{
  return "tangerbot_msgs::action::NavigateToPose_SendGoal_Event";
}

template<>
inline const char * name<tangerbot_msgs::action::NavigateToPose_SendGoal_Event>()
{
  return "tangerbot_msgs/action/NavigateToPose_SendGoal_Event";
}

template<>
struct has_fixed_size<tangerbot_msgs::action::NavigateToPose_SendGoal_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tangerbot_msgs::action::NavigateToPose_SendGoal_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<tangerbot_msgs::action::NavigateToPose_SendGoal_Request>::value && has_bounded_size<tangerbot_msgs::action::NavigateToPose_SendGoal_Response>::value> {};

template<>
struct is_message<tangerbot_msgs::action::NavigateToPose_SendGoal_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tangerbot_msgs::action::NavigateToPose_SendGoal>()
{
  return "tangerbot_msgs::action::NavigateToPose_SendGoal";
}

template<>
inline const char * name<tangerbot_msgs::action::NavigateToPose_SendGoal>()
{
  return "tangerbot_msgs/action/NavigateToPose_SendGoal";
}

template<>
struct has_fixed_size<tangerbot_msgs::action::NavigateToPose_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<tangerbot_msgs::action::NavigateToPose_SendGoal_Request>::value &&
    has_fixed_size<tangerbot_msgs::action::NavigateToPose_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<tangerbot_msgs::action::NavigateToPose_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<tangerbot_msgs::action::NavigateToPose_SendGoal_Request>::value &&
    has_bounded_size<tangerbot_msgs::action::NavigateToPose_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<tangerbot_msgs::action::NavigateToPose_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<tangerbot_msgs::action::NavigateToPose_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<tangerbot_msgs::action::NavigateToPose_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace tangerbot_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const NavigateToPose_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavigateToPose_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigateToPose_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace tangerbot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tangerbot_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tangerbot_msgs::action::NavigateToPose_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::action::NavigateToPose_GetResult_Request & msg)
{
  return tangerbot_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::action::NavigateToPose_GetResult_Request>()
{
  return "tangerbot_msgs::action::NavigateToPose_GetResult_Request";
}

template<>
inline const char * name<tangerbot_msgs::action::NavigateToPose_GetResult_Request>()
{
  return "tangerbot_msgs/action/NavigateToPose_GetResult_Request";
}

template<>
struct has_fixed_size<tangerbot_msgs::action::NavigateToPose_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<tangerbot_msgs::action::NavigateToPose_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<tangerbot_msgs::action::NavigateToPose_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "tangerbot_msgs/action/detail/navigate_to_pose__traits.hpp"

namespace tangerbot_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const NavigateToPose_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavigateToPose_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigateToPose_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace tangerbot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tangerbot_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tangerbot_msgs::action::NavigateToPose_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::action::NavigateToPose_GetResult_Response & msg)
{
  return tangerbot_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::action::NavigateToPose_GetResult_Response>()
{
  return "tangerbot_msgs::action::NavigateToPose_GetResult_Response";
}

template<>
inline const char * name<tangerbot_msgs::action::NavigateToPose_GetResult_Response>()
{
  return "tangerbot_msgs/action/NavigateToPose_GetResult_Response";
}

template<>
struct has_fixed_size<tangerbot_msgs::action::NavigateToPose_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<tangerbot_msgs::action::NavigateToPose_Result>::value> {};

template<>
struct has_bounded_size<tangerbot_msgs::action::NavigateToPose_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<tangerbot_msgs::action::NavigateToPose_Result>::value> {};

template<>
struct is_message<tangerbot_msgs::action::NavigateToPose_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace tangerbot_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const NavigateToPose_GetResult_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
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
  const NavigateToPose_GetResult_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigateToPose_GetResult_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace tangerbot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tangerbot_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tangerbot_msgs::action::NavigateToPose_GetResult_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::action::NavigateToPose_GetResult_Event & msg)
{
  return tangerbot_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::action::NavigateToPose_GetResult_Event>()
{
  return "tangerbot_msgs::action::NavigateToPose_GetResult_Event";
}

template<>
inline const char * name<tangerbot_msgs::action::NavigateToPose_GetResult_Event>()
{
  return "tangerbot_msgs/action/NavigateToPose_GetResult_Event";
}

template<>
struct has_fixed_size<tangerbot_msgs::action::NavigateToPose_GetResult_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tangerbot_msgs::action::NavigateToPose_GetResult_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<tangerbot_msgs::action::NavigateToPose_GetResult_Request>::value && has_bounded_size<tangerbot_msgs::action::NavigateToPose_GetResult_Response>::value> {};

template<>
struct is_message<tangerbot_msgs::action::NavigateToPose_GetResult_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tangerbot_msgs::action::NavigateToPose_GetResult>()
{
  return "tangerbot_msgs::action::NavigateToPose_GetResult";
}

template<>
inline const char * name<tangerbot_msgs::action::NavigateToPose_GetResult>()
{
  return "tangerbot_msgs/action/NavigateToPose_GetResult";
}

template<>
struct has_fixed_size<tangerbot_msgs::action::NavigateToPose_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<tangerbot_msgs::action::NavigateToPose_GetResult_Request>::value &&
    has_fixed_size<tangerbot_msgs::action::NavigateToPose_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<tangerbot_msgs::action::NavigateToPose_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<tangerbot_msgs::action::NavigateToPose_GetResult_Request>::value &&
    has_bounded_size<tangerbot_msgs::action::NavigateToPose_GetResult_Response>::value
  >
{
};

template<>
struct is_service<tangerbot_msgs::action::NavigateToPose_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<tangerbot_msgs::action::NavigateToPose_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<tangerbot_msgs::action::NavigateToPose_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "tangerbot_msgs/action/detail/navigate_to_pose__traits.hpp"

namespace tangerbot_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const NavigateToPose_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavigateToPose_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavigateToPose_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace tangerbot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tangerbot_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tangerbot_msgs::action::NavigateToPose_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::action::NavigateToPose_FeedbackMessage & msg)
{
  return tangerbot_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::action::NavigateToPose_FeedbackMessage>()
{
  return "tangerbot_msgs::action::NavigateToPose_FeedbackMessage";
}

template<>
inline const char * name<tangerbot_msgs::action::NavigateToPose_FeedbackMessage>()
{
  return "tangerbot_msgs/action/NavigateToPose_FeedbackMessage";
}

template<>
struct has_fixed_size<tangerbot_msgs::action::NavigateToPose_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<tangerbot_msgs::action::NavigateToPose_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<tangerbot_msgs::action::NavigateToPose_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<tangerbot_msgs::action::NavigateToPose_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<tangerbot_msgs::action::NavigateToPose_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<tangerbot_msgs::action::NavigateToPose>
  : std::true_type
{
};

template<>
struct is_action_goal<tangerbot_msgs::action::NavigateToPose_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<tangerbot_msgs::action::NavigateToPose_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<tangerbot_msgs::action::NavigateToPose_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // TANGERBOT_MSGS__ACTION__DETAIL__NAVIGATE_TO_POSE__TRAITS_HPP_
