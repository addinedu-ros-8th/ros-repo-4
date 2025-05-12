// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tangerbot_msgs:srv/SetFollowMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/srv/set_follow_mode.hpp"


#ifndef TANGERBOT_MSGS__SRV__DETAIL__SET_FOLLOW_MODE__BUILDER_HPP_
#define TANGERBOT_MSGS__SRV__DETAIL__SET_FOLLOW_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tangerbot_msgs/srv/detail/set_follow_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tangerbot_msgs
{

namespace srv
{

namespace builder
{

class Init_SetFollowMode_Request_mode
{
public:
  explicit Init_SetFollowMode_Request_mode(::tangerbot_msgs::srv::SetFollowMode_Request & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::srv::SetFollowMode_Request mode(::tangerbot_msgs::srv::SetFollowMode_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::srv::SetFollowMode_Request msg_;
};

class Init_SetFollowMode_Request_robot_id
{
public:
  Init_SetFollowMode_Request_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetFollowMode_Request_mode robot_id(::tangerbot_msgs::srv::SetFollowMode_Request::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_SetFollowMode_Request_mode(msg_);
  }

private:
  ::tangerbot_msgs::srv::SetFollowMode_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::srv::SetFollowMode_Request>()
{
  return tangerbot_msgs::srv::builder::Init_SetFollowMode_Request_robot_id();
}

}  // namespace tangerbot_msgs


namespace tangerbot_msgs
{

namespace srv
{

namespace builder
{

class Init_SetFollowMode_Response_success
{
public:
  Init_SetFollowMode_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tangerbot_msgs::srv::SetFollowMode_Response success(::tangerbot_msgs::srv::SetFollowMode_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::srv::SetFollowMode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::srv::SetFollowMode_Response>()
{
  return tangerbot_msgs::srv::builder::Init_SetFollowMode_Response_success();
}

}  // namespace tangerbot_msgs


namespace tangerbot_msgs
{

namespace srv
{

namespace builder
{

class Init_SetFollowMode_Event_response
{
public:
  explicit Init_SetFollowMode_Event_response(::tangerbot_msgs::srv::SetFollowMode_Event & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::srv::SetFollowMode_Event response(::tangerbot_msgs::srv::SetFollowMode_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::srv::SetFollowMode_Event msg_;
};

class Init_SetFollowMode_Event_request
{
public:
  explicit Init_SetFollowMode_Event_request(::tangerbot_msgs::srv::SetFollowMode_Event & msg)
  : msg_(msg)
  {}
  Init_SetFollowMode_Event_response request(::tangerbot_msgs::srv::SetFollowMode_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetFollowMode_Event_response(msg_);
  }

private:
  ::tangerbot_msgs::srv::SetFollowMode_Event msg_;
};

class Init_SetFollowMode_Event_info
{
public:
  Init_SetFollowMode_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetFollowMode_Event_request info(::tangerbot_msgs::srv::SetFollowMode_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetFollowMode_Event_request(msg_);
  }

private:
  ::tangerbot_msgs::srv::SetFollowMode_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::srv::SetFollowMode_Event>()
{
  return tangerbot_msgs::srv::builder::Init_SetFollowMode_Event_info();
}

}  // namespace tangerbot_msgs

#endif  // TANGERBOT_MSGS__SRV__DETAIL__SET_FOLLOW_MODE__BUILDER_HPP_
