// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tangerbot_msgs:srv/Speak.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/srv/speak.hpp"


#ifndef TANGERBOT_MSGS__SRV__DETAIL__SPEAK__TRAITS_HPP_
#define TANGERBOT_MSGS__SRV__DETAIL__SPEAK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tangerbot_msgs/srv/detail/speak__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'data'
#include "std_msgs/msg/detail/byte_multi_array__traits.hpp"

namespace tangerbot_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Speak_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << ", ";
  }

  // member: data
  {
    out << "data: ";
    to_flow_style_yaml(msg.data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Speak_Request & msg,
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

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data:\n";
    to_block_style_yaml(msg.data, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Speak_Request & msg, bool use_flow_style = false)
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
  const tangerbot_msgs::srv::Speak_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::srv::Speak_Request & msg)
{
  return tangerbot_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::srv::Speak_Request>()
{
  return "tangerbot_msgs::srv::Speak_Request";
}

template<>
inline const char * name<tangerbot_msgs::srv::Speak_Request>()
{
  return "tangerbot_msgs/srv/Speak_Request";
}

template<>
struct has_fixed_size<tangerbot_msgs::srv::Speak_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tangerbot_msgs::srv::Speak_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tangerbot_msgs::srv::Speak_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace tangerbot_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Speak_Response & msg,
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
  const Speak_Response & msg,
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

inline std::string to_yaml(const Speak_Response & msg, bool use_flow_style = false)
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
  const tangerbot_msgs::srv::Speak_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::srv::Speak_Response & msg)
{
  return tangerbot_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::srv::Speak_Response>()
{
  return "tangerbot_msgs::srv::Speak_Response";
}

template<>
inline const char * name<tangerbot_msgs::srv::Speak_Response>()
{
  return "tangerbot_msgs/srv/Speak_Response";
}

template<>
struct has_fixed_size<tangerbot_msgs::srv::Speak_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tangerbot_msgs::srv::Speak_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tangerbot_msgs::srv::Speak_Response>
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
  const Speak_Event & msg,
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
  const Speak_Event & msg,
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

inline std::string to_yaml(const Speak_Event & msg, bool use_flow_style = false)
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
  const tangerbot_msgs::srv::Speak_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::srv::Speak_Event & msg)
{
  return tangerbot_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::srv::Speak_Event>()
{
  return "tangerbot_msgs::srv::Speak_Event";
}

template<>
inline const char * name<tangerbot_msgs::srv::Speak_Event>()
{
  return "tangerbot_msgs/srv/Speak_Event";
}

template<>
struct has_fixed_size<tangerbot_msgs::srv::Speak_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tangerbot_msgs::srv::Speak_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<tangerbot_msgs::srv::Speak_Request>::value && has_bounded_size<tangerbot_msgs::srv::Speak_Response>::value> {};

template<>
struct is_message<tangerbot_msgs::srv::Speak_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tangerbot_msgs::srv::Speak>()
{
  return "tangerbot_msgs::srv::Speak";
}

template<>
inline const char * name<tangerbot_msgs::srv::Speak>()
{
  return "tangerbot_msgs/srv/Speak";
}

template<>
struct has_fixed_size<tangerbot_msgs::srv::Speak>
  : std::integral_constant<
    bool,
    has_fixed_size<tangerbot_msgs::srv::Speak_Request>::value &&
    has_fixed_size<tangerbot_msgs::srv::Speak_Response>::value
  >
{
};

template<>
struct has_bounded_size<tangerbot_msgs::srv::Speak>
  : std::integral_constant<
    bool,
    has_bounded_size<tangerbot_msgs::srv::Speak_Request>::value &&
    has_bounded_size<tangerbot_msgs::srv::Speak_Response>::value
  >
{
};

template<>
struct is_service<tangerbot_msgs::srv::Speak>
  : std::true_type
{
};

template<>
struct is_service_request<tangerbot_msgs::srv::Speak_Request>
  : std::true_type
{
};

template<>
struct is_service_response<tangerbot_msgs::srv::Speak_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TANGERBOT_MSGS__SRV__DETAIL__SPEAK__TRAITS_HPP_
