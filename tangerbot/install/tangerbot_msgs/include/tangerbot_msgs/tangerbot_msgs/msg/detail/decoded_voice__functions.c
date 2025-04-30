// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tangerbot_msgs:msg/DecodedVoice.idl
// generated code does not contain a copyright notice
#include "tangerbot_msgs/msg/detail/decoded_voice__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `user_id`
// Member `text`
#include "rosidl_runtime_c/string_functions.h"

bool
tangerbot_msgs__msg__DecodedVoice__init(tangerbot_msgs__msg__DecodedVoice * msg)
{
  if (!msg) {
    return false;
  }
  // user_id
  if (!rosidl_runtime_c__String__init(&msg->user_id)) {
    tangerbot_msgs__msg__DecodedVoice__fini(msg);
    return false;
  }
  // text
  if (!rosidl_runtime_c__String__init(&msg->text)) {
    tangerbot_msgs__msg__DecodedVoice__fini(msg);
    return false;
  }
  return true;
}

void
tangerbot_msgs__msg__DecodedVoice__fini(tangerbot_msgs__msg__DecodedVoice * msg)
{
  if (!msg) {
    return;
  }
  // user_id
  rosidl_runtime_c__String__fini(&msg->user_id);
  // text
  rosidl_runtime_c__String__fini(&msg->text);
}

bool
tangerbot_msgs__msg__DecodedVoice__are_equal(const tangerbot_msgs__msg__DecodedVoice * lhs, const tangerbot_msgs__msg__DecodedVoice * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // user_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->user_id), &(rhs->user_id)))
  {
    return false;
  }
  // text
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->text), &(rhs->text)))
  {
    return false;
  }
  return true;
}

bool
tangerbot_msgs__msg__DecodedVoice__copy(
  const tangerbot_msgs__msg__DecodedVoice * input,
  tangerbot_msgs__msg__DecodedVoice * output)
{
  if (!input || !output) {
    return false;
  }
  // user_id
  if (!rosidl_runtime_c__String__copy(
      &(input->user_id), &(output->user_id)))
  {
    return false;
  }
  // text
  if (!rosidl_runtime_c__String__copy(
      &(input->text), &(output->text)))
  {
    return false;
  }
  return true;
}

tangerbot_msgs__msg__DecodedVoice *
tangerbot_msgs__msg__DecodedVoice__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__msg__DecodedVoice * msg = (tangerbot_msgs__msg__DecodedVoice *)allocator.allocate(sizeof(tangerbot_msgs__msg__DecodedVoice), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tangerbot_msgs__msg__DecodedVoice));
  bool success = tangerbot_msgs__msg__DecodedVoice__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tangerbot_msgs__msg__DecodedVoice__destroy(tangerbot_msgs__msg__DecodedVoice * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tangerbot_msgs__msg__DecodedVoice__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tangerbot_msgs__msg__DecodedVoice__Sequence__init(tangerbot_msgs__msg__DecodedVoice__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__msg__DecodedVoice * data = NULL;

  if (size) {
    data = (tangerbot_msgs__msg__DecodedVoice *)allocator.zero_allocate(size, sizeof(tangerbot_msgs__msg__DecodedVoice), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tangerbot_msgs__msg__DecodedVoice__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tangerbot_msgs__msg__DecodedVoice__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tangerbot_msgs__msg__DecodedVoice__Sequence__fini(tangerbot_msgs__msg__DecodedVoice__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tangerbot_msgs__msg__DecodedVoice__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tangerbot_msgs__msg__DecodedVoice__Sequence *
tangerbot_msgs__msg__DecodedVoice__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__msg__DecodedVoice__Sequence * array = (tangerbot_msgs__msg__DecodedVoice__Sequence *)allocator.allocate(sizeof(tangerbot_msgs__msg__DecodedVoice__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tangerbot_msgs__msg__DecodedVoice__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tangerbot_msgs__msg__DecodedVoice__Sequence__destroy(tangerbot_msgs__msg__DecodedVoice__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tangerbot_msgs__msg__DecodedVoice__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tangerbot_msgs__msg__DecodedVoice__Sequence__are_equal(const tangerbot_msgs__msg__DecodedVoice__Sequence * lhs, const tangerbot_msgs__msg__DecodedVoice__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tangerbot_msgs__msg__DecodedVoice__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tangerbot_msgs__msg__DecodedVoice__Sequence__copy(
  const tangerbot_msgs__msg__DecodedVoice__Sequence * input,
  tangerbot_msgs__msg__DecodedVoice__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tangerbot_msgs__msg__DecodedVoice);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tangerbot_msgs__msg__DecodedVoice * data =
      (tangerbot_msgs__msg__DecodedVoice *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tangerbot_msgs__msg__DecodedVoice__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tangerbot_msgs__msg__DecodedVoice__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tangerbot_msgs__msg__DecodedVoice__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
