// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tangerbot_msgs:srv/PathPlanning.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tangerbot_msgs/srv/detail/path_planning__rosidl_typesupport_introspection_c.h"
#include "tangerbot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tangerbot_msgs/srv/detail/path_planning__functions.h"
#include "tangerbot_msgs/srv/detail/path_planning__struct.h"


// Include directives for member types
// Member `robot_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `end`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__PathPlanning_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tangerbot_msgs__srv__PathPlanning_Request__init(message_memory);
}

void tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__PathPlanning_Request_fini_function(void * message_memory)
{
  tangerbot_msgs__srv__PathPlanning_Request__fini(message_memory);
}

size_t tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__size_function__PathPlanning_Request__robot_id(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Request__robot_id(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__get_function__PathPlanning_Request__robot_id(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__fetch_function__PathPlanning_Request__robot_id(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Request__robot_id(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__assign_function__PathPlanning_Request__robot_id(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__get_function__PathPlanning_Request__robot_id(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__resize_function__PathPlanning_Request__robot_id(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__size_function__PathPlanning_Request__end(
  const void * untyped_member)
{
  const rosidl_runtime_c__int8__Sequence * member =
    (const rosidl_runtime_c__int8__Sequence *)(untyped_member);
  return member->size;
}

const void * tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Request__end(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int8__Sequence * member =
    (const rosidl_runtime_c__int8__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__get_function__PathPlanning_Request__end(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int8__Sequence * member =
    (rosidl_runtime_c__int8__Sequence *)(untyped_member);
  return &member->data[index];
}

void tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__fetch_function__PathPlanning_Request__end(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int8_t * item =
    ((const int8_t *)
    tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Request__end(untyped_member, index));
  int8_t * value =
    (int8_t *)(untyped_value);
  *value = *item;
}

void tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__assign_function__PathPlanning_Request__end(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int8_t * item =
    ((int8_t *)
    tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__get_function__PathPlanning_Request__end(untyped_member, index));
  const int8_t * value =
    (const int8_t *)(untyped_value);
  *item = *value;
}

bool tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__resize_function__PathPlanning_Request__end(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int8__Sequence * member =
    (rosidl_runtime_c__int8__Sequence *)(untyped_member);
  rosidl_runtime_c__int8__Sequence__fini(member);
  return rosidl_runtime_c__int8__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__PathPlanning_Request_message_member_array[2] = {
  {
    "robot_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs__srv__PathPlanning_Request, robot_id),  // bytes offset in struct
    NULL,  // default value
    tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__size_function__PathPlanning_Request__robot_id,  // size() function pointer
    tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Request__robot_id,  // get_const(index) function pointer
    tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__get_function__PathPlanning_Request__robot_id,  // get(index) function pointer
    tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__fetch_function__PathPlanning_Request__robot_id,  // fetch(index, &value) function pointer
    tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__assign_function__PathPlanning_Request__robot_id,  // assign(index, value) function pointer
    tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__resize_function__PathPlanning_Request__robot_id  // resize(index) function pointer
  },
  {
    "end",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs__srv__PathPlanning_Request, end),  // bytes offset in struct
    NULL,  // default value
    tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__size_function__PathPlanning_Request__end,  // size() function pointer
    tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Request__end,  // get_const(index) function pointer
    tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__get_function__PathPlanning_Request__end,  // get(index) function pointer
    tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__fetch_function__PathPlanning_Request__end,  // fetch(index, &value) function pointer
    tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__assign_function__PathPlanning_Request__end,  // assign(index, value) function pointer
    tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__resize_function__PathPlanning_Request__end  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__PathPlanning_Request_message_members = {
  "tangerbot_msgs__srv",  // message namespace
  "PathPlanning_Request",  // message name
  2,  // number of fields
  sizeof(tangerbot_msgs__srv__PathPlanning_Request),
  false,  // has_any_key_member_
  tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__PathPlanning_Request_message_member_array,  // message members
  tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__PathPlanning_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__PathPlanning_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__PathPlanning_Request_message_type_support_handle = {
  0,
  &tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__PathPlanning_Request_message_members,
  get_message_typesupport_handle_function,
  &tangerbot_msgs__srv__PathPlanning_Request__get_type_hash,
  &tangerbot_msgs__srv__PathPlanning_Request__get_type_description,
  &tangerbot_msgs__srv__PathPlanning_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tangerbot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tangerbot_msgs, srv, PathPlanning_Request)() {
  if (!tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__PathPlanning_Request_message_type_support_handle.typesupport_identifier) {
    tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__PathPlanning_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__PathPlanning_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "tangerbot_msgs/srv/detail/path_planning__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tangerbot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tangerbot_msgs/srv/detail/path_planning__functions.h"
// already included above
// #include "tangerbot_msgs/srv/detail/path_planning__struct.h"


// Include directives for member types
// Member `robot_id`
// already included above
// #include "rosidl_runtime_c/string_functions.h"
// Member `waypoints`
#include "geometry_msgs/msg/point.h"
// Member `waypoints`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `distance`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__PathPlanning_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tangerbot_msgs__srv__PathPlanning_Response__init(message_memory);
}

void tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__PathPlanning_Response_fini_function(void * message_memory)
{
  tangerbot_msgs__srv__PathPlanning_Response__fini(message_memory);
}

size_t tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__size_function__PathPlanning_Response__robot_id(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Response__robot_id(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__get_function__PathPlanning_Response__robot_id(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__fetch_function__PathPlanning_Response__robot_id(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Response__robot_id(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__assign_function__PathPlanning_Response__robot_id(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__get_function__PathPlanning_Response__robot_id(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__resize_function__PathPlanning_Response__robot_id(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__size_function__PathPlanning_Response__waypoints(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Response__waypoints(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__get_function__PathPlanning_Response__waypoints(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__fetch_function__PathPlanning_Response__waypoints(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Response__waypoints(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__assign_function__PathPlanning_Response__waypoints(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__get_function__PathPlanning_Response__waypoints(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__resize_function__PathPlanning_Response__waypoints(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__size_function__PathPlanning_Response__distance(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Response__distance(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__get_function__PathPlanning_Response__distance(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__fetch_function__PathPlanning_Response__distance(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Response__distance(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__assign_function__PathPlanning_Response__distance(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__get_function__PathPlanning_Response__distance(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__resize_function__PathPlanning_Response__distance(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__PathPlanning_Response_message_member_array[3] = {
  {
    "robot_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs__srv__PathPlanning_Response, robot_id),  // bytes offset in struct
    NULL,  // default value
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__size_function__PathPlanning_Response__robot_id,  // size() function pointer
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Response__robot_id,  // get_const(index) function pointer
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__get_function__PathPlanning_Response__robot_id,  // get(index) function pointer
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__fetch_function__PathPlanning_Response__robot_id,  // fetch(index, &value) function pointer
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__assign_function__PathPlanning_Response__robot_id,  // assign(index, value) function pointer
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__resize_function__PathPlanning_Response__robot_id  // resize(index) function pointer
  },
  {
    "waypoints",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs__srv__PathPlanning_Response, waypoints),  // bytes offset in struct
    NULL,  // default value
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__size_function__PathPlanning_Response__waypoints,  // size() function pointer
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Response__waypoints,  // get_const(index) function pointer
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__get_function__PathPlanning_Response__waypoints,  // get(index) function pointer
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__fetch_function__PathPlanning_Response__waypoints,  // fetch(index, &value) function pointer
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__assign_function__PathPlanning_Response__waypoints,  // assign(index, value) function pointer
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__resize_function__PathPlanning_Response__waypoints  // resize(index) function pointer
  },
  {
    "distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs__srv__PathPlanning_Response, distance),  // bytes offset in struct
    NULL,  // default value
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__size_function__PathPlanning_Response__distance,  // size() function pointer
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Response__distance,  // get_const(index) function pointer
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__get_function__PathPlanning_Response__distance,  // get(index) function pointer
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__fetch_function__PathPlanning_Response__distance,  // fetch(index, &value) function pointer
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__assign_function__PathPlanning_Response__distance,  // assign(index, value) function pointer
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__resize_function__PathPlanning_Response__distance  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__PathPlanning_Response_message_members = {
  "tangerbot_msgs__srv",  // message namespace
  "PathPlanning_Response",  // message name
  3,  // number of fields
  sizeof(tangerbot_msgs__srv__PathPlanning_Response),
  false,  // has_any_key_member_
  tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__PathPlanning_Response_message_member_array,  // message members
  tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__PathPlanning_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__PathPlanning_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__PathPlanning_Response_message_type_support_handle = {
  0,
  &tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__PathPlanning_Response_message_members,
  get_message_typesupport_handle_function,
  &tangerbot_msgs__srv__PathPlanning_Response__get_type_hash,
  &tangerbot_msgs__srv__PathPlanning_Response__get_type_description,
  &tangerbot_msgs__srv__PathPlanning_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tangerbot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tangerbot_msgs, srv, PathPlanning_Response)() {
  tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__PathPlanning_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__PathPlanning_Response_message_type_support_handle.typesupport_identifier) {
    tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__PathPlanning_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__PathPlanning_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "tangerbot_msgs/srv/detail/path_planning__rosidl_typesupport_introspection_c.h"
// already included above
// #include "tangerbot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "tangerbot_msgs/srv/detail/path_planning__functions.h"
// already included above
// #include "tangerbot_msgs/srv/detail/path_planning__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "tangerbot_msgs/srv/path_planning.h"
// Member `request`
// Member `response`
// already included above
// #include "tangerbot_msgs/srv/detail/path_planning__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__PathPlanning_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tangerbot_msgs__srv__PathPlanning_Event__init(message_memory);
}

void tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__PathPlanning_Event_fini_function(void * message_memory)
{
  tangerbot_msgs__srv__PathPlanning_Event__fini(message_memory);
}

size_t tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__size_function__PathPlanning_Event__request(
  const void * untyped_member)
{
  const tangerbot_msgs__srv__PathPlanning_Request__Sequence * member =
    (const tangerbot_msgs__srv__PathPlanning_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Event__request(
  const void * untyped_member, size_t index)
{
  const tangerbot_msgs__srv__PathPlanning_Request__Sequence * member =
    (const tangerbot_msgs__srv__PathPlanning_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__get_function__PathPlanning_Event__request(
  void * untyped_member, size_t index)
{
  tangerbot_msgs__srv__PathPlanning_Request__Sequence * member =
    (tangerbot_msgs__srv__PathPlanning_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__fetch_function__PathPlanning_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tangerbot_msgs__srv__PathPlanning_Request * item =
    ((const tangerbot_msgs__srv__PathPlanning_Request *)
    tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Event__request(untyped_member, index));
  tangerbot_msgs__srv__PathPlanning_Request * value =
    (tangerbot_msgs__srv__PathPlanning_Request *)(untyped_value);
  *value = *item;
}

void tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__assign_function__PathPlanning_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tangerbot_msgs__srv__PathPlanning_Request * item =
    ((tangerbot_msgs__srv__PathPlanning_Request *)
    tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__get_function__PathPlanning_Event__request(untyped_member, index));
  const tangerbot_msgs__srv__PathPlanning_Request * value =
    (const tangerbot_msgs__srv__PathPlanning_Request *)(untyped_value);
  *item = *value;
}

bool tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__resize_function__PathPlanning_Event__request(
  void * untyped_member, size_t size)
{
  tangerbot_msgs__srv__PathPlanning_Request__Sequence * member =
    (tangerbot_msgs__srv__PathPlanning_Request__Sequence *)(untyped_member);
  tangerbot_msgs__srv__PathPlanning_Request__Sequence__fini(member);
  return tangerbot_msgs__srv__PathPlanning_Request__Sequence__init(member, size);
}

size_t tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__size_function__PathPlanning_Event__response(
  const void * untyped_member)
{
  const tangerbot_msgs__srv__PathPlanning_Response__Sequence * member =
    (const tangerbot_msgs__srv__PathPlanning_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Event__response(
  const void * untyped_member, size_t index)
{
  const tangerbot_msgs__srv__PathPlanning_Response__Sequence * member =
    (const tangerbot_msgs__srv__PathPlanning_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__get_function__PathPlanning_Event__response(
  void * untyped_member, size_t index)
{
  tangerbot_msgs__srv__PathPlanning_Response__Sequence * member =
    (tangerbot_msgs__srv__PathPlanning_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__fetch_function__PathPlanning_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const tangerbot_msgs__srv__PathPlanning_Response * item =
    ((const tangerbot_msgs__srv__PathPlanning_Response *)
    tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Event__response(untyped_member, index));
  tangerbot_msgs__srv__PathPlanning_Response * value =
    (tangerbot_msgs__srv__PathPlanning_Response *)(untyped_value);
  *value = *item;
}

void tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__assign_function__PathPlanning_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  tangerbot_msgs__srv__PathPlanning_Response * item =
    ((tangerbot_msgs__srv__PathPlanning_Response *)
    tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__get_function__PathPlanning_Event__response(untyped_member, index));
  const tangerbot_msgs__srv__PathPlanning_Response * value =
    (const tangerbot_msgs__srv__PathPlanning_Response *)(untyped_value);
  *item = *value;
}

bool tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__resize_function__PathPlanning_Event__response(
  void * untyped_member, size_t size)
{
  tangerbot_msgs__srv__PathPlanning_Response__Sequence * member =
    (tangerbot_msgs__srv__PathPlanning_Response__Sequence *)(untyped_member);
  tangerbot_msgs__srv__PathPlanning_Response__Sequence__fini(member);
  return tangerbot_msgs__srv__PathPlanning_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__PathPlanning_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs__srv__PathPlanning_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(tangerbot_msgs__srv__PathPlanning_Event, request),  // bytes offset in struct
    NULL,  // default value
    tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__size_function__PathPlanning_Event__request,  // size() function pointer
    tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Event__request,  // get_const(index) function pointer
    tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__get_function__PathPlanning_Event__request,  // get(index) function pointer
    tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__fetch_function__PathPlanning_Event__request,  // fetch(index, &value) function pointer
    tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__assign_function__PathPlanning_Event__request,  // assign(index, value) function pointer
    tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__resize_function__PathPlanning_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(tangerbot_msgs__srv__PathPlanning_Event, response),  // bytes offset in struct
    NULL,  // default value
    tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__size_function__PathPlanning_Event__response,  // size() function pointer
    tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__get_const_function__PathPlanning_Event__response,  // get_const(index) function pointer
    tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__get_function__PathPlanning_Event__response,  // get(index) function pointer
    tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__fetch_function__PathPlanning_Event__response,  // fetch(index, &value) function pointer
    tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__assign_function__PathPlanning_Event__response,  // assign(index, value) function pointer
    tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__resize_function__PathPlanning_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__PathPlanning_Event_message_members = {
  "tangerbot_msgs__srv",  // message namespace
  "PathPlanning_Event",  // message name
  3,  // number of fields
  sizeof(tangerbot_msgs__srv__PathPlanning_Event),
  false,  // has_any_key_member_
  tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__PathPlanning_Event_message_member_array,  // message members
  tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__PathPlanning_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__PathPlanning_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__PathPlanning_Event_message_type_support_handle = {
  0,
  &tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__PathPlanning_Event_message_members,
  get_message_typesupport_handle_function,
  &tangerbot_msgs__srv__PathPlanning_Event__get_type_hash,
  &tangerbot_msgs__srv__PathPlanning_Event__get_type_description,
  &tangerbot_msgs__srv__PathPlanning_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tangerbot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tangerbot_msgs, srv, PathPlanning_Event)() {
  tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__PathPlanning_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__PathPlanning_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tangerbot_msgs, srv, PathPlanning_Request)();
  tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__PathPlanning_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tangerbot_msgs, srv, PathPlanning_Response)();
  if (!tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__PathPlanning_Event_message_type_support_handle.typesupport_identifier) {
    tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__PathPlanning_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__PathPlanning_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "tangerbot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "tangerbot_msgs/srv/detail/path_planning__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers tangerbot_msgs__srv__detail__path_planning__rosidl_typesupport_introspection_c__PathPlanning_service_members = {
  "tangerbot_msgs__srv",  // service namespace
  "PathPlanning",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // tangerbot_msgs__srv__detail__path_planning__rosidl_typesupport_introspection_c__PathPlanning_Request_message_type_support_handle,
  NULL,  // response message
  // tangerbot_msgs__srv__detail__path_planning__rosidl_typesupport_introspection_c__PathPlanning_Response_message_type_support_handle
  NULL  // event_message
  // tangerbot_msgs__srv__detail__path_planning__rosidl_typesupport_introspection_c__PathPlanning_Response_message_type_support_handle
};


static rosidl_service_type_support_t tangerbot_msgs__srv__detail__path_planning__rosidl_typesupport_introspection_c__PathPlanning_service_type_support_handle = {
  0,
  &tangerbot_msgs__srv__detail__path_planning__rosidl_typesupport_introspection_c__PathPlanning_service_members,
  get_service_typesupport_handle_function,
  &tangerbot_msgs__srv__PathPlanning_Request__rosidl_typesupport_introspection_c__PathPlanning_Request_message_type_support_handle,
  &tangerbot_msgs__srv__PathPlanning_Response__rosidl_typesupport_introspection_c__PathPlanning_Response_message_type_support_handle,
  &tangerbot_msgs__srv__PathPlanning_Event__rosidl_typesupport_introspection_c__PathPlanning_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    tangerbot_msgs,
    srv,
    PathPlanning
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    tangerbot_msgs,
    srv,
    PathPlanning
  ),
  &tangerbot_msgs__srv__PathPlanning__get_type_hash,
  &tangerbot_msgs__srv__PathPlanning__get_type_description,
  &tangerbot_msgs__srv__PathPlanning__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tangerbot_msgs, srv, PathPlanning_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tangerbot_msgs, srv, PathPlanning_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tangerbot_msgs, srv, PathPlanning_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tangerbot_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tangerbot_msgs, srv, PathPlanning)(void) {
  if (!tangerbot_msgs__srv__detail__path_planning__rosidl_typesupport_introspection_c__PathPlanning_service_type_support_handle.typesupport_identifier) {
    tangerbot_msgs__srv__detail__path_planning__rosidl_typesupport_introspection_c__PathPlanning_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)tangerbot_msgs__srv__detail__path_planning__rosidl_typesupport_introspection_c__PathPlanning_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tangerbot_msgs, srv, PathPlanning_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tangerbot_msgs, srv, PathPlanning_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tangerbot_msgs, srv, PathPlanning_Event)()->data;
  }

  return &tangerbot_msgs__srv__detail__path_planning__rosidl_typesupport_introspection_c__PathPlanning_service_type_support_handle;
}
