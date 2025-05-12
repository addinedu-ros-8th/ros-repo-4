// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from tangerbot_msgs:srv/Speak.idl
// generated code does not contain a copyright notice

#include "tangerbot_msgs/srv/detail/speak__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
const rosidl_type_hash_t *
tangerbot_msgs__srv__Speak__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xcd, 0x19, 0x11, 0x0d, 0x82, 0x15, 0xfc, 0x3c,
      0x3c, 0x2a, 0x39, 0x12, 0x05, 0xe9, 0xf6, 0xb2,
      0x17, 0x0b, 0xfd, 0xc4, 0x50, 0x3b, 0x30, 0xc9,
      0x8e, 0xb7, 0xbf, 0x0d, 0x1f, 0xd4, 0x6a, 0x96,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
const rosidl_type_hash_t *
tangerbot_msgs__srv__Speak_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd4, 0x04, 0xa9, 0xc9, 0x42, 0xcf, 0x03, 0x6f,
      0xd0, 0x62, 0x3a, 0x6a, 0x60, 0x79, 0x59, 0xe1,
      0x0b, 0xdf, 0x90, 0x31, 0xf1, 0xdb, 0xf1, 0x7c,
      0xcd, 0x66, 0xc0, 0x89, 0x9c, 0xc9, 0x0d, 0x5a,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
const rosidl_type_hash_t *
tangerbot_msgs__srv__Speak_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb9, 0x00, 0x26, 0x1f, 0x0e, 0x11, 0xd9, 0x2a,
      0x04, 0xe2, 0xaf, 0xf3, 0x22, 0x5b, 0xd2, 0x28,
      0xf0, 0x37, 0x4c, 0x8c, 0x55, 0xf0, 0xec, 0xad,
      0xfd, 0x1a, 0xd4, 0xaf, 0xea, 0x9d, 0x2d, 0xc7,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_tangerbot_msgs
const rosidl_type_hash_t *
tangerbot_msgs__srv__Speak_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x02, 0x8a, 0x0c, 0x84, 0x6b, 0x5f, 0xf6, 0x92,
      0xfa, 0xc1, 0xd5, 0x0b, 0x35, 0x06, 0x83, 0xd7,
      0xfa, 0x39, 0xde, 0x38, 0x18, 0x42, 0x2c, 0xb7,
      0x87, 0x4f, 0xd5, 0x9d, 0xc3, 0x53, 0xb0, 0x02,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "std_msgs/msg/detail/multi_array_layout__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "std_msgs/msg/detail/multi_array_dimension__functions.h"
#include "std_msgs/msg/detail/byte_multi_array__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
static const rosidl_type_hash_t std_msgs__msg__ByteMultiArray__EXPECTED_HASH = {1, {
    0x97, 0x2f, 0xec, 0x7f, 0x50, 0xab, 0x3c, 0x1d,
    0x06, 0x78, 0x3c, 0x22, 0x8e, 0x79, 0xe8, 0xa9,
    0xa5, 0x09, 0x02, 0x17, 0x08, 0xc5, 0x11, 0xc0,
    0x59, 0x92, 0x62, 0x61, 0xad, 0xa9, 0x01, 0xd4,
  }};
static const rosidl_type_hash_t std_msgs__msg__MultiArrayDimension__EXPECTED_HASH = {1, {
    0x5e, 0x77, 0x3a, 0x60, 0xa4, 0xc7, 0xfc, 0x8a,
    0x54, 0x98, 0x5f, 0x30, 0x7c, 0x78, 0x37, 0xaa,
    0x29, 0x94, 0x25, 0x2a, 0x12, 0x6c, 0x30, 0x19,
    0x57, 0xa2, 0x4e, 0x31, 0x28, 0x2c, 0x9c, 0xbe,
  }};
static const rosidl_type_hash_t std_msgs__msg__MultiArrayLayout__EXPECTED_HASH = {1, {
    0x4c, 0x66, 0xe6, 0xf7, 0x8e, 0x74, 0x0a, 0xc1,
    0x03, 0xa9, 0x4c, 0xf6, 0x32, 0x59, 0xf9, 0x68,
    0xe4, 0x8c, 0x61, 0x7e, 0x76, 0x99, 0xe8, 0x29,
    0xb6, 0x3c, 0x21, 0xa5, 0xcb, 0x50, 0xda, 0xc6,
  }};
#endif

