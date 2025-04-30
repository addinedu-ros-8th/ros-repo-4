// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tangerbot_msgs:msg/LocalMap.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/msg/local_map.hpp"


#ifndef TANGERBOT_MSGS__MSG__DETAIL__LOCAL_MAP__STRUCT_HPP_
#define TANGERBOT_MSGS__MSG__DETAIL__LOCAL_MAP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tangerbot_msgs__msg__LocalMap __attribute__((deprecated))
#else
# define DEPRECATED__tangerbot_msgs__msg__LocalMap __declspec(deprecated)
#endif

namespace tangerbot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LocalMap_
{
  using Type = LocalMap_<ContainerAllocator>;

  explicit LocalMap_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = "";
      this->resolution = 0.0f;
      this->width = 0ul;
      this->height = 0ul;
      this->origin_x = 0.0f;
      this->origin_y = 0.0f;
    }
  }

  explicit LocalMap_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_id(_alloc),
    header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = "";
      this->resolution = 0.0f;
      this->width = 0ul;
      this->height = 0ul;
      this->origin_x = 0.0f;
      this->origin_y = 0.0f;
    }
  }

  // field types and members
  using _robot_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_id_type robot_id;
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _resolution_type =
    float;
  _resolution_type resolution;
  using _width_type =
    uint32_t;
  _width_type width;
  using _height_type =
    uint32_t;
  _height_type height;
  using _origin_x_type =
    float;
  _origin_x_type origin_x;
  using _origin_y_type =
    float;
  _origin_y_type origin_y;
  using _data_type =
    std::vector<int8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int8_t>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__robot_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_id = _arg;
    return *this;
  }
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__resolution(
    const float & _arg)
  {
    this->resolution = _arg;
    return *this;
  }
  Type & set__width(
    const uint32_t & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__height(
    const uint32_t & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__origin_x(
    const float & _arg)
  {
    this->origin_x = _arg;
    return *this;
  }
  Type & set__origin_y(
    const float & _arg)
  {
    this->origin_y = _arg;
    return *this;
  }
  Type & set__data(
    const std::vector<int8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int8_t>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tangerbot_msgs::msg::LocalMap_<ContainerAllocator> *;
  using ConstRawPtr =
    const tangerbot_msgs::msg::LocalMap_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tangerbot_msgs::msg::LocalMap_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tangerbot_msgs::msg::LocalMap_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tangerbot_msgs::msg::LocalMap_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tangerbot_msgs::msg::LocalMap_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tangerbot_msgs::msg::LocalMap_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tangerbot_msgs::msg::LocalMap_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tangerbot_msgs::msg::LocalMap_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tangerbot_msgs::msg::LocalMap_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tangerbot_msgs__msg__LocalMap
    std::shared_ptr<tangerbot_msgs::msg::LocalMap_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tangerbot_msgs__msg__LocalMap
    std::shared_ptr<tangerbot_msgs::msg::LocalMap_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LocalMap_ & other) const
  {
    if (this->robot_id != other.robot_id) {
      return false;
    }
    if (this->header != other.header) {
      return false;
    }
    if (this->resolution != other.resolution) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    if (this->origin_x != other.origin_x) {
      return false;
    }
    if (this->origin_y != other.origin_y) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const LocalMap_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LocalMap_

// alias to use template instance with default allocator
using LocalMap =
  tangerbot_msgs::msg::LocalMap_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tangerbot_msgs

#endif  // TANGERBOT_MSGS__MSG__DETAIL__LOCAL_MAP__STRUCT_HPP_
