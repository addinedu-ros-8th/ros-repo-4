// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tangerbot_msgs:msg/LocalMap.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/msg/local_map.hpp"


#ifndef TANGERBOT_MSGS__MSG__DETAIL__LOCAL_MAP__BUILDER_HPP_
#define TANGERBOT_MSGS__MSG__DETAIL__LOCAL_MAP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tangerbot_msgs/msg/detail/local_map__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tangerbot_msgs
{

namespace msg
{

namespace builder
{

class Init_LocalMap_data
{
public:
  explicit Init_LocalMap_data(::tangerbot_msgs::msg::LocalMap & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::msg::LocalMap data(::tangerbot_msgs::msg::LocalMap::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::msg::LocalMap msg_;
};

class Init_LocalMap_origin_y
{
public:
  explicit Init_LocalMap_origin_y(::tangerbot_msgs::msg::LocalMap & msg)
  : msg_(msg)
  {}
  Init_LocalMap_data origin_y(::tangerbot_msgs::msg::LocalMap::_origin_y_type arg)
  {
    msg_.origin_y = std::move(arg);
    return Init_LocalMap_data(msg_);
  }

private:
  ::tangerbot_msgs::msg::LocalMap msg_;
};

class Init_LocalMap_origin_x
{
public:
  explicit Init_LocalMap_origin_x(::tangerbot_msgs::msg::LocalMap & msg)
  : msg_(msg)
  {}
  Init_LocalMap_origin_y origin_x(::tangerbot_msgs::msg::LocalMap::_origin_x_type arg)
  {
    msg_.origin_x = std::move(arg);
    return Init_LocalMap_origin_y(msg_);
  }

private:
  ::tangerbot_msgs::msg::LocalMap msg_;
};

class Init_LocalMap_height
{
public:
  explicit Init_LocalMap_height(::tangerbot_msgs::msg::LocalMap & msg)
  : msg_(msg)
  {}
  Init_LocalMap_origin_x height(::tangerbot_msgs::msg::LocalMap::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_LocalMap_origin_x(msg_);
  }

private:
  ::tangerbot_msgs::msg::LocalMap msg_;
};

class Init_LocalMap_width
{
public:
  explicit Init_LocalMap_width(::tangerbot_msgs::msg::LocalMap & msg)
  : msg_(msg)
  {}
  Init_LocalMap_height width(::tangerbot_msgs::msg::LocalMap::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_LocalMap_height(msg_);
  }

private:
  ::tangerbot_msgs::msg::LocalMap msg_;
};

class Init_LocalMap_resolution
{
public:
  explicit Init_LocalMap_resolution(::tangerbot_msgs::msg::LocalMap & msg)
  : msg_(msg)
  {}
  Init_LocalMap_width resolution(::tangerbot_msgs::msg::LocalMap::_resolution_type arg)
  {
    msg_.resolution = std::move(arg);
    return Init_LocalMap_width(msg_);
  }

private:
  ::tangerbot_msgs::msg::LocalMap msg_;
};

class Init_LocalMap_header
{
public:
  explicit Init_LocalMap_header(::tangerbot_msgs::msg::LocalMap & msg)
  : msg_(msg)
  {}
  Init_LocalMap_resolution header(::tangerbot_msgs::msg::LocalMap::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_LocalMap_resolution(msg_);
  }

private:
  ::tangerbot_msgs::msg::LocalMap msg_;
};

class Init_LocalMap_robot_id
{
public:
  Init_LocalMap_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LocalMap_header robot_id(::tangerbot_msgs::msg::LocalMap::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_LocalMap_header(msg_);
  }

private:
  ::tangerbot_msgs::msg::LocalMap msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::msg::LocalMap>()
{
  return tangerbot_msgs::msg::builder::Init_LocalMap_robot_id();
}

}  // namespace tangerbot_msgs

#endif  // TANGERBOT_MSGS__MSG__DETAIL__LOCAL_MAP__BUILDER_HPP_
