// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tangerbot_msgs:srv/Speak.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/srv/speak.h"


#ifndef TANGERBOT_MSGS__SRV__DETAIL__SPEAK__STRUCT_H_
#define TANGERBOT_MSGS__SRV__DETAIL__SPEAK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'robot_id'
#include "rosidl_runtime_c/string.h"
// Member 'data'
#include "std_msgs/msg/detail/byte_multi_array__struct.h"

/// Struct defined in srv/Speak in the package tangerbot_msgs.
typedef struct tangerbot_msgs__srv__Speak_Request
{
  rosidl_runtime_c__String robot_id;
  std_msgs__msg__ByteMultiArray data;
} tangerbot_msgs__srv__Speak_Request;

// Struct for a sequence of tangerbot_msgs__srv__Speak_Request.
typedef struct tangerbot_msgs__srv__Speak_Request__Sequence
{
  tangerbot_msgs__srv__Speak_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tangerbot_msgs__srv__Speak_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/Speak in the package tangerbot_msgs.
typedef struct tangerbot_msgs__srv__Speak_Response
{
  bool success;
} tangerbot_msgs__srv__Speak_Response;

// Struct for a sequence of tangerbot_msgs__srv__Speak_Response.
typedef struct tangerbot_msgs__srv__Speak_Response__Sequence
{
  tangerbot_msgs__srv__Speak_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tangerbot_msgs__srv__Speak_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  tangerbot_msgs__srv__Speak_Event__request__MAX_SIZE = 1
};
// response
enum
{
  tangerbot_msgs__srv__Speak_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/Speak in the package tangerbot_msgs.
typedef struct tangerbot_msgs__srv__Speak_Event
{
  service_msgs__msg__ServiceEventInfo info;
  tangerbot_msgs__srv__Speak_Request__Sequence request;
  tangerbot_msgs__srv__Speak_Response__Sequence response;
} tangerbot_msgs__srv__Speak_Event;

// Struct for a sequence of tangerbot_msgs__srv__Speak_Event.
typedef struct tangerbot_msgs__srv__Speak_Event__Sequence
{
  tangerbot_msgs__srv__Speak_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tangerbot_msgs__srv__Speak_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TANGERBOT_MSGS__SRV__DETAIL__SPEAK__STRUCT_H_
