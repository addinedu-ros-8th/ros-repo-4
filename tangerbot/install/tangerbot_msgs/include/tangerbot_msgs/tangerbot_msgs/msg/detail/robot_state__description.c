// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from tangerbot_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

#include "tangerbot_msgs/msg/detail/robot_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
const rosidl_type_hash_t *
tangerbot_msgs__msg__RobotState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc5, 0xea, 0x49, 0x07, 0xd0, 0xc5, 0x60, 0x5d,
      0x69, 0xf0, 0x66, 0x5d, 0xe3, 0xa0, 0x13, 0xa5,
      0xf7, 0x7c, 0x7a, 0xee, 0x07, 0x06, 0x97, 0x7b,
      0xd3, 0xb0, 0xaa, 0xfd, 0x85, 0x3a, 0xf2, 0x59,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char tangerbot_msgs__msg__RobotState__TYPE_NAME[] = "tangerbot_msgs/msg/RobotState";

// Define type names, field names, and default values
static char tangerbot_msgs__msg__RobotState__FIELD_NAME__robot_id[] = "robot_id";
static char tangerbot_msgs__msg__RobotState__FIELD_NAME__main_status[] = "main_status";
static char tangerbot_msgs__msg__RobotState__FIELD_NAME__motion_status[] = "motion_status";
static char tangerbot_msgs__msg__RobotState__FIELD_NAME__battery[] = "battery";

static rosidl_runtime_c__type_description__Field tangerbot_msgs__msg__RobotState__FIELDS[] = {
  {
    {tangerbot_msgs__msg__RobotState__FIELD_NAME__robot_id, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__msg__RobotState__FIELD_NAME__main_status, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__msg__RobotState__FIELD_NAME__motion_status, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__msg__RobotState__FIELD_NAME__battery, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tangerbot_msgs__msg__RobotState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tangerbot_msgs__msg__RobotState__TYPE_NAME, 29, 29},
      {tangerbot_msgs__msg__RobotState__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string robot_id\n"
  "uint8 main_status\n"
  "uint8 motion_status\n"
  "float32 battery\n"
  "\n"
  "# main_status constants\n"
  "uint8 IDLE=0\n"
  "uint8 WORKING=1\n"
  "\n"
  "# motion_status\n"
  "uint8 MOVING=0\n"
  "uint8 FOLLOWING=1\n"
  "uint8 STOP=2\n"
  "uint8 LOADING=3";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
tangerbot_msgs__msg__RobotState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tangerbot_msgs__msg__RobotState__TYPE_NAME, 29, 29},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 202, 202},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tangerbot_msgs__msg__RobotState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tangerbot_msgs__msg__RobotState__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
