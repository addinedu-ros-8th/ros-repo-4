// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tangerbot_msgs:msg/LocalMap.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tangerbot_msgs/msg/detail/local_map__rosidl_typesupport_introspection_c.h"
#include "tangerbot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tangerbot_msgs/msg/detail/local_map__functions.h"
#include "tangerbot_msgs/msg/detail/local_map__struct.h"


// Include directives for member types
// Member `robot_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__LocalMap_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tangerbot_msgs__msg__LocalMap__init(message_memory);
}

void tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__LocalMap_fini_function(void * message_memory)
{
  tangerbot_msgs__msg__LocalMap__fini(message_memory);
}

size_t tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__size_function__LocalMap__data(
  const void * untyped_member)
{
  const rosidl_runtime_c__int8__Sequence * member =
    (const rosidl_runtime_c__int8__Sequence *)(untyped_member);
  return member->size;
}

const void * tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__get_const_function__LocalMap__data(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int8__Sequence * member =
    (const rosidl_runtime_c__int8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__get_function__LocalMap__data(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int8__Sequence * member =
    (rosidl_runtime_c__int8__Sequence *)(untyped_member);
  return &member->data[index];
}

void tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__fetch_function__LocalMap__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int8_t * item =
    ((const int8_t *)
    tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__get_const_function__LocalMap__data(untyped_member, index));
  int8_t * value =
    (int8_t *)(untyped_value);
  *value = *item;
}

void tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__assign_function__LocalMap__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int8_t * item =
    ((int8_t *)
    tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__get_function__LocalMap__data(untyped_member, index));
  const int8_t * value =
    (const int8_t *)(untyped_value);
  *item = *value;
}

bool tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__resize_function__LocalMap__data(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int8__Sequence * member =
    (rosidl_runtime_c__int8__Sequence *)(untyped_member);
  rosidl_runtime_c__int8__Sequence__fini(member);
  return rosidl_runtime_c__int8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__LocalMap_message_member_array[8] = {
  {
    "robot_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs__msg__LocalMap, robot_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs__msg__LocalMap, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "resolution",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs__msg__LocalMap, resolution),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "width",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs__msg__LocalMap, width),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "height",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs__msg__LocalMap, height),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "origin_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs__msg__LocalMap, origin_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "origin_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs__msg__LocalMap, origin_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs__msg__LocalMap, data),  // bytes offset in struct
    NULL,  // default value
    tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__size_function__LocalMap__data,  // size() function pointer
    tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__get_const_function__LocalMap__data,  // get_const(index) function pointer
    tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__get_function__LocalMap__data,  // get(index) function pointer
    tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__fetch_function__LocalMap__data,  // fetch(index, &value) function pointer
    tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__assign_function__LocalMap__data,  // assign(index, value) function pointer
    tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__resize_function__LocalMap__data  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__LocalMap_message_members = {
  "tangerbot_msgs__msg",  // message namespace
  "LocalMap",  // message name
  8,  // number of fields
  sizeof(tangerbot_msgs__msg__LocalMap),
  false,  // has_any_key_member_
  tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__LocalMap_message_member_array,  // message members
  tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__LocalMap_init_function,  // function to initialize message memory (memory has to be allocated)
  tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__LocalMap_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__LocalMap_message_type_support_handle = {
  0,
  &tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__LocalMap_message_members,
  get_message_typesupport_handle_function,
  &tangerbot_msgs__msg__LocalMap__get_type_hash,
  &tangerbot_msgs__msg__LocalMap__get_type_description,
  &tangerbot_msgs__msg__LocalMap__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tangerbot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tangerbot_msgs, msg, LocalMap)() {
  tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__LocalMap_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__LocalMap_message_type_support_handle.typesupport_identifier) {
    tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__LocalMap_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tangerbot_msgs__msg__LocalMap__rosidl_typesupport_introspection_c__LocalMap_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
