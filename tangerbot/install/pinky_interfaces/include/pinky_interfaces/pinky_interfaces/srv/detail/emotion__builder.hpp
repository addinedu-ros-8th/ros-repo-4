// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pinky_interfaces:srv/Emotion.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pinky_interfaces/srv/emotion.hpp"


#ifndef PINKY_INTERFACES__SRV__DETAIL__EMOTION__BUILDER_HPP_
#define PINKY_INTERFACES__SRV__DETAIL__EMOTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pinky_interfaces/srv/detail/emotion__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pinky_interfaces
{

namespace srv
{

namespace builder
{

class Init_Emotion_Request_emotion
{
public:
  Init_Emotion_Request_emotion()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::pinky_interfaces::srv::Emotion_Request emotion(::pinky_interfaces::srv::Emotion_Request::_emotion_type arg)
  {
    msg_.emotion = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pinky_interfaces::srv::Emotion_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::pinky_interfaces::srv::Emotion_Request>()
{
  return pinky_interfaces::srv::builder::Init_Emotion_Request_emotion();
}

}  // namespace pinky_interfaces


namespace pinky_interfaces
{

namespace srv
{

namespace builder
{

class Init_Emotion_Response_response
{
public:
  Init_Emotion_Response_response()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::pinky_interfaces::srv::Emotion_Response response(::pinky_interfaces::srv::Emotion_Response::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pinky_interfaces::srv::Emotion_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::pinky_interfaces::srv::Emotion_Response>()
{
  return pinky_interfaces::srv::builder::Init_Emotion_Response_response();
}

}  // namespace pinky_interfaces


namespace pinky_interfaces
{

namespace srv
{

namespace builder
{

class Init_Emotion_Event_response
{
public:
  explicit Init_Emotion_Event_response(::pinky_interfaces::srv::Emotion_Event & msg)
  : msg_(msg)
  {}
  ::pinky_interfaces::srv::Emotion_Event response(::pinky_interfaces::srv::Emotion_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pinky_interfaces::srv::Emotion_Event msg_;
};

class Init_Emotion_Event_request
{
public:
  explicit Init_Emotion_Event_request(::pinky_interfaces::srv::Emotion_Event & msg)
  : msg_(msg)
  {}
  Init_Emotion_Event_response request(::pinky_interfaces::srv::Emotion_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Emotion_Event_response(msg_);
  }

private:
  ::pinky_interfaces::srv::Emotion_Event msg_;
};

class Init_Emotion_Event_info
{
public:
  Init_Emotion_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Emotion_Event_request info(::pinky_interfaces::srv::Emotion_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Emotion_Event_request(msg_);
  }

private:
  ::pinky_interfaces::srv::Emotion_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::pinky_interfaces::srv::Emotion_Event>()
{
  return pinky_interfaces::srv::builder::Init_Emotion_Event_info();
}

}  // namespace pinky_interfaces

#endif  // PINKY_INTERFACES__SRV__DETAIL__EMOTION__BUILDER_HPP_
