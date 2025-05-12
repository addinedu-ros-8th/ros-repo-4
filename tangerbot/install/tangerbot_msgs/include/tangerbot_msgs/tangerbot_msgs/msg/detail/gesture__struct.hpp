// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tangerbot_msgs:msg/Gesture.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/msg/gesture.hpp"


#ifndef TANGERBOT_MSGS__MSG__DETAIL__GESTURE__STRUCT_HPP_
#define TANGERBOT_MSGS__MSG__DETAIL__GESTURE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'point'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tangerbot_msgs__msg__Gesture __attribute__((deprecated))
#else
# define DEPRECATED__tangerbot_msgs__msg__Gesture __declspec(deprecated)
#endif

namespace tangerbot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Gesture_
{
  using Type = Gesture_<ContainerAllocator>;

  explicit Gesture_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : point(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = "";
    }
  }

  explicit Gesture_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_id(_alloc),
    point(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = "";
    }
  }

  // field types and members
  using _robot_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_id_type robot_id;
  using _point_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _point_type point;

  // setters for named parameter idiom
  Type & set__robot_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_id = _arg;
    return *this;
  }
  Type & set__point(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->point = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tangerbot_msgs::msg::Gesture_<ContainerAllocator> *;
  using ConstRawPtr =
    const tangerbot_msgs::msg::Gesture_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tangerbot_msgs::msg::Gesture_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tangerbot_msgs::msg::Gesture_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tangerbot_msgs::msg::Gesture_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tangerbot_msgs::msg::Gesture_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tangerbot_msgs::msg::Gesture_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tangerbot_msgs::msg::Gesture_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tangerbot_msgs::msg::Gesture_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tangerbot_msgs::msg::Gesture_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tangerbot_msgs__msg__Gesture
    std::shared_ptr<tangerbot_msgs::msg::Gesture_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tangerbot_msgs__msg__Gesture
    std::shared_ptr<tangerbot_msgs::msg::Gesture_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Gesture_ & other) const
  {
    if (this->robot_id != other.robot_id) {
      return false;
    }
    if (this->point != other.point) {
      return false;
    }
    return true;
  }
  bool operator!=(const Gesture_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Gesture_

// alias to use template instance with default allocator
using Gesture =
  tangerbot_msgs::msg::Gesture_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tangerbot_msgs

#endif  // TANGERBOT_MSGS__MSG__DETAIL__GESTURE__STRUCT_HPP_
