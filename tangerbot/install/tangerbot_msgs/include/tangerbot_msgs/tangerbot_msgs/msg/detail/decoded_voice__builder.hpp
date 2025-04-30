// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tangerbot_msgs:msg/DecodedVoice.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/msg/decoded_voice.hpp"


#ifndef TANGERBOT_MSGS__MSG__DETAIL__DECODED_VOICE__BUILDER_HPP_
#define TANGERBOT_MSGS__MSG__DETAIL__DECODED_VOICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tangerbot_msgs/msg/detail/decoded_voice__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tangerbot_msgs
{

namespace msg
{

namespace builder
{

class Init_DecodedVoice_text
{
public:
  explicit Init_DecodedVoice_text(::tangerbot_msgs::msg::DecodedVoice & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::msg::DecodedVoice text(::tangerbot_msgs::msg::DecodedVoice::_text_type arg)
  {
    msg_.text = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::msg::DecodedVoice msg_;
};

class Init_DecodedVoice_user_id
{
public:
  Init_DecodedVoice_user_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DecodedVoice_text user_id(::tangerbot_msgs::msg::DecodedVoice::_user_id_type arg)
  {
    msg_.user_id = std::move(arg);
    return Init_DecodedVoice_text(msg_);
  }

private:
  ::tangerbot_msgs::msg::DecodedVoice msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::msg::DecodedVoice>()
{
  return tangerbot_msgs::msg::builder::Init_DecodedVoice_user_id();
}

}  // namespace tangerbot_msgs

#endif  // TANGERBOT_MSGS__MSG__DETAIL__DECODED_VOICE__BUILDER_HPP_
