// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tangerbot_msgs:srv/Redirect.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/srv/redirect.hpp"


#ifndef TANGERBOT_MSGS__SRV__DETAIL__REDIRECT__BUILDER_HPP_
#define TANGERBOT_MSGS__SRV__DETAIL__REDIRECT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tangerbot_msgs/srv/detail/redirect__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tangerbot_msgs
{

namespace srv
{

namespace builder
{

class Init_Redirect_Request_robot_id
{
public:
  Init_Redirect_Request_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tangerbot_msgs::srv::Redirect_Request robot_id(::tangerbot_msgs::srv::Redirect_Request::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::srv::Redirect_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::srv::Redirect_Request>()
{
  return tangerbot_msgs::srv::builder::Init_Redirect_Request_robot_id();
}

}  // namespace tangerbot_msgs


namespace tangerbot_msgs
{

namespace srv
{

namespace builder
{

class Init_Redirect_Response_success
{
public:
  Init_Redirect_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tangerbot_msgs::srv::Redirect_Response success(::tangerbot_msgs::srv::Redirect_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::srv::Redirect_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::srv::Redirect_Response>()
{
  return tangerbot_msgs::srv::builder::Init_Redirect_Response_success();
}

}  // namespace tangerbot_msgs


namespace tangerbot_msgs
{

namespace srv
{

namespace builder
{

class Init_Redirect_Event_response
{
public:
  explicit Init_Redirect_Event_response(::tangerbot_msgs::srv::Redirect_Event & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::srv::Redirect_Event response(::tangerbot_msgs::srv::Redirect_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::srv::Redirect_Event msg_;
};

class Init_Redirect_Event_request
{
public:
  explicit Init_Redirect_Event_request(::tangerbot_msgs::srv::Redirect_Event & msg)
  : msg_(msg)
  {}
  Init_Redirect_Event_response request(::tangerbot_msgs::srv::Redirect_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Redirect_Event_response(msg_);
  }

private:
  ::tangerbot_msgs::srv::Redirect_Event msg_;
};

class Init_Redirect_Event_info
{
public:
  Init_Redirect_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Redirect_Event_request info(::tangerbot_msgs::srv::Redirect_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Redirect_Event_request(msg_);
  }

private:
  ::tangerbot_msgs::srv::Redirect_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::srv::Redirect_Event>()
{
  return tangerbot_msgs::srv::builder::Init_Redirect_Event_info();
}

}  // namespace tangerbot_msgs

#endif  // TANGERBOT_MSGS__SRV__DETAIL__REDIRECT__BUILDER_HPP_
