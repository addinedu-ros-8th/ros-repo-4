// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tangerbot_msgs:srv/SetState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/srv/set_state.hpp"


#ifndef TANGERBOT_MSGS__SRV__DETAIL__SET_STATE__STRUCT_HPP_
#define TANGERBOT_MSGS__SRV__DETAIL__SET_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tangerbot_msgs__srv__SetState_Request __attribute__((deprecated))
#else
# define DEPRECATED__tangerbot_msgs__srv__SetState_Request __declspec(deprecated)
#endif

namespace tangerbot_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetState_Request_
{
  using Type = SetState_Request_<ContainerAllocator>;

  explicit SetState_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = "";
      this->main_status = 0;
      this->motion_status = 0;
    }
  }

  explicit SetState_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = "";
      this->main_status = 0;
      this->motion_status = 0;
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

  // constant declarations

  // pointer types
  using RawPtr =
    tangerbot_msgs::srv::SetState_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const tangerbot_msgs::srv::SetState_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tangerbot_msgs::srv::SetState_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tangerbot_msgs::srv::SetState_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tangerbot_msgs::srv::SetState_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tangerbot_msgs::srv::SetState_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tangerbot_msgs::srv::SetState_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tangerbot_msgs::srv::SetState_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tangerbot_msgs::srv::SetState_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tangerbot_msgs::srv::SetState_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tangerbot_msgs__srv__SetState_Request
    std::shared_ptr<tangerbot_msgs::srv::SetState_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tangerbot_msgs__srv__SetState_Request
    std::shared_ptr<tangerbot_msgs::srv::SetState_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetState_Request_ & other) const
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
    return true;
  }
  bool operator!=(const SetState_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetState_Request_

// alias to use template instance with default allocator
using SetState_Request =
  tangerbot_msgs::srv::SetState_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tangerbot_msgs


#ifndef _WIN32
# define DEPRECATED__tangerbot_msgs__srv__SetState_Response __attribute__((deprecated))
#else
# define DEPRECATED__tangerbot_msgs__srv__SetState_Response __declspec(deprecated)
#endif

namespace tangerbot_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetState_Response_
{
  using Type = SetState_Response_<ContainerAllocator>;

  explicit SetState_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit SetState_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t IDLE =
    0u;
  static constexpr uint8_t WORKING =
    1u;
  static constexpr uint8_t DEACTIVATE =
    2u;
  static constexpr uint8_t MOVING =
    0u;
  static constexpr uint8_t FOLLOWING =
    1u;
  static constexpr uint8_t STOPPED =
    2u;
  static constexpr uint8_t LOADING =
    3u;

  // pointer types
  using RawPtr =
    tangerbot_msgs::srv::SetState_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const tangerbot_msgs::srv::SetState_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tangerbot_msgs::srv::SetState_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tangerbot_msgs::srv::SetState_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tangerbot_msgs::srv::SetState_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tangerbot_msgs::srv::SetState_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tangerbot_msgs::srv::SetState_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tangerbot_msgs::srv::SetState_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tangerbot_msgs::srv::SetState_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tangerbot_msgs::srv::SetState_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tangerbot_msgs__srv__SetState_Response
    std::shared_ptr<tangerbot_msgs::srv::SetState_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tangerbot_msgs__srv__SetState_Response
    std::shared_ptr<tangerbot_msgs::srv::SetState_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetState_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetState_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetState_Response_

// alias to use template instance with default allocator
using SetState_Response =
  tangerbot_msgs::srv::SetState_Response_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SetState_Response_<ContainerAllocator>::IDLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SetState_Response_<ContainerAllocator>::WORKING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SetState_Response_<ContainerAllocator>::DEACTIVATE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SetState_Response_<ContainerAllocator>::MOVING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SetState_Response_<ContainerAllocator>::FOLLOWING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SetState_Response_<ContainerAllocator>::STOPPED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SetState_Response_<ContainerAllocator>::LOADING;
#endif  // __cplusplus < 201703L

}  // namespace srv

}  // namespace tangerbot_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tangerbot_msgs__srv__SetState_Event __attribute__((deprecated))
#else
# define DEPRECATED__tangerbot_msgs__srv__SetState_Event __declspec(deprecated)
#endif

namespace tangerbot_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetState_Event_
{
  using Type = SetState_Event_<ContainerAllocator>;

  explicit SetState_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit SetState_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<tangerbot_msgs::srv::SetState_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tangerbot_msgs::srv::SetState_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<tangerbot_msgs::srv::SetState_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tangerbot_msgs::srv::SetState_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<tangerbot_msgs::srv::SetState_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tangerbot_msgs::srv::SetState_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<tangerbot_msgs::srv::SetState_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tangerbot_msgs::srv::SetState_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tangerbot_msgs::srv::SetState_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const tangerbot_msgs::srv::SetState_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tangerbot_msgs::srv::SetState_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tangerbot_msgs::srv::SetState_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tangerbot_msgs::srv::SetState_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tangerbot_msgs::srv::SetState_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tangerbot_msgs::srv::SetState_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tangerbot_msgs::srv::SetState_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tangerbot_msgs::srv::SetState_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tangerbot_msgs::srv::SetState_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tangerbot_msgs__srv__SetState_Event
    std::shared_ptr<tangerbot_msgs::srv::SetState_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tangerbot_msgs__srv__SetState_Event
    std::shared_ptr<tangerbot_msgs::srv::SetState_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetState_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetState_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetState_Event_

// alias to use template instance with default allocator
using SetState_Event =
  tangerbot_msgs::srv::SetState_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tangerbot_msgs

namespace tangerbot_msgs
{

namespace srv
{

struct SetState
{
  using Request = tangerbot_msgs::srv::SetState_Request;
  using Response = tangerbot_msgs::srv::SetState_Response;
  using Event = tangerbot_msgs::srv::SetState_Event;
};

}  // namespace srv

}  // namespace tangerbot_msgs

#endif  // TANGERBOT_MSGS__SRV__DETAIL__SET_STATE__STRUCT_HPP_
