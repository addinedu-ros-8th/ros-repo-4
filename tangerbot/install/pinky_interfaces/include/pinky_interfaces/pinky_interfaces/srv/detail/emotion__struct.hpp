// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pinky_interfaces:srv/Emotion.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pinky_interfaces/srv/emotion.hpp"


#ifndef PINKY_INTERFACES__SRV__DETAIL__EMOTION__STRUCT_HPP_
#define PINKY_INTERFACES__SRV__DETAIL__EMOTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__pinky_interfaces__srv__Emotion_Request __attribute__((deprecated))
#else
# define DEPRECATED__pinky_interfaces__srv__Emotion_Request __declspec(deprecated)
#endif

namespace pinky_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Emotion_Request_
{
  using Type = Emotion_Request_<ContainerAllocator>;

  explicit Emotion_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->emotion = "";
    }
  }

  explicit Emotion_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : emotion(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->emotion = "";
    }
  }

  // field types and members
  using _emotion_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _emotion_type emotion;

  // setters for named parameter idiom
  Type & set__emotion(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->emotion = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pinky_interfaces::srv::Emotion_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const pinky_interfaces::srv::Emotion_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pinky_interfaces::srv::Emotion_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pinky_interfaces::srv::Emotion_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pinky_interfaces::srv::Emotion_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pinky_interfaces::srv::Emotion_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pinky_interfaces::srv::Emotion_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pinky_interfaces::srv::Emotion_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pinky_interfaces::srv::Emotion_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pinky_interfaces::srv::Emotion_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pinky_interfaces__srv__Emotion_Request
    std::shared_ptr<pinky_interfaces::srv::Emotion_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pinky_interfaces__srv__Emotion_Request
    std::shared_ptr<pinky_interfaces::srv::Emotion_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Emotion_Request_ & other) const
  {
    if (this->emotion != other.emotion) {
      return false;
    }
    return true;
  }
  bool operator!=(const Emotion_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Emotion_Request_

// alias to use template instance with default allocator
using Emotion_Request =
  pinky_interfaces::srv::Emotion_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace pinky_interfaces


#ifndef _WIN32
# define DEPRECATED__pinky_interfaces__srv__Emotion_Response __attribute__((deprecated))
#else
# define DEPRECATED__pinky_interfaces__srv__Emotion_Response __declspec(deprecated)
#endif

namespace pinky_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Emotion_Response_
{
  using Type = Emotion_Response_<ContainerAllocator>;

  explicit Emotion_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response = "";
    }
  }

  explicit Emotion_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : response(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response = "";
    }
  }

  // field types and members
  using _response_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__response(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pinky_interfaces::srv::Emotion_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const pinky_interfaces::srv::Emotion_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pinky_interfaces::srv::Emotion_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pinky_interfaces::srv::Emotion_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pinky_interfaces::srv::Emotion_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pinky_interfaces::srv::Emotion_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pinky_interfaces::srv::Emotion_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pinky_interfaces::srv::Emotion_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pinky_interfaces::srv::Emotion_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pinky_interfaces::srv::Emotion_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pinky_interfaces__srv__Emotion_Response
    std::shared_ptr<pinky_interfaces::srv::Emotion_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pinky_interfaces__srv__Emotion_Response
    std::shared_ptr<pinky_interfaces::srv::Emotion_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Emotion_Response_ & other) const
  {
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const Emotion_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Emotion_Response_

// alias to use template instance with default allocator
using Emotion_Response =
  pinky_interfaces::srv::Emotion_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace pinky_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pinky_interfaces__srv__Emotion_Event __attribute__((deprecated))
#else
# define DEPRECATED__pinky_interfaces__srv__Emotion_Event __declspec(deprecated)
#endif

namespace pinky_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Emotion_Event_
{
  using Type = Emotion_Event_<ContainerAllocator>;

  explicit Emotion_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit Emotion_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<pinky_interfaces::srv::Emotion_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<pinky_interfaces::srv::Emotion_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<pinky_interfaces::srv::Emotion_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<pinky_interfaces::srv::Emotion_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<pinky_interfaces::srv::Emotion_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<pinky_interfaces::srv::Emotion_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<pinky_interfaces::srv::Emotion_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<pinky_interfaces::srv::Emotion_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pinky_interfaces::srv::Emotion_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const pinky_interfaces::srv::Emotion_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pinky_interfaces::srv::Emotion_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pinky_interfaces::srv::Emotion_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pinky_interfaces::srv::Emotion_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pinky_interfaces::srv::Emotion_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pinky_interfaces::srv::Emotion_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pinky_interfaces::srv::Emotion_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pinky_interfaces::srv::Emotion_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pinky_interfaces::srv::Emotion_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pinky_interfaces__srv__Emotion_Event
    std::shared_ptr<pinky_interfaces::srv::Emotion_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pinky_interfaces__srv__Emotion_Event
    std::shared_ptr<pinky_interfaces::srv::Emotion_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Emotion_Event_ & other) const
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
  bool operator!=(const Emotion_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Emotion_Event_

// alias to use template instance with default allocator
using Emotion_Event =
  pinky_interfaces::srv::Emotion_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace pinky_interfaces

namespace pinky_interfaces
{

namespace srv
{

struct Emotion
{
  using Request = pinky_interfaces::srv::Emotion_Request;
  using Response = pinky_interfaces::srv::Emotion_Response;
  using Event = pinky_interfaces::srv::Emotion_Event;
};

}  // namespace srv

}  // namespace pinky_interfaces

#endif  // PINKY_INTERFACES__SRV__DETAIL__EMOTION__STRUCT_HPP_
