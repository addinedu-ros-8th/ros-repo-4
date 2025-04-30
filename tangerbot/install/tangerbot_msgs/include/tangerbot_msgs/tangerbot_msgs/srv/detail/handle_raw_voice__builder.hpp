// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tangerbot_msgs:srv/HandleRawVoice.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/srv/handle_raw_voice.hpp"


#ifndef TANGERBOT_MSGS__SRV__DETAIL__HANDLE_RAW_VOICE__BUILDER_HPP_
#define TANGERBOT_MSGS__SRV__DETAIL__HANDLE_RAW_VOICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tangerbot_msgs/srv/detail/handle_raw_voice__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tangerbot_msgs
{

namespace srv
{

namespace builder
{

class Init_HandleRawVoice_Request_data
{
public:
  explicit Init_HandleRawVoice_Request_data(::tangerbot_msgs::srv::HandleRawVoice_Request & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::srv::HandleRawVoice_Request data(::tangerbot_msgs::srv::HandleRawVoice_Request::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::srv::HandleRawVoice_Request msg_;
};

class Init_HandleRawVoice_Request_user_id
{
public:
  explicit Init_HandleRawVoice_Request_user_id(::tangerbot_msgs::srv::HandleRawVoice_Request & msg)
  : msg_(msg)
  {}
  Init_HandleRawVoice_Request_data user_id(::tangerbot_msgs::srv::HandleRawVoice_Request::_user_id_type arg)
  {
    msg_.user_id = std::move(arg);
    return Init_HandleRawVoice_Request_data(msg_);
  }

private:
  ::tangerbot_msgs::srv::HandleRawVoice_Request msg_;
};

class Init_HandleRawVoice_Request_robot_id
{
public:
  Init_HandleRawVoice_Request_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HandleRawVoice_Request_user_id robot_id(::tangerbot_msgs::srv::HandleRawVoice_Request::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_HandleRawVoice_Request_user_id(msg_);
  }

private:
  ::tangerbot_msgs::srv::HandleRawVoice_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::srv::HandleRawVoice_Request>()
{
  return tangerbot_msgs::srv::builder::Init_HandleRawVoice_Request_robot_id();
}

}  // namespace tangerbot_msgs


namespace tangerbot_msgs
{

namespace srv
{

namespace builder
{

class Init_HandleRawVoice_Response_success
{
public:
  Init_HandleRawVoice_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tangerbot_msgs::srv::HandleRawVoice_Response success(::tangerbot_msgs::srv::HandleRawVoice_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::srv::HandleRawVoice_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::srv::HandleRawVoice_Response>()
{
  return tangerbot_msgs::srv::builder::Init_HandleRawVoice_Response_success();
}

}  // namespace tangerbot_msgs


namespace tangerbot_msgs
{

namespace srv
{

namespace builder
{

class Init_HandleRawVoice_Event_response
{
public:
  explicit Init_HandleRawVoice_Event_response(::tangerbot_msgs::srv::HandleRawVoice_Event & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::srv::HandleRawVoice_Event response(::tangerbot_msgs::srv::HandleRawVoice_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::srv::HandleRawVoice_Event msg_;
};

class Init_HandleRawVoice_Event_request
{
public:
  explicit Init_HandleRawVoice_Event_request(::tangerbot_msgs::srv::HandleRawVoice_Event & msg)
  : msg_(msg)
  {}
  Init_HandleRawVoice_Event_response request(::tangerbot_msgs::srv::HandleRawVoice_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_HandleRawVoice_Event_response(msg_);
  }

private:
  ::tangerbot_msgs::srv::HandleRawVoice_Event msg_;
};

class Init_HandleRawVoice_Event_info
{
public:
  Init_HandleRawVoice_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HandleRawVoice_Event_request info(::tangerbot_msgs::srv::HandleRawVoice_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_HandleRawVoice_Event_request(msg_);
  }

private:
  ::tangerbot_msgs::srv::HandleRawVoice_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::srv::HandleRawVoice_Event>()
{
  return tangerbot_msgs::srv::builder::Init_HandleRawVoice_Event_info();
}

}  // namespace tangerbot_msgs

#endif  // TANGERBOT_MSGS__SRV__DETAIL__HANDLE_RAW_VOICE__BUILDER_HPP_
