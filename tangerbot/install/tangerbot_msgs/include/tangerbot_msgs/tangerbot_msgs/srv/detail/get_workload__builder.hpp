// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tangerbot_msgs:srv/GetWorkload.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/srv/get_workload.hpp"


#ifndef TANGERBOT_MSGS__SRV__DETAIL__GET_WORKLOAD__BUILDER_HPP_
#define TANGERBOT_MSGS__SRV__DETAIL__GET_WORKLOAD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tangerbot_msgs/srv/detail/get_workload__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tangerbot_msgs
{

namespace srv
{

namespace builder
{

class Init_GetWorkload_Request_robot_id
{
public:
  Init_GetWorkload_Request_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tangerbot_msgs::srv::GetWorkload_Request robot_id(::tangerbot_msgs::srv::GetWorkload_Request::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::srv::GetWorkload_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::srv::GetWorkload_Request>()
{
  return tangerbot_msgs::srv::builder::Init_GetWorkload_Request_robot_id();
}

}  // namespace tangerbot_msgs


namespace tangerbot_msgs
{

namespace srv
{

namespace builder
{

class Init_GetWorkload_Response_workload
{
public:
  Init_GetWorkload_Response_workload()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tangerbot_msgs::srv::GetWorkload_Response workload(::tangerbot_msgs::srv::GetWorkload_Response::_workload_type arg)
  {
    msg_.workload = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::srv::GetWorkload_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::srv::GetWorkload_Response>()
{
  return tangerbot_msgs::srv::builder::Init_GetWorkload_Response_workload();
}

}  // namespace tangerbot_msgs


namespace tangerbot_msgs
{

namespace srv
{

namespace builder
{

class Init_GetWorkload_Event_response
{
public:
  explicit Init_GetWorkload_Event_response(::tangerbot_msgs::srv::GetWorkload_Event & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::srv::GetWorkload_Event response(::tangerbot_msgs::srv::GetWorkload_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::srv::GetWorkload_Event msg_;
};

class Init_GetWorkload_Event_request
{
public:
  explicit Init_GetWorkload_Event_request(::tangerbot_msgs::srv::GetWorkload_Event & msg)
  : msg_(msg)
  {}
  Init_GetWorkload_Event_response request(::tangerbot_msgs::srv::GetWorkload_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetWorkload_Event_response(msg_);
  }

private:
  ::tangerbot_msgs::srv::GetWorkload_Event msg_;
};

class Init_GetWorkload_Event_info
{
public:
  Init_GetWorkload_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetWorkload_Event_request info(::tangerbot_msgs::srv::GetWorkload_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetWorkload_Event_request(msg_);
  }

private:
  ::tangerbot_msgs::srv::GetWorkload_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::srv::GetWorkload_Event>()
{
  return tangerbot_msgs::srv::builder::Init_GetWorkload_Event_info();
}

}  // namespace tangerbot_msgs

#endif  // TANGERBOT_MSGS__SRV__DETAIL__GET_WORKLOAD__BUILDER_HPP_
