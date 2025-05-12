// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from tangerbot_msgs:srv/PathPlanning.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "tangerbot_msgs/srv/detail/path_planning__functions.h"
#include "tangerbot_msgs/srv/detail/path_planning__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace tangerbot_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void PathPlanning_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tangerbot_msgs::srv::PathPlanning_Request(_init);
}

void PathPlanning_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tangerbot_msgs::srv::PathPlanning_Request *>(message_memory);
  typed_message->~PathPlanning_Request();
}

size_t size_function__PathPlanning_Request__robot_id(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PathPlanning_Request__robot_id(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__PathPlanning_Request__robot_id(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__PathPlanning_Request__robot_id(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__PathPlanning_Request__robot_id(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__PathPlanning_Request__robot_id(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__PathPlanning_Request__robot_id(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__PathPlanning_Request__robot_id(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__PathPlanning_Request__end(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int8_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PathPlanning_Request__end(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int8_t> *>(untyped_member);
  return &member[index];
}

void * get_function__PathPlanning_Request__end(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int8_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__PathPlanning_Request__end(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int8_t *>(
    get_const_function__PathPlanning_Request__end(untyped_member, index));
  auto & value = *reinterpret_cast<int8_t *>(untyped_value);
  value = item;
}

void assign_function__PathPlanning_Request__end(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int8_t *>(
    get_function__PathPlanning_Request__end(untyped_member, index));
  const auto & value = *reinterpret_cast<const int8_t *>(untyped_value);
  item = value;
}

void resize_function__PathPlanning_Request__end(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int8_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PathPlanning_Request_message_member_array[2] = {
  {
    "robot_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs::srv::PathPlanning_Request, robot_id),  // bytes offset in struct
    nullptr,  // default value
    size_function__PathPlanning_Request__robot_id,  // size() function pointer
    get_const_function__PathPlanning_Request__robot_id,  // get_const(index) function pointer
    get_function__PathPlanning_Request__robot_id,  // get(index) function pointer
    fetch_function__PathPlanning_Request__robot_id,  // fetch(index, &value) function pointer
    assign_function__PathPlanning_Request__robot_id,  // assign(index, value) function pointer
    resize_function__PathPlanning_Request__robot_id  // resize(index) function pointer
  },
  {
    "end",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs::srv::PathPlanning_Request, end),  // bytes offset in struct
    nullptr,  // default value
    size_function__PathPlanning_Request__end,  // size() function pointer
    get_const_function__PathPlanning_Request__end,  // get_const(index) function pointer
    get_function__PathPlanning_Request__end,  // get(index) function pointer
    fetch_function__PathPlanning_Request__end,  // fetch(index, &value) function pointer
    assign_function__PathPlanning_Request__end,  // assign(index, value) function pointer
    resize_function__PathPlanning_Request__end  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PathPlanning_Request_message_members = {
  "tangerbot_msgs::srv",  // message namespace
  "PathPlanning_Request",  // message name
  2,  // number of fields
  sizeof(tangerbot_msgs::srv::PathPlanning_Request),
  false,  // has_any_key_member_
  PathPlanning_Request_message_member_array,  // message members
  PathPlanning_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  PathPlanning_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PathPlanning_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PathPlanning_Request_message_members,
  get_message_typesupport_handle_function,
  &tangerbot_msgs__srv__PathPlanning_Request__get_type_hash,
  &tangerbot_msgs__srv__PathPlanning_Request__get_type_description,
  &tangerbot_msgs__srv__PathPlanning_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace tangerbot_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tangerbot_msgs::srv::PathPlanning_Request>()
{
  return &::tangerbot_msgs::srv::rosidl_typesupport_introspection_cpp::PathPlanning_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tangerbot_msgs, srv, PathPlanning_Request)() {
  return &::tangerbot_msgs::srv::rosidl_typesupport_introspection_cpp::PathPlanning_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "tangerbot_msgs/srv/detail/path_planning__functions.h"
// already included above
// #include "tangerbot_msgs/srv/detail/path_planning__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace tangerbot_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void PathPlanning_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tangerbot_msgs::srv::PathPlanning_Response(_init);
}

void PathPlanning_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tangerbot_msgs::srv::PathPlanning_Response *>(message_memory);
  typed_message->~PathPlanning_Response();
}

size_t size_function__PathPlanning_Response__robot_id(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PathPlanning_Response__robot_id(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__PathPlanning_Response__robot_id(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__PathPlanning_Response__robot_id(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__PathPlanning_Response__robot_id(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__PathPlanning_Response__robot_id(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__PathPlanning_Response__robot_id(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__PathPlanning_Response__robot_id(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__PathPlanning_Response__waypoints(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PathPlanning_Response__waypoints(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__PathPlanning_Response__waypoints(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__PathPlanning_Response__waypoints(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__PathPlanning_Response__waypoints(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__PathPlanning_Response__waypoints(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__PathPlanning_Response__waypoints(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__PathPlanning_Response__waypoints(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__PathPlanning_Response__distance(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PathPlanning_Response__distance(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__PathPlanning_Response__distance(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__PathPlanning_Response__distance(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__PathPlanning_Response__distance(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__PathPlanning_Response__distance(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__PathPlanning_Response__distance(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__PathPlanning_Response__distance(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PathPlanning_Response_message_member_array[3] = {
  {
    "robot_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs::srv::PathPlanning_Response, robot_id),  // bytes offset in struct
    nullptr,  // default value
    size_function__PathPlanning_Response__robot_id,  // size() function pointer
    get_const_function__PathPlanning_Response__robot_id,  // get_const(index) function pointer
    get_function__PathPlanning_Response__robot_id,  // get(index) function pointer
    fetch_function__PathPlanning_Response__robot_id,  // fetch(index, &value) function pointer
    assign_function__PathPlanning_Response__robot_id,  // assign(index, value) function pointer
    resize_function__PathPlanning_Response__robot_id  // resize(index) function pointer
  },
  {
    "waypoints",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs::srv::PathPlanning_Response, waypoints),  // bytes offset in struct
    nullptr,  // default value
    size_function__PathPlanning_Response__waypoints,  // size() function pointer
    get_const_function__PathPlanning_Response__waypoints,  // get_const(index) function pointer
    get_function__PathPlanning_Response__waypoints,  // get(index) function pointer
    fetch_function__PathPlanning_Response__waypoints,  // fetch(index, &value) function pointer
    assign_function__PathPlanning_Response__waypoints,  // assign(index, value) function pointer
    resize_function__PathPlanning_Response__waypoints  // resize(index) function pointer
  },
  {
    "distance",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs::srv::PathPlanning_Response, distance),  // bytes offset in struct
    nullptr,  // default value
    size_function__PathPlanning_Response__distance,  // size() function pointer
    get_const_function__PathPlanning_Response__distance,  // get_const(index) function pointer
    get_function__PathPlanning_Response__distance,  // get(index) function pointer
    fetch_function__PathPlanning_Response__distance,  // fetch(index, &value) function pointer
    assign_function__PathPlanning_Response__distance,  // assign(index, value) function pointer
    resize_function__PathPlanning_Response__distance  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PathPlanning_Response_message_members = {
  "tangerbot_msgs::srv",  // message namespace
  "PathPlanning_Response",  // message name
  3,  // number of fields
  sizeof(tangerbot_msgs::srv::PathPlanning_Response),
  false,  // has_any_key_member_
  PathPlanning_Response_message_member_array,  // message members
  PathPlanning_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  PathPlanning_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PathPlanning_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PathPlanning_Response_message_members,
  get_message_typesupport_handle_function,
  &tangerbot_msgs__srv__PathPlanning_Response__get_type_hash,
  &tangerbot_msgs__srv__PathPlanning_Response__get_type_description,
  &tangerbot_msgs__srv__PathPlanning_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace tangerbot_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tangerbot_msgs::srv::PathPlanning_Response>()
{
  return &::tangerbot_msgs::srv::rosidl_typesupport_introspection_cpp::PathPlanning_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tangerbot_msgs, srv, PathPlanning_Response)() {
  return &::tangerbot_msgs::srv::rosidl_typesupport_introspection_cpp::PathPlanning_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "tangerbot_msgs/srv/detail/path_planning__functions.h"
// already included above
// #include "tangerbot_msgs/srv/detail/path_planning__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace tangerbot_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void PathPlanning_Event_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tangerbot_msgs::srv::PathPlanning_Event(_init);
}

void PathPlanning_Event_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tangerbot_msgs::srv::PathPlanning_Event *>(message_memory);
  typed_message->~PathPlanning_Event();
}

size_t size_function__PathPlanning_Event__request(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<tangerbot_msgs::srv::PathPlanning_Request> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PathPlanning_Event__request(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<tangerbot_msgs::srv::PathPlanning_Request> *>(untyped_member);
  return &member[index];
}

void * get_function__PathPlanning_Event__request(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<tangerbot_msgs::srv::PathPlanning_Request> *>(untyped_member);
  return &member[index];
}

void fetch_function__PathPlanning_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const tangerbot_msgs::srv::PathPlanning_Request *>(
    get_const_function__PathPlanning_Event__request(untyped_member, index));
  auto & value = *reinterpret_cast<tangerbot_msgs::srv::PathPlanning_Request *>(untyped_value);
  value = item;
}

void assign_function__PathPlanning_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<tangerbot_msgs::srv::PathPlanning_Request *>(
    get_function__PathPlanning_Event__request(untyped_member, index));
  const auto & value = *reinterpret_cast<const tangerbot_msgs::srv::PathPlanning_Request *>(untyped_value);
  item = value;
}

void resize_function__PathPlanning_Event__request(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<tangerbot_msgs::srv::PathPlanning_Request> *>(untyped_member);
  member->resize(size);
}

size_t size_function__PathPlanning_Event__response(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<tangerbot_msgs::srv::PathPlanning_Response> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PathPlanning_Event__response(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<tangerbot_msgs::srv::PathPlanning_Response> *>(untyped_member);
  return &member[index];
}

void * get_function__PathPlanning_Event__response(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<tangerbot_msgs::srv::PathPlanning_Response> *>(untyped_member);
  return &member[index];
}

void fetch_function__PathPlanning_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const tangerbot_msgs::srv::PathPlanning_Response *>(
    get_const_function__PathPlanning_Event__response(untyped_member, index));
  auto & value = *reinterpret_cast<tangerbot_msgs::srv::PathPlanning_Response *>(untyped_value);
  value = item;
}

void assign_function__PathPlanning_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<tangerbot_msgs::srv::PathPlanning_Response *>(
    get_function__PathPlanning_Event__response(untyped_member, index));
  const auto & value = *reinterpret_cast<const tangerbot_msgs::srv::PathPlanning_Response *>(untyped_value);
  item = value;
}

void resize_function__PathPlanning_Event__response(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<tangerbot_msgs::srv::PathPlanning_Response> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PathPlanning_Event_message_member_array[3] = {
  {
    "info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<service_msgs::msg::ServiceEventInfo>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs::srv::PathPlanning_Event, info),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "request",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tangerbot_msgs::srv::PathPlanning_Request>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(tangerbot_msgs::srv::PathPlanning_Event, request),  // bytes offset in struct
    nullptr,  // default value
    size_function__PathPlanning_Event__request,  // size() function pointer
    get_const_function__PathPlanning_Event__request,  // get_const(index) function pointer
    get_function__PathPlanning_Event__request,  // get(index) function pointer
    fetch_function__PathPlanning_Event__request,  // fetch(index, &value) function pointer
    assign_function__PathPlanning_Event__request,  // assign(index, value) function pointer
    resize_function__PathPlanning_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tangerbot_msgs::srv::PathPlanning_Response>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(tangerbot_msgs::srv::PathPlanning_Event, response),  // bytes offset in struct
    nullptr,  // default value
    size_function__PathPlanning_Event__response,  // size() function pointer
    get_const_function__PathPlanning_Event__response,  // get_const(index) function pointer
    get_function__PathPlanning_Event__response,  // get(index) function pointer
    fetch_function__PathPlanning_Event__response,  // fetch(index, &value) function pointer
    assign_function__PathPlanning_Event__response,  // assign(index, value) function pointer
    resize_function__PathPlanning_Event__response  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PathPlanning_Event_message_members = {
  "tangerbot_msgs::srv",  // message namespace
  "PathPlanning_Event",  // message name
  3,  // number of fields
  sizeof(tangerbot_msgs::srv::PathPlanning_Event),
  false,  // has_any_key_member_
  PathPlanning_Event_message_member_array,  // message members
  PathPlanning_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  PathPlanning_Event_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PathPlanning_Event_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PathPlanning_Event_message_members,
  get_message_typesupport_handle_function,
  &tangerbot_msgs__srv__PathPlanning_Event__get_type_hash,
  &tangerbot_msgs__srv__PathPlanning_Event__get_type_description,
  &tangerbot_msgs__srv__PathPlanning_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace tangerbot_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tangerbot_msgs::srv::PathPlanning_Event>()
{
  return &::tangerbot_msgs::srv::rosidl_typesupport_introspection_cpp::PathPlanning_Event_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tangerbot_msgs, srv, PathPlanning_Event)() {
  return &::tangerbot_msgs::srv::rosidl_typesupport_introspection_cpp::PathPlanning_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "tangerbot_msgs/srv/detail/path_planning__functions.h"
// already included above
// #include "tangerbot_msgs/srv/detail/path_planning__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace tangerbot_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers PathPlanning_service_members = {
  "tangerbot_msgs::srv",  // service namespace
  "PathPlanning",  // service name
  // the following fields are initialized below on first access
  // see get_service_type_support_handle<tangerbot_msgs::srv::PathPlanning>()
  nullptr,  // request message
  nullptr,  // response message
  nullptr,  // event message
};

static const rosidl_service_type_support_t PathPlanning_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PathPlanning_service_members,
  get_service_typesupport_handle_function,
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tangerbot_msgs::srv::PathPlanning_Request>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tangerbot_msgs::srv::PathPlanning_Response>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<tangerbot_msgs::srv::PathPlanning_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<tangerbot_msgs::srv::PathPlanning>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<tangerbot_msgs::srv::PathPlanning>,
  &tangerbot_msgs__srv__PathPlanning__get_type_hash,
  &tangerbot_msgs__srv__PathPlanning__get_type_description,
  &tangerbot_msgs__srv__PathPlanning__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace tangerbot_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<tangerbot_msgs::srv::PathPlanning>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::tangerbot_msgs::srv::rosidl_typesupport_introspection_cpp::PathPlanning_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure all of the service_members are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr ||
    service_members->event_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::tangerbot_msgs::srv::PathPlanning_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::tangerbot_msgs::srv::PathPlanning_Response
      >()->data
      );
    // initialize the event_members_ with the static function from the external library
    service_members->event_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::tangerbot_msgs::srv::PathPlanning_Event
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tangerbot_msgs, srv, PathPlanning)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<tangerbot_msgs::srv::PathPlanning>();
}

#ifdef __cplusplus
}
#endif
