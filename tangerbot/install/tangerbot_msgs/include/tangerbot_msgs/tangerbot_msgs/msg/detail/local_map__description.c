// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from tangerbot_msgs:msg/LocalMap.idl
// generated code does not contain a copyright notice

#include "tangerbot_msgs/msg/detail/local_map__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
const rosidl_type_hash_t *
tangerbot_msgs__msg__LocalMap__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9e, 0xc5, 0x94, 0x4d, 0x46, 0x01, 0x49, 0x6e,
      0x2f, 0x0e, 0xcc, 0xaf, 0x30, 0xe5, 0x69, 0x32,
      0xef, 0x09, 0x2e, 0xfa, 0x56, 0x31, 0x0a, 0xe8,
      0x4e, 0x7c, 0x9a, 0x04, 0xbc, 0xff, 0x45, 0x3c,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "std_msgs/msg/detail/header__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char tangerbot_msgs__msg__LocalMap__TYPE_NAME[] = "tangerbot_msgs/msg/LocalMap";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char tangerbot_msgs__msg__LocalMap__FIELD_NAME__robot_id[] = "robot_id";
static char tangerbot_msgs__msg__LocalMap__FIELD_NAME__header[] = "header";
static char tangerbot_msgs__msg__LocalMap__FIELD_NAME__resolution[] = "resolution";
static char tangerbot_msgs__msg__LocalMap__FIELD_NAME__width[] = "width";
static char tangerbot_msgs__msg__LocalMap__FIELD_NAME__height[] = "height";
static char tangerbot_msgs__msg__LocalMap__FIELD_NAME__origin_x[] = "origin_x";
static char tangerbot_msgs__msg__LocalMap__FIELD_NAME__origin_y[] = "origin_y";
static char tangerbot_msgs__msg__LocalMap__FIELD_NAME__data[] = "data";

static rosidl_runtime_c__type_description__Field tangerbot_msgs__msg__LocalMap__FIELDS[] = {
  {
    {tangerbot_msgs__msg__LocalMap__FIELD_NAME__robot_id, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__msg__LocalMap__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__msg__LocalMap__FIELD_NAME__resolution, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__msg__LocalMap__FIELD_NAME__width, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__msg__LocalMap__FIELD_NAME__height, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__msg__LocalMap__FIELD_NAME__origin_x, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__msg__LocalMap__FIELD_NAME__origin_y, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__msg__LocalMap__FIELD_NAME__data, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription tangerbot_msgs__msg__LocalMap__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tangerbot_msgs__msg__LocalMap__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tangerbot_msgs__msg__LocalMap__TYPE_NAME, 27, 27},
      {tangerbot_msgs__msg__LocalMap__FIELDS, 8, 8},
    },
    {tangerbot_msgs__msg__LocalMap__REFERENCED_TYPE_DESCRIPTIONS, 2, 2},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# \\xeb\\xa1\\x9c\\xeb\\xb4\\x87 \\xec\\xa4\\x91\\xec\\x8b\\xac(Local Frame) Occupancy Grid Map \\xeb\\xa9\\x94\\xec\\x8b\\x9c\\xec\\xa7\\x80\n"
  "string robot_id\n"
  "\n"
  "std_msgs/Header header\n"
  "\n"
  "float32 resolution        # 1 grid cell\\xec\\x9d\\x98 \\xec\\x8b\\xa4\\xec\\xa0\\x9c \\xed\\x81\\xac\\xea\\xb8\\xb0 (meters per cell), ex: 0.05m\n"
  "uint32 width               # grid map\\xec\\x9d\\x98 \\xea\\xb0\\x80\\xeb\\xa1\\x9c \\xec\\xb9\\xb8 \\xec\\x88\\x98\n"
  "uint32 height              # grid map\\xec\\x9d\\x98 \\xec\\x84\\xb8\\xeb\\xa1\\x9c \\xec\\xb9\\xb8 \\xec\\x88\\x98\n"
  "\n"
  "float32 origin_x           # grid (0,0) \\xec\\x85\\x80\\xec\\x9d\\x98 \\xec\\x83\\x81\\xeb\\x8c\\x80 \\xec\\x8b\\x9c\\xec\\x9e\\x91\\xec\\xa0\\x90 (x) (ex: -2.5m)\n"
  "float32 origin_y           # grid (0,0) \\xec\\x85\\x80\\xec\\x9d\\x98 \\xec\\x83\\x81\\xeb\\x8c\\x80 \\xec\\x8b\\x9c\\xec\\x9e\\x91\\xec\\xa0\\x90 (y) (ex: -2.5m)\n"
  "\n"
  "int8[] data                # Occupancy data (row-major 1D array)\n"
  "                           #  -1: Unknown, 0: Free, 100: Occupied";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
tangerbot_msgs__msg__LocalMap__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tangerbot_msgs__msg__LocalMap__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 518, 518},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tangerbot_msgs__msg__LocalMap__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[3];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 3, 3};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tangerbot_msgs__msg__LocalMap__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
