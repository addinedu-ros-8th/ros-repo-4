// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tangerbot_msgs:msg/DecodedVoice.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/msg/decoded_voice.h"


#ifndef TANGERBOT_MSGS__MSG__DETAIL__DECODED_VOICE__STRUCT_H_
#define TANGERBOT_MSGS__MSG__DETAIL__DECODED_VOICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'user_id'
// Member 'text'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/DecodedVoice in the package tangerbot_msgs.
typedef struct tangerbot_msgs__msg__DecodedVoice
{
  rosidl_runtime_c__String user_id;
  rosidl_runtime_c__String text;
} tangerbot_msgs__msg__DecodedVoice;

// Struct for a sequence of tangerbot_msgs__msg__DecodedVoice.
typedef struct tangerbot_msgs__msg__DecodedVoice__Sequence
{
  tangerbot_msgs__msg__DecodedVoice * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tangerbot_msgs__msg__DecodedVoice__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TANGERBOT_MSGS__MSG__DETAIL__DECODED_VOICE__STRUCT_H_
