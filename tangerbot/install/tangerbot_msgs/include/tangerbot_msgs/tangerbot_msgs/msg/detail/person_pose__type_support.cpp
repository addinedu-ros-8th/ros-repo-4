// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from tangerbot_msgs:msg/PersonPose.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "tangerbot_msgs/msg/detail/person_pose__functions.h"
#include "tangerbot_msgs/msg/detail/person_pose__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace tangerbot_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void PersonPose_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) tangerbot_msgs::msg::PersonPose(_init);
}

void PersonPose_fini_function(void * message_memory)
{
  auto typed_message = static_cast<tangerbot_msgs::msg::PersonPose *>(message_memory);
  typed_message->~PersonPose();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PersonPose_message_member_array[2] = {
  {
    "robot_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs::msg::PersonPose, robot_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pose",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs::msg::PersonPose, pose),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PersonPose_message_members = {
  "tangerbot_msgs::msg",  // message namespace
  "PersonPose",  // message name
  2,  // number of fields
  sizeof(tangerbot_msgs::msg::PersonPose),
  false,  // has_any_key_member_
  PersonPose_message_member_array,  // message members
  PersonPose_init_function,  // function to initialize message memory (memory has to be allocated)
  PersonPose_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PersonPose_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PersonPose_message_members,
  get_message_typesupport_handle_function,
  &tangerbot_msgs__msg__PersonPose__get_type_hash,
  &tangerbot_msgs__msg__PersonPose__get_type_description,
  &tangerbot_msgs__msg__PersonPose__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace tangerbot_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<tangerbot_msgs::msg::PersonPose>()
{
  return &::tangerbot_msgs::msg::rosidl_typesupport_introspection_cpp::PersonPose_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, tangerbot_msgs, msg, PersonPose)() {
  return &::tangerbot_msgs::msg::rosidl_typesupport_introspection_cpp::PersonPose_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
