// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tangerbot_msgs:srv/SetFollowMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/srv/set_follow_mode.hpp"


#ifndef TANGERBOT_MSGS__SRV__DETAIL__SET_FOLLOW_MODE__STRUCT_HPP_
#define TANGERBOT_MSGS__SRV__DETAIL__SET_FOLLOW_MODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tangerbot_msgs__srv__SetFollowMode_Request __attribute__((deprecated))
#else
# define DEPRECATED__tangerbot_msgs__srv__SetFollowMode_Request __declspec(deprecated)
#endif

namespace tangerbot_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetFollowMode_Request_
{
  using Type = SetFollowMode_Request_<ContainerAllocator>;

  explicit SetFollowMode_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = "";
      this->mode = false;
    }
  }

  explicit SetFollowMode_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = "";
      this->mode = false;
    }
  }

  // field types and members
  using _robot_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_id_type robot_id;
  using _mode_type =
    bool;
  _mode_type mode;

  // setters for named parameter idiom
  Type & set__robot_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_id = _arg;
    return *this;
  }
  Type & set__mode(
    const bool & _arg)
  {
    this->mode = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tangerbot_msgs::srv::SetFollowMode_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const tangerbot_msgs::srv::SetFollowMode_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tangerbot_msgs::srv::SetFollowMode_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tangerbot_msgs::srv::SetFollowMode_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tangerbot_msgs::srv::SetFollowMode_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tangerbot_msgs::srv::SetFollowMode_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tangerbot_msgs::srv::SetFollowMode_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tangerbot_msgs::srv::SetFollowMode_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tangerbot_msgs::srv::SetFollowMode_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tangerbot_msgs::srv::SetFollowMode_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tangerbot_msgs__srv__SetFollowMode_Request
    std::shared_ptr<tangerbot_msgs::srv::SetFollowMode_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tangerbot_msgs__srv__SetFollowMode_Request
    std::shared_ptr<tangerbot_msgs::srv::SetFollowMode_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetFollowMode_Request_ & other) const
  {
    if (this->robot_id != other.robot_id) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetFollowMode_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetFollowMode_Request_

// alias to use template instance with default allocator
using SetFollowMode_Request =
  tangerbot_msgs::srv::SetFollowMode_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tangerbot_msgs


#ifndef _WIN32
# define DEPRECATED__tangerbot_msgs__srv__SetFollowMode_Response __attribute__((deprecated))
#else
# define DEPRECATED__tangerbot_msgs__srv__SetFollowMode_Response __declspec(deprecated)
#endif

namespace tangerbot_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetFollowMode_Response_
{
  using Type = SetFollowMode_Response_<ContainerAllocator>;

  explicit SetFollowMode_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit SetFollowMode_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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

  // pointer types
  using RawPtr =
    tangerbot_msgs::srv::SetFollowMode_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const tangerbot_msgs::srv::SetFollowMode_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tangerbot_msgs::srv::SetFollowMode_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tangerbot_msgs::srv::SetFollowMode_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tangerbot_msgs::srv::SetFollowMode_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tangerbot_msgs::srv::SetFollowMode_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tangerbot_msgs::srv::SetFollowMode_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tangerbot_msgs::srv::SetFollowMode_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tangerbot_msgs::srv::SetFollowMode_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tangerbot_msgs::srv::SetFollowMode_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tangerbot_msgs__srv__SetFollowMode_Response
    std::shared_ptr<tangerbot_msgs::srv::SetFollowMode_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tangerbot_msgs__srv__SetFollowMode_Response
    std::shared_ptr<tangerbot_msgs::srv::SetFollowMode_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetFollowMode_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetFollowMode_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetFollowMode_Response_

// alias to use template instance with default allocator
using SetFollowMode_Response =
  tangerbot_msgs::srv::SetFollowMode_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tangerbot_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tangerbot_msgs__srv__SetFollowMode_Event __attribute__((deprecated))
#else
# define DEPRECATED__tangerbot_msgs__srv__SetFollowMode_Event __declspec(deprecated)
#endif

namespace tangerbot_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetFollowMode_Event_
{
  using Type = SetFollowMode_Event_<ContainerAllocator>;

  explicit SetFollowMode_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit SetFollowMode_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<tangerbot_msgs::srv::SetFollowMode_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tangerbot_msgs::srv::SetFollowMode_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<tangerbot_msgs::srv::SetFollowMode_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tangerbot_msgs::srv::SetFollowMode_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<tangerbot_msgs::srv::SetFollowMode_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tangerbot_msgs::srv::SetFollowMode_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<tangerbot_msgs::srv::SetFollowMode_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<tangerbot_msgs::srv::SetFollowMode_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tangerbot_msgs::srv::SetFollowMode_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const tangerbot_msgs::srv::SetFollowMode_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tangerbot_msgs::srv::SetFollowMode_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tangerbot_msgs::srv::SetFollowMode_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tangerbot_msgs::srv::SetFollowMode_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tangerbot_msgs::srv::SetFollowMode_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tangerbot_msgs::srv::SetFollowMode_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tangerbot_msgs::srv::SetFollowMode_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tangerbot_msgs::srv::SetFollowMode_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tangerbot_msgs::srv::SetFollowMode_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tangerbot_msgs__srv__SetFollowMode_Event
    std::shared_ptr<tangerbot_msgs::srv::SetFollowMode_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tangerbot_msgs__srv__SetFollowMode_Event
    std::shared_ptr<tangerbot_msgs::srv::SetFollowMode_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetFollowMode_Event_ & other) const
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
  bool operator!=(const SetFollowMode_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetFollowMode_Event_

// alias to use template instance with default allocator
using SetFollowMode_Event =
  tangerbot_msgs::srv::SetFollowMode_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tangerbot_msgs

namespace tangerbot_msgs
{

namespace srv
{

struct SetFollowMode
{
  using Request = tangerbot_msgs::srv::SetFollowMode_Request;
  using Response = tangerbot_msgs::srv::SetFollowMode_Response;
  using Event = tangerbot_msgs::srv::SetFollowMode_Event;
};

}  // namespace srv

}  // namespace tangerbot_msgs

#endif  // TANGERBOT_MSGS__SRV__DETAIL__SET_FOLLOW_MODE__STRUCT_HPP_
