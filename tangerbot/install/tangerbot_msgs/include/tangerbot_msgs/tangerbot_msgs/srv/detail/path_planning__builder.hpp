// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tangerbot_msgs:srv/PathPlanning.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/srv/path_planning.hpp"


#ifndef TANGERBOT_MSGS__SRV__DETAIL__PATH_PLANNING__BUILDER_HPP_
#define TANGERBOT_MSGS__SRV__DETAIL__PATH_PLANNING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tangerbot_msgs/srv/detail/path_planning__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tangerbot_msgs
{

namespace srv
{

namespace builder
{

class Init_PathPlanning_Request_end
{
public:
  explicit Init_PathPlanning_Request_end(::tangerbot_msgs::srv::PathPlanning_Request & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::srv::PathPlanning_Request end(::tangerbot_msgs::srv::PathPlanning_Request::_end_type arg)
  {
    msg_.end = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::srv::PathPlanning_Request msg_;
};

class Init_PathPlanning_Request_robot_id
{
public:
  Init_PathPlanning_Request_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PathPlanning_Request_end robot_id(::tangerbot_msgs::srv::PathPlanning_Request::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_PathPlanning_Request_end(msg_);
  }

private:
  ::tangerbot_msgs::srv::PathPlanning_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::srv::PathPlanning_Request>()
{
  return tangerbot_msgs::srv::builder::Init_PathPlanning_Request_robot_id();
}

}  // namespace tangerbot_msgs


namespace tangerbot_msgs
{

namespace srv
{

namespace builder
{

class Init_PathPlanning_Response_distance
{
public:
  explicit Init_PathPlanning_Response_distance(::tangerbot_msgs::srv::PathPlanning_Response & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::srv::PathPlanning_Response distance(::tangerbot_msgs::srv::PathPlanning_Response::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::srv::PathPlanning_Response msg_;
};

class Init_PathPlanning_Response_waypoints
{
public:
  explicit Init_PathPlanning_Response_waypoints(::tangerbot_msgs::srv::PathPlanning_Response & msg)
  : msg_(msg)
  {}
  Init_PathPlanning_Response_distance waypoints(::tangerbot_msgs::srv::PathPlanning_Response::_waypoints_type arg)
  {
    msg_.waypoints = std::move(arg);
    return Init_PathPlanning_Response_distance(msg_);
  }

private:
  ::tangerbot_msgs::srv::PathPlanning_Response msg_;
};

class Init_PathPlanning_Response_robot_id
{
public:
  Init_PathPlanning_Response_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PathPlanning_Response_waypoints robot_id(::tangerbot_msgs::srv::PathPlanning_Response::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_PathPlanning_Response_waypoints(msg_);
  }

private:
  ::tangerbot_msgs::srv::PathPlanning_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::srv::PathPlanning_Response>()
{
  return tangerbot_msgs::srv::builder::Init_PathPlanning_Response_robot_id();
}

}  // namespace tangerbot_msgs


namespace tangerbot_msgs
{

namespace srv
{

namespace builder
{

class Init_PathPlanning_Event_response
{
public:
  explicit Init_PathPlanning_Event_response(::tangerbot_msgs::srv::PathPlanning_Event & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::srv::PathPlanning_Event response(::tangerbot_msgs::srv::PathPlanning_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::srv::PathPlanning_Event msg_;
};

class Init_PathPlanning_Event_request
{
public:
  explicit Init_PathPlanning_Event_request(::tangerbot_msgs::srv::PathPlanning_Event & msg)
  : msg_(msg)
  {}
  Init_PathPlanning_Event_response request(::tangerbot_msgs::srv::PathPlanning_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_PathPlanning_Event_response(msg_);
  }

private:
  ::tangerbot_msgs::srv::PathPlanning_Event msg_;
};

class Init_PathPlanning_Event_info
{
public:
  Init_PathPlanning_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PathPlanning_Event_request info(::tangerbot_msgs::srv::PathPlanning_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_PathPlanning_Event_request(msg_);
  }

private:
  ::tangerbot_msgs::srv::PathPlanning_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::srv::PathPlanning_Event>()
{
  return tangerbot_msgs::srv::builder::Init_PathPlanning_Event_info();
}

}  // namespace tangerbot_msgs

#endif  // TANGERBOT_MSGS__SRV__DETAIL__PATH_PLANNING__BUILDER_HPP_
