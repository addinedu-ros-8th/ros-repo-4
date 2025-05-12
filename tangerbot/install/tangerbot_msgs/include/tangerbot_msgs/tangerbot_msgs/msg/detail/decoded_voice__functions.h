// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from tangerbot_msgs:msg/DecodedVoice.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/msg/decoded_voice.h"


#ifndef TANGERBOT_MSGS__MSG__DETAIL__DECODED_VOICE__FUNCTIONS_H_
#define TANGERBOT_MSGS__MSG__DETAIL__DECODED_VOICE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "tangerbot_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "tangerbot_msgs/msg/detail/decoded_voice__struct.h"

/// Initialize msg/DecodedVoice message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tangerbot_msgs__msg__DecodedVoice
 * )) before or use
 * tangerbot_msgs__msg__DecodedVoice__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
bool
tangerbot_msgs__msg__DecodedVoice__init(tangerbot_msgs__msg__DecodedVoice * msg);

/// Finalize msg/DecodedVoice message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
void
tangerbot_msgs__msg__DecodedVoice__fini(tangerbot_msgs__msg__DecodedVoice * msg);

/// Create msg/DecodedVoice message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tangerbot_msgs__msg__DecodedVoice__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
tangerbot_msgs__msg__DecodedVoice *
tangerbot_msgs__msg__DecodedVoice__create(void);

/// Destroy msg/DecodedVoice message.
/**
 * It calls
 * tangerbot_msgs__msg__DecodedVoice__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
void
tangerbot_msgs__msg__DecodedVoice__destroy(tangerbot_msgs__msg__DecodedVoice * msg);

/// Check for msg/DecodedVoice message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
bool
tangerbot_msgs__msg__DecodedVoice__are_equal(const tangerbot_msgs__msg__DecodedVoice * lhs, const tangerbot_msgs__msg__DecodedVoice * rhs);

/// Copy a msg/DecodedVoice message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
bool
tangerbot_msgs__msg__DecodedVoice__copy(
  const tangerbot_msgs__msg__DecodedVoice * input,
  tangerbot_msgs__msg__DecodedVoice * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
const rosidl_type_hash_t *
tangerbot_msgs__msg__DecodedVoice__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
const rosidl_runtime_c__type_description__TypeDescription *
tangerbot_msgs__msg__DecodedVoice__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
const rosidl_runtime_c__type_description__TypeSource *
tangerbot_msgs__msg__DecodedVoice__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
const rosidl_runtime_c__type_description__TypeSource__Sequence *
tangerbot_msgs__msg__DecodedVoice__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/DecodedVoice messages.
/**
 * It allocates the memory for the number of elements and calls
 * tangerbot_msgs__msg__DecodedVoice__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
bool
tangerbot_msgs__msg__DecodedVoice__Sequence__init(tangerbot_msgs__msg__DecodedVoice__Sequence * array, size_t size);

/// Finalize array of msg/DecodedVoice messages.
/**
 * It calls
 * tangerbot_msgs__msg__DecodedVoice__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
void
tangerbot_msgs__msg__DecodedVoice__Sequence__fini(tangerbot_msgs__msg__DecodedVoice__Sequence * array);

/// Create array of msg/DecodedVoice messages.
/**
 * It allocates the memory for the array and calls
 * tangerbot_msgs__msg__DecodedVoice__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
tangerbot_msgs__msg__DecodedVoice__Sequence *
tangerbot_msgs__msg__DecodedVoice__Sequence__create(size_t size);

/// Destroy array of msg/DecodedVoice messages.
/**
 * It calls
 * tangerbot_msgs__msg__DecodedVoice__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
void
tangerbot_msgs__msg__DecodedVoice__Sequence__destroy(tangerbot_msgs__msg__DecodedVoice__Sequence * array);

/// Check for msg/DecodedVoice message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
bool
tangerbot_msgs__msg__DecodedVoice__Sequence__are_equal(const tangerbot_msgs__msg__DecodedVoice__Sequence * lhs, const tangerbot_msgs__msg__DecodedVoice__Sequence * rhs);

/// Copy an array of msg/DecodedVoice messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
bool
tangerbot_msgs__msg__DecodedVoice__Sequence__copy(
  const tangerbot_msgs__msg__DecodedVoice__Sequence * input,
  tangerbot_msgs__msg__DecodedVoice__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TANGERBOT_MSGS__MSG__DETAIL__DECODED_VOICE__FUNCTIONS_H_