static char tangerbot_msgs__srv__Speak__TYPE_NAME[] = "tangerbot_msgs/srv/Speak";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";
static char std_msgs__msg__ByteMultiArray__TYPE_NAME[] = "std_msgs/msg/ByteMultiArray";
static char std_msgs__msg__MultiArrayDimension__TYPE_NAME[] = "std_msgs/msg/MultiArrayDimension";
static char std_msgs__msg__MultiArrayLayout__TYPE_NAME[] = "std_msgs/msg/MultiArrayLayout";
static char tangerbot_msgs__srv__Speak_Event__TYPE_NAME[] = "tangerbot_msgs/srv/Speak_Event";
static char tangerbot_msgs__srv__Speak_Request__TYPE_NAME[] = "tangerbot_msgs/srv/Speak_Request";
static char tangerbot_msgs__srv__Speak_Response__TYPE_NAME[] = "tangerbot_msgs/srv/Speak_Response";

// Define type names, field names, and default values
static char tangerbot_msgs__srv__Speak__FIELD_NAME__request_message[] = "request_message";
static char tangerbot_msgs__srv__Speak__FIELD_NAME__response_message[] = "response_message";
static char tangerbot_msgs__srv__Speak__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field tangerbot_msgs__srv__Speak__FIELDS[] = {
  {
    {tangerbot_msgs__srv__Speak__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {tangerbot_msgs__srv__Speak_Request__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__Speak__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {tangerbot_msgs__srv__Speak_Response__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__Speak__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {tangerbot_msgs__srv__Speak_Event__TYPE_NAME, 30, 30},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription tangerbot_msgs__srv__Speak__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__ByteMultiArray__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__MultiArrayDimension__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__MultiArrayLayout__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__Speak_Event__TYPE_NAME, 30, 30},
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__Speak_Request__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__Speak_Response__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tangerbot_msgs__srv__Speak__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tangerbot_msgs__srv__Speak__TYPE_NAME, 24, 24},
      {tangerbot_msgs__srv__Speak__FIELDS, 3, 3},
    },
    {tangerbot_msgs__srv__Speak__REFERENCED_TYPE_DESCRIPTIONS, 8, 8},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__ByteMultiArray__EXPECTED_HASH, std_msgs__msg__ByteMultiArray__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = std_msgs__msg__ByteMultiArray__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__MultiArrayDimension__EXPECTED_HASH, std_msgs__msg__MultiArrayDimension__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = std_msgs__msg__MultiArrayDimension__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__MultiArrayLayout__EXPECTED_HASH, std_msgs__msg__MultiArrayLayout__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = std_msgs__msg__MultiArrayLayout__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = tangerbot_msgs__srv__Speak_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[6].fields = tangerbot_msgs__srv__Speak_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[7].fields = tangerbot_msgs__srv__Speak_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char tangerbot_msgs__srv__Speak_Request__FIELD_NAME__robot_id[] = "robot_id";
static char tangerbot_msgs__srv__Speak_Request__FIELD_NAME__data[] = "data";

static rosidl_runtime_c__type_description__Field tangerbot_msgs__srv__Speak_Request__FIELDS[] = {
  {
    {tangerbot_msgs__srv__Speak_Request__FIELD_NAME__robot_id, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__Speak_Request__FIELD_NAME__data, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__ByteMultiArray__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription tangerbot_msgs__srv__Speak_Request__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {std_msgs__msg__ByteMultiArray__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__MultiArrayDimension__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__MultiArrayLayout__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tangerbot_msgs__srv__Speak_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tangerbot_msgs__srv__Speak_Request__TYPE_NAME, 32, 32},
      {tangerbot_msgs__srv__Speak_Request__FIELDS, 2, 2},
    },
    {tangerbot_msgs__srv__Speak_Request__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
  };
  if (!constructed) {
    assert(0 == memcmp(&std_msgs__msg__ByteMultiArray__EXPECTED_HASH, std_msgs__msg__ByteMultiArray__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = std_msgs__msg__ByteMultiArray__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__MultiArrayDimension__EXPECTED_HASH, std_msgs__msg__MultiArrayDimension__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = std_msgs__msg__MultiArrayDimension__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__MultiArrayLayout__EXPECTED_HASH, std_msgs__msg__MultiArrayLayout__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = std_msgs__msg__MultiArrayLayout__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char tangerbot_msgs__srv__Speak_Response__FIELD_NAME__success[] = "success";

static rosidl_runtime_c__type_description__Field tangerbot_msgs__srv__Speak_Response__FIELDS[] = {
  {
    {tangerbot_msgs__srv__Speak_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tangerbot_msgs__srv__Speak_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tangerbot_msgs__srv__Speak_Response__TYPE_NAME, 33, 33},
      {tangerbot_msgs__srv__Speak_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char tangerbot_msgs__srv__Speak_Event__FIELD_NAME__info[] = "info";
static char tangerbot_msgs__srv__Speak_Event__FIELD_NAME__request[] = "request";
static char tangerbot_msgs__srv__Speak_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field tangerbot_msgs__srv__Speak_Event__FIELDS[] = {
  {
    {tangerbot_msgs__srv__Speak_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__Speak_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {tangerbot_msgs__srv__Speak_Request__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__Speak_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {tangerbot_msgs__srv__Speak_Response__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription tangerbot_msgs__srv__Speak_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__ByteMultiArray__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__MultiArrayDimension__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__MultiArrayLayout__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__Speak_Request__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {tangerbot_msgs__srv__Speak_Response__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tangerbot_msgs__srv__Speak_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tangerbot_msgs__srv__Speak_Event__TYPE_NAME, 30, 30},
      {tangerbot_msgs__srv__Speak_Event__FIELDS, 3, 3},
    },
    {tangerbot_msgs__srv__Speak_Event__REFERENCED_TYPE_DESCRIPTIONS, 7, 7},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__ByteMultiArray__EXPECTED_HASH, std_msgs__msg__ByteMultiArray__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = std_msgs__msg__ByteMultiArray__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__MultiArrayDimension__EXPECTED_HASH, std_msgs__msg__MultiArrayDimension__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = std_msgs__msg__MultiArrayDimension__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__MultiArrayLayout__EXPECTED_HASH, std_msgs__msg__MultiArrayLayout__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = std_msgs__msg__MultiArrayLayout__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[5].fields = tangerbot_msgs__srv__Speak_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[6].fields = tangerbot_msgs__srv__Speak_Response__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string robot_id\n"
  "std_msgs/ByteMultiArray data\n"
  "---\n"
  "bool success";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
tangerbot_msgs__srv__Speak__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tangerbot_msgs__srv__Speak__TYPE_NAME, 24, 24},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 61, 61},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
tangerbot_msgs__srv__Speak_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tangerbot_msgs__srv__Speak_Request__TYPE_NAME, 32, 32},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
tangerbot_msgs__srv__Speak_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tangerbot_msgs__srv__Speak_Response__TYPE_NAME, 33, 33},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
tangerbot_msgs__srv__Speak_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tangerbot_msgs__srv__Speak_Event__TYPE_NAME, 30, 30},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tangerbot_msgs__srv__Speak__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[9];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 9, 9};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tangerbot_msgs__srv__Speak__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *std_msgs__msg__ByteMultiArray__get_individual_type_description_source(NULL);
    sources[4] = *std_msgs__msg__MultiArrayDimension__get_individual_type_description_source(NULL);
    sources[5] = *std_msgs__msg__MultiArrayLayout__get_individual_type_description_source(NULL);
    sources[6] = *tangerbot_msgs__srv__Speak_Event__get_individual_type_description_source(NULL);
    sources[7] = *tangerbot_msgs__srv__Speak_Request__get_individual_type_description_source(NULL);
    sources[8] = *tangerbot_msgs__srv__Speak_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tangerbot_msgs__srv__Speak_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tangerbot_msgs__srv__Speak_Request__get_individual_type_description_source(NULL),
    sources[1] = *std_msgs__msg__ByteMultiArray__get_individual_type_description_source(NULL);
    sources[2] = *std_msgs__msg__MultiArrayDimension__get_individual_type_description_source(NULL);
    sources[3] = *std_msgs__msg__MultiArrayLayout__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tangerbot_msgs__srv__Speak_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tangerbot_msgs__srv__Speak_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tangerbot_msgs__srv__Speak_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[8];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 8, 8};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tangerbot_msgs__srv__Speak_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    sources[3] = *std_msgs__msg__ByteMultiArray__get_individual_type_description_source(NULL);
    sources[4] = *std_msgs__msg__MultiArrayDimension__get_individual_type_description_source(NULL);
    sources[5] = *std_msgs__msg__MultiArrayLayout__get_individual_type_description_source(NULL);
    sources[6] = *tangerbot_msgs__srv__Speak_Request__get_individual_type_description_source(NULL);
    sources[7] = *tangerbot_msgs__srv__Speak_Response__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
