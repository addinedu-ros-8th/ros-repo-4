// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tangerbot_msgs:srv/SetState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/srv/set_state.hpp"


#ifndef TANGERBOT_MSGS__SRV__DETAIL__SET_STATE__TRAITS_HPP_
#define TANGERBOT_MSGS__SRV__DETAIL__SET_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tangerbot_msgs/srv/detail/set_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tangerbot_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetState_Request & msg,
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetState_Request & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetState_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace tangerbot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tangerbot_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tangerbot_msgs::srv::SetState_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::srv::SetState_Request & msg)
{
  return tangerbot_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::srv::SetState_Request>()
{
  return "tangerbot_msgs::srv::SetState_Request";
}

template<>
inline const char * name<tangerbot_msgs::srv::SetState_Request>()
{
  return "tangerbot_msgs/srv/SetState_Request";
}

template<>
struct has_fixed_size<tangerbot_msgs::srv::SetState_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tangerbot_msgs::srv::SetState_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tangerbot_msgs::srv::SetState_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace tangerbot_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetState_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetState_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetState_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace tangerbot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tangerbot_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tangerbot_msgs::srv::SetState_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::srv::SetState_Response & msg)
{
  return tangerbot_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::srv::SetState_Response>()
{
  return "tangerbot_msgs::srv::SetState_Response";
}

template<>
inline const char * name<tangerbot_msgs::srv::SetState_Response>()
{
  return "tangerbot_msgs/srv/SetState_Response";
}

template<>
struct has_fixed_size<tangerbot_msgs::srv::SetState_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tangerbot_msgs::srv::SetState_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tangerbot_msgs::srv::SetState_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace tangerbot_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetState_Event & msg,
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
  const SetState_Event & msg,
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

inline std::string to_yaml(const SetState_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace tangerbot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use tangerbot_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tangerbot_msgs::srv::SetState_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::srv::SetState_Event & msg)
{
  return tangerbot_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::srv::SetState_Event>()
{
  return "tangerbot_msgs::srv::SetState_Event";
}

template<>
inline const char * name<tangerbot_msgs::srv::SetState_Event>()
{
  return "tangerbot_msgs/srv/SetState_Event";
}

template<>
struct has_fixed_size<tangerbot_msgs::srv::SetState_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tangerbot_msgs::srv::SetState_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<tangerbot_msgs::srv::SetState_Request>::value && has_bounded_size<tangerbot_msgs::srv::SetState_Response>::value> {};

template<>
struct is_message<tangerbot_msgs::srv::SetState_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tangerbot_msgs::srv::SetState>()
{
  return "tangerbot_msgs::srv::SetState";
}

template<>
inline const char * name<tangerbot_msgs::srv::SetState>()
{
  return "tangerbot_msgs/srv/SetState";
}

template<>
struct has_fixed_size<tangerbot_msgs::srv::SetState>
  : std::integral_constant<
    bool,
    has_fixed_size<tangerbot_msgs::srv::SetState_Request>::value &&
    has_fixed_size<tangerbot_msgs::srv::SetState_Response>::value
  >
{
};

template<>
struct has_bounded_size<tangerbot_msgs::srv::SetState>
  : std::integral_constant<
    bool,
    has_bounded_size<tangerbot_msgs::srv::SetState_Request>::value &&
    has_bounded_size<tangerbot_msgs::srv::SetState_Response>::value
  >
{
};

template<>
struct is_service<tangerbot_msgs::srv::SetState>
  : std::true_type
{
};

template<>
struct is_service_request<tangerbot_msgs::srv::SetState_Request>
  : std::true_type
{
};

template<>
struct is_service_response<tangerbot_msgs::srv::SetState_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TANGERBOT_MSGS__SRV__DETAIL__SET_STATE__TRAITS_HPP_
