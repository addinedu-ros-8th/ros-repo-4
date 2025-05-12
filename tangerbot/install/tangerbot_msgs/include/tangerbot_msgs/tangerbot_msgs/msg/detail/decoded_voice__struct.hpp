// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tangerbot_msgs:msg/DecodedVoice.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/msg/decoded_voice.hpp"


#ifndef TANGERBOT_MSGS__MSG__DETAIL__DECODED_VOICE__STRUCT_HPP_
#define TANGERBOT_MSGS__MSG__DETAIL__DECODED_VOICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tangerbot_msgs__msg__DecodedVoice __attribute__((deprecated))
#else
# define DEPRECATED__tangerbot_msgs__msg__DecodedVoice __declspec(deprecated)
#endif

namespace tangerbot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DecodedVoice_
{
  using Type = DecodedVoice_<ContainerAllocator>;

  explicit DecodedVoice_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->user_id = "";
      this->text = "";
    }
  }

  explicit DecodedVoice_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : user_id(_alloc),
    text(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->user_id = "";
      this->text = "";
    }
  }

  // field types and members
  using _user_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _user_id_type user_id;
  using _text_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _text_type text;

  // setters for named parameter idiom
  Type & set__user_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->user_id = _arg;
    return *this;
  }
  Type & set__text(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->text = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tangerbot_msgs::msg::DecodedVoice_<ContainerAllocator> *;
  using ConstRawPtr =
    const tangerbot_msgs::msg::DecodedVoice_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tangerbot_msgs::msg::DecodedVoice_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tangerbot_msgs::msg::DecodedVoice_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tangerbot_msgs::msg::DecodedVoice_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tangerbot_msgs::msg::DecodedVoice_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tangerbot_msgs::msg::DecodedVoice_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tangerbot_msgs::msg::DecodedVoice_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tangerbot_msgs::msg::DecodedVoice_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tangerbot_msgs::msg::DecodedVoice_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tangerbot_msgs__msg__DecodedVoice
    std::shared_ptr<tangerbot_msgs::msg::DecodedVoice_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tangerbot_msgs__msg__DecodedVoice
    std::shared_ptr<tangerbot_msgs::msg::DecodedVoice_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DecodedVoice_ & other) const
  {
    if (this->user_id != other.user_id) {
      return false;
    }
    if (this->text != other.text) {
      return false;
    }
    return true;
  }
  bool operator!=(const DecodedVoice_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DecodedVoice_

// alias to use template instance with default allocator
using DecodedVoice =
  tangerbot_msgs::msg::DecodedVoice_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tangerbot_msgs

#endif  // TANGERBOT_MSGS__MSG__DETAIL__DECODED_VOICE__STRUCT_HPP_
