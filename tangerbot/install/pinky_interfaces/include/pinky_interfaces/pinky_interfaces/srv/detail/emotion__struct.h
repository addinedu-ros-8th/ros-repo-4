// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pinky_interfaces:srv/Emotion.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pinky_interfaces/srv/emotion.h"


#ifndef PINKY_INTERFACES__SRV__DETAIL__EMOTION__STRUCT_H_
#define PINKY_INTERFACES__SRV__DETAIL__EMOTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'emotion'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Emotion in the package pinky_interfaces.
typedef struct pinky_interfaces__srv__Emotion_Request
{
  /// Emotion input (e.g., "hello", "basic", "angry", "bored", "fun", "happy", "interest", "sad")
  rosidl_runtime_c__String emotion;
} pinky_interfaces__srv__Emotion_Request;

// Struct for a sequence of pinky_interfaces__srv__Emotion_Request.
typedef struct pinky_interfaces__srv__Emotion_Request__Sequence
{
  pinky_interfaces__srv__Emotion_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pinky_interfaces__srv__Emotion_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'response'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Emotion in the package pinky_interfaces.
typedef struct pinky_interfaces__srv__Emotion_Response
{
  rosidl_runtime_c__String response;
} pinky_interfaces__srv__Emotion_Response;

// Struct for a sequence of pinky_interfaces__srv__Emotion_Response.
typedef struct pinky_interfaces__srv__Emotion_Response__Sequence
{
  pinky_interfaces__srv__Emotion_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pinky_interfaces__srv__Emotion_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  pinky_interfaces__srv__Emotion_Event__request__MAX_SIZE = 1
};
// response
enum
{
  pinky_interfaces__srv__Emotion_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/Emotion in the package pinky_interfaces.
typedef struct pinky_interfaces__srv__Emotion_Event
{
  service_msgs__msg__ServiceEventInfo info;
  pinky_interfaces__srv__Emotion_Request__Sequence request;
  pinky_interfaces__srv__Emotion_Response__Sequence response;
} pinky_interfaces__srv__Emotion_Event;

// Struct for a sequence of pinky_interfaces__srv__Emotion_Event.
typedef struct pinky_interfaces__srv__Emotion_Event__Sequence
{
  pinky_interfaces__srv__Emotion_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pinky_interfaces__srv__Emotion_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PINKY_INTERFACES__SRV__DETAIL__EMOTION__STRUCT_H_
