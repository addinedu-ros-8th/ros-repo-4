// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tangerbot_msgs:msg/RobotPose.idl
// generated code does not contain a copyright notice
#include "tangerbot_msgs/msg/detail/robot_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `robot_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"

bool
tangerbot_msgs__msg__RobotPose__init(tangerbot_msgs__msg__RobotPose * msg)
{
  if (!msg) {
    return false;
  }
  // robot_id
  if (!rosidl_runtime_c__String__init(&msg->robot_id)) {
    tangerbot_msgs__msg__RobotPose__fini(msg);
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseStamped__init(&msg->pose)) {
    tangerbot_msgs__msg__RobotPose__fini(msg);
    return false;
  }
  return true;
}

void
tangerbot_msgs__msg__RobotPose__fini(tangerbot_msgs__msg__RobotPose * msg)
{
  if (!msg) {
    return;
  }
  // robot_id
  rosidl_runtime_c__String__fini(&msg->robot_id);
  // pose
  geometry_msgs__msg__PoseStamped__fini(&msg->pose);
}

bool
tangerbot_msgs__msg__RobotPose__are_equal(const tangerbot_msgs__msg__RobotPose * lhs, const tangerbot_msgs__msg__RobotPose * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->robot_id), &(rhs->robot_id)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  return true;
}

bool
tangerbot_msgs__msg__RobotPose__copy(
  const tangerbot_msgs__msg__RobotPose * input,
  tangerbot_msgs__msg__RobotPose * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_id
  if (!rosidl_runtime_c__String__copy(
      &(input->robot_id), &(output->robot_id)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  return true;
}

tangerbot_msgs__msg__RobotPose *
tangerbot_msgs__msg__RobotPose__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__msg__RobotPose * msg = (tangerbot_msgs__msg__RobotPose *)allocator.allocate(sizeof(tangerbot_msgs__msg__RobotPose), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tangerbot_msgs__msg__RobotPose));
  bool success = tangerbot_msgs__msg__RobotPose__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tangerbot_msgs__msg__RobotPose__destroy(tangerbot_msgs__msg__RobotPose * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tangerbot_msgs__msg__RobotPose__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tangerbot_msgs__msg__RobotPose__Sequence__init(tangerbot_msgs__msg__RobotPose__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__msg__RobotPose * data = NULL;

  if (size) {
    data = (tangerbot_msgs__msg__RobotPose *)allocator.zero_allocate(size, sizeof(tangerbot_msgs__msg__RobotPose), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tangerbot_msgs__msg__RobotPose__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tangerbot_msgs__msg__RobotPose__fini(&data[i - 1]);
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
tangerbot_msgs__msg__RobotPose__Sequence__fini(tangerbot_msgs__msg__RobotPose__Sequence * array)
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
      tangerbot_msgs__msg__RobotPose__fini(&array->data[i]);
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

tangerbot_msgs__msg__RobotPose__Sequence *
tangerbot_msgs__msg__RobotPose__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tangerbot_msgs__msg__RobotPose__Sequence * array = (tangerbot_msgs__msg__RobotPose__Sequence *)allocator.allocate(sizeof(tangerbot_msgs__msg__RobotPose__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tangerbot_msgs__msg__RobotPose__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tangerbot_msgs__msg__RobotPose__Sequence__destroy(tangerbot_msgs__msg__RobotPose__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tangerbot_msgs__msg__RobotPose__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tangerbot_msgs__msg__RobotPose__Sequence__are_equal(const tangerbot_msgs__msg__RobotPose__Sequence * lhs, const tangerbot_msgs__msg__RobotPose__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tangerbot_msgs__msg__RobotPose__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tangerbot_msgs__msg__RobotPose__Sequence__copy(
  const tangerbot_msgs__msg__RobotPose__Sequence * input,
  tangerbot_msgs__msg__RobotPose__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tangerbot_msgs__msg__RobotPose);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tangerbot_msgs__msg__RobotPose * data =
      (tangerbot_msgs__msg__RobotPose *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tangerbot_msgs__msg__RobotPose__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tangerbot_msgs__msg__RobotPose__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tangerbot_msgs__msg__RobotPose__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
