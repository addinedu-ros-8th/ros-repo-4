// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tangerbot_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/msg/robot_state.hpp"


#ifndef TANGERBOT_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_HPP_
#define TANGERBOT_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tangerbot_msgs__msg__RobotState __attribute__((deprecated))
#else
# define DEPRECATED__tangerbot_msgs__msg__RobotState __declspec(deprecated)
#endif

namespace tangerbot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotState_
{
  using Type = RobotState_<ContainerAllocator>;

  explicit RobotState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = "";
      this->main_status = 0;
      this->motion_status = 0;
      this->battery = 0.0f;
    }
  }

  explicit RobotState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = "";
      this->main_status = 0;
      this->motion_status = 0;
      this->battery = 0.0f;
    }
  }

  // field types and members
  using _robot_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_id_type robot_id;
  using _main_status_type =
    uint8_t;
  _main_status_type main_status;
  using _motion_status_type =
    uint8_t;
  _motion_status_type motion_status;
  using _battery_type =
    float;
  _battery_type battery;

  // setters for named parameter idiom
  Type & set__robot_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_id = _arg;
    return *this;
  }
  Type & set__main_status(
    const uint8_t & _arg)
  {
    this->main_status = _arg;
    return *this;
  }
  Type & set__motion_status(
    const uint8_t & _arg)
  {
    this->motion_status = _arg;
    return *this;
  }
  Type & set__battery(
    const float & _arg)
  {
    this->battery = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t IDLE =
    0u;
  static constexpr uint8_t WORKING =
    1u;
  static constexpr uint8_t MOVING =
    0u;
  static constexpr uint8_t FOLLOWING =
    1u;
  static constexpr uint8_t STOP =
    2u;
  static constexpr uint8_t LOADING =
    3u;

  // pointer types
  using RawPtr =
    tangerbot_msgs::msg::RobotState_<ContainerAllocator> *;
  using ConstRawPtr =
    const tangerbot_msgs::msg::RobotState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tangerbot_msgs::msg::RobotState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tangerbot_msgs::msg::RobotState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tangerbot_msgs::msg::RobotState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tangerbot_msgs::msg::RobotState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tangerbot_msgs::msg::RobotState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tangerbot_msgs::msg::RobotState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tangerbot_msgs::msg::RobotState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tangerbot_msgs::msg::RobotState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tangerbot_msgs__msg__RobotState
    std::shared_ptr<tangerbot_msgs::msg::RobotState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tangerbot_msgs__msg__RobotState
    std::shared_ptr<tangerbot_msgs::msg::RobotState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotState_ & other) const
  {
    if (this->robot_id != other.robot_id) {
      return false;
    }
    if (this->main_status != other.main_status) {
      return false;
    }
    if (this->motion_status != other.motion_status) {
      return false;
    }
    if (this->battery != other.battery) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotState_

// alias to use template instance with default allocator
using RobotState =
  tangerbot_msgs::msg::RobotState_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotState_<ContainerAllocator>::IDLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotState_<ContainerAllocator>::WORKING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotState_<ContainerAllocator>::MOVING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotState_<ContainerAllocator>::FOLLOWING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotState_<ContainerAllocator>::STOP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RobotState_<ContainerAllocator>::LOADING;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace tangerbot_msgs

#endif  // TANGERBOT_MSGS__MSG__DETAIL__ROBOT_STATE__STRUCT_HPP_
