// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from tangerbot_msgs:msg/DecodedVoice.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "tangerbot_msgs/msg/detail/decoded_voice__rosidl_typesupport_introspection_c.h"
#include "tangerbot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "tangerbot_msgs/msg/detail/decoded_voice__functions.h"
#include "tangerbot_msgs/msg/detail/decoded_voice__struct.h"


// Include directives for member types
// Member `user_id`
// Member `text`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void tangerbot_msgs__msg__DecodedVoice__rosidl_typesupport_introspection_c__DecodedVoice_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  tangerbot_msgs__msg__DecodedVoice__init(message_memory);
}

void tangerbot_msgs__msg__DecodedVoice__rosidl_typesupport_introspection_c__DecodedVoice_fini_function(void * message_memory)
{
  tangerbot_msgs__msg__DecodedVoice__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember tangerbot_msgs__msg__DecodedVoice__rosidl_typesupport_introspection_c__DecodedVoice_message_member_array[2] = {
  {
    "user_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs__msg__DecodedVoice, user_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "text",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(tangerbot_msgs__msg__DecodedVoice, text),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers tangerbot_msgs__msg__DecodedVoice__rosidl_typesupport_introspection_c__DecodedVoice_message_members = {
  "tangerbot_msgs__msg",  // message namespace
  "DecodedVoice",  // message name
  2,  // number of fields
  sizeof(tangerbot_msgs__msg__DecodedVoice),
  false,  // has_any_key_member_
  tangerbot_msgs__msg__DecodedVoice__rosidl_typesupport_introspection_c__DecodedVoice_message_member_array,  // message members
  tangerbot_msgs__msg__DecodedVoice__rosidl_typesupport_introspection_c__DecodedVoice_init_function,  // function to initialize message memory (memory has to be allocated)
  tangerbot_msgs__msg__DecodedVoice__rosidl_typesupport_introspection_c__DecodedVoice_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t tangerbot_msgs__msg__DecodedVoice__rosidl_typesupport_introspection_c__DecodedVoice_message_type_support_handle = {
  0,
  &tangerbot_msgs__msg__DecodedVoice__rosidl_typesupport_introspection_c__DecodedVoice_message_members,
  get_message_typesupport_handle_function,
  &tangerbot_msgs__msg__DecodedVoice__get_type_hash,
  &tangerbot_msgs__msg__DecodedVoice__get_type_description,
  &tangerbot_msgs__msg__DecodedVoice__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_tangerbot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, tangerbot_msgs, msg, DecodedVoice)() {
  if (!tangerbot_msgs__msg__DecodedVoice__rosidl_typesupport_introspection_c__DecodedVoice_message_type_support_handle.typesupport_identifier) {
    tangerbot_msgs__msg__DecodedVoice__rosidl_typesupport_introspection_c__DecodedVoice_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &tangerbot_msgs__msg__DecodedVoice__rosidl_typesupport_introspection_c__DecodedVoice_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
