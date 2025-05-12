// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tangerbot_msgs:srv/PathPlanning.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/srv/path_planning.hpp"


#ifndef TANGERBOT_MSGS__SRV__DETAIL__PATH_PLANNING__TRAITS_HPP_
#define TANGERBOT_MSGS__SRV__DETAIL__PATH_PLANNING__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tangerbot_msgs/srv/detail/path_planning__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tangerbot_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const PathPlanning_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    if (msg.robot_id.size() == 0) {
      out << "robot_id: []";
    } else {
      out << "robot_id: [";
      size_t pending_items = msg.robot_id.size();
      for (auto item : msg.robot_id) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: end
  {
    if (msg.end.size() == 0) {
      out << "end: []";
    } else {
      out << "end: [";
      size_t pending_items = msg.end.size();
      for (auto item : msg.end) {
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
  const PathPlanning_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.robot_id.size() == 0) {
      out << "robot_id: []\n";
    } else {
      out << "robot_id:\n";
      for (auto item : msg.robot_id) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: end
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.end.size() == 0) {
      out << "end: []\n";
    } else {
      out << "end:\n";
      for (auto item : msg.end) {
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

inline std::string to_yaml(const PathPlanning_Request & msg, bool use_flow_style = false)
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
  const tangerbot_msgs::srv::PathPlanning_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::srv::PathPlanning_Request & msg)
{
  return tangerbot_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::srv::PathPlanning_Request>()
{
  return "tangerbot_msgs::srv::PathPlanning_Request";
}

template<>
inline const char * name<tangerbot_msgs::srv::PathPlanning_Request>()
{
  return "tangerbot_msgs/srv/PathPlanning_Request";
}

template<>
struct has_fixed_size<tangerbot_msgs::srv::PathPlanning_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tangerbot_msgs::srv::PathPlanning_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tangerbot_msgs::srv::PathPlanning_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'waypoints'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace tangerbot_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const PathPlanning_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    if (msg.robot_id.size() == 0) {
      out << "robot_id: []";
    } else {
      out << "robot_id: [";
      size_t pending_items = msg.robot_id.size();
      for (auto item : msg.robot_id) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: waypoints
  {
    if (msg.waypoints.size() == 0) {
      out << "waypoints: []";
    } else {
      out << "waypoints: [";
      size_t pending_items = msg.waypoints.size();
      for (auto item : msg.waypoints) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: distance
  {
    if (msg.distance.size() == 0) {
      out << "distance: []";
    } else {
      out << "distance: [";
      size_t pending_items = msg.distance.size();
      for (auto item : msg.distance) {
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
  const PathPlanning_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.robot_id.size() == 0) {
      out << "robot_id: []\n";
    } else {
      out << "robot_id:\n";
      for (auto item : msg.robot_id) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: waypoints
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.waypoints.size() == 0) {
      out << "waypoints: []\n";
    } else {
      out << "waypoints:\n";
      for (auto item : msg.waypoints) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.distance.size() == 0) {
      out << "distance: []\n";
    } else {
      out << "distance:\n";
      for (auto item : msg.distance) {
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

inline std::string to_yaml(const PathPlanning_Response & msg, bool use_flow_style = false)
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
  const tangerbot_msgs::srv::PathPlanning_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::srv::PathPlanning_Response & msg)
{
  return tangerbot_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::srv::PathPlanning_Response>()
{
  return "tangerbot_msgs::srv::PathPlanning_Response";
}

template<>
inline const char * name<tangerbot_msgs::srv::PathPlanning_Response>()
{
  return "tangerbot_msgs/srv/PathPlanning_Response";
}

template<>
struct has_fixed_size<tangerbot_msgs::srv::PathPlanning_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tangerbot_msgs::srv::PathPlanning_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tangerbot_msgs::srv::PathPlanning_Response>
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
  const PathPlanning_Event & msg,
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
  const PathPlanning_Event & msg,
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

inline std::string to_yaml(const PathPlanning_Event & msg, bool use_flow_style = false)
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
  const tangerbot_msgs::srv::PathPlanning_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  tangerbot_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tangerbot_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const tangerbot_msgs::srv::PathPlanning_Event & msg)
{
  return tangerbot_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tangerbot_msgs::srv::PathPlanning_Event>()
{
  return "tangerbot_msgs::srv::PathPlanning_Event";
}

template<>
inline const char * name<tangerbot_msgs::srv::PathPlanning_Event>()
{
  return "tangerbot_msgs/srv/PathPlanning_Event";
}

template<>
struct has_fixed_size<tangerbot_msgs::srv::PathPlanning_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tangerbot_msgs::srv::PathPlanning_Event>
  : std::integral_constant<bool, has_bounded_size<service_msgs::msg::ServiceEventInfo>::value && has_bounded_size<tangerbot_msgs::srv::PathPlanning_Request>::value && has_bounded_size<tangerbot_msgs::srv::PathPlanning_Response>::value> {};

template<>
struct is_message<tangerbot_msgs::srv::PathPlanning_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tangerbot_msgs::srv::PathPlanning>()
{
  return "tangerbot_msgs::srv::PathPlanning";
}

template<>
inline const char * name<tangerbot_msgs::srv::PathPlanning>()
{
  return "tangerbot_msgs/srv/PathPlanning";
}

template<>
struct has_fixed_size<tangerbot_msgs::srv::PathPlanning>
  : std::integral_constant<
    bool,
    has_fixed_size<tangerbot_msgs::srv::PathPlanning_Request>::value &&
    has_fixed_size<tangerbot_msgs::srv::PathPlanning_Response>::value
  >
{
};

template<>
struct has_bounded_size<tangerbot_msgs::srv::PathPlanning>
  : std::integral_constant<
    bool,
    has_bounded_size<tangerbot_msgs::srv::PathPlanning_Request>::value &&
    has_bounded_size<tangerbot_msgs::srv::PathPlanning_Response>::value
  >
{
};

template<>
struct is_service<tangerbot_msgs::srv::PathPlanning>
  : std::true_type
{
};

template<>
struct is_service_request<tangerbot_msgs::srv::PathPlanning_Request>
  : std::true_type
{
};

template<>
struct is_service_response<tangerbot_msgs::srv::PathPlanning_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TANGERBOT_MSGS__SRV__DETAIL__PATH_PLANNING__TRAITS_HPP_
