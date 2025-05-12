// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from pinky_interfaces:srv/Emotion.idl
// generated code does not contain a copyright notice

#include "pinky_interfaces/srv/detail/emotion__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_pinky_interfaces
const rosidl_type_hash_t *
pinky_interfaces__srv__Emotion__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x5b, 0x29, 0xd3, 0x00, 0x20, 0xad, 0x12, 0x7a,
      0x5b, 0xf6, 0xb7, 0x67, 0x5e, 0x0d, 0x67, 0x46,
      0x18, 0xaf, 0x17, 0xc0, 0x53, 0xc1, 0x35, 0xc4,
      0x79, 0xbb, 0x66, 0x95, 0xfb, 0x23, 0xb3, 0xe7,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_pinky_interfaces
const rosidl_type_hash_t *
pinky_interfaces__srv__Emotion_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf7, 0x7d, 0x15, 0x20, 0x8c, 0x6d, 0x54, 0x44,
      0xa7, 0x08, 0x6e, 0x4a, 0xd0, 0x8a, 0x4a, 0xb8,
      0xa0, 0x5d, 0x9d, 0x7b, 0x77, 0xc2, 0xa9, 0xc6,
      0x0f, 0x96, 0xf4, 0x5f, 0x36, 0xf2, 0x31, 0x81,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_pinky_interfaces
const rosidl_type_hash_t *
pinky_interfaces__srv__Emotion_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x56, 0x89, 0x90, 0x7e, 0x63, 0xea, 0x29, 0x88,
      0x29, 0xa4, 0x2c, 0x6c, 0xaa, 0xb3, 0xda, 0x68,
      0xfe, 0x59, 0x5f, 0x9f, 0x2f, 0x47, 0x69, 0xcc,
      0x5b, 0x11, 0x37, 0xab, 0xe6, 0xda, 0xb5, 0x46,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_pinky_interfaces
const rosidl_type_hash_t *
pinky_interfaces__srv__Emotion_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb2, 0x6e, 0x66, 0xe5, 0x6a, 0xf4, 0x71, 0x3b,
      0x96, 0x98, 0xc8, 0x7d, 0xea, 0xba, 0xf5, 0xdc,
      0x11, 0x5e, 0x22, 0x44, 0x21, 0x97, 0x7a, 0x48,
      0x72, 0x9e, 0x5b, 0x4e, 0x4e, 0xb2, 0x6a, 0x18,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

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
#endif

static char pinky_interfaces__srv__Emotion__TYPE_NAME[] = "pinky_interfaces/srv/Emotion";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char pinky_interfaces__srv__Emotion_Event__TYPE_NAME[] = "pinky_interfaces/srv/Emotion_Event";
static char pinky_interfaces__srv__Emotion_Request__TYPE_NAME[] = "pinky_interfaces/srv/Emotion_Request";
static char pinky_interfaces__srv__Emotion_Response__TYPE_NAME[] = "pinky_interfaces/srv/Emotion_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char pinky_interfaces__srv__Emotion__FIELD_NAME__request_message[] = "request_message";
static char pinky_interfaces__srv__Emotion__FIELD_NAME__response_message[] = "response_message";
static char pinky_interfaces__srv__Emotion__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field pinky_interfaces__srv__Emotion__FIELDS[] = {
  {
    {pinky_interfaces__srv__Emotion__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {pinky_interfaces__srv__Emotion_Request__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
  {
    {pinky_interfaces__srv__Emotion__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {pinky_interfaces__srv__Emotion_Response__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
  {
    {pinky_interfaces__srv__Emotion__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {pinky_interfaces__srv__Emotion_Event__TYPE_NAME, 34, 34},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription pinky_interfaces__srv__Emotion__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {pinky_interfaces__srv__Emotion_Event__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {pinky_interfaces__srv__Emotion_Request__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {pinky_interfaces__srv__Emotion_Response__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
pinky_interfaces__srv__Emotion__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {pinky_interfaces__srv__Emotion__TYPE_NAME, 28, 28},
      {pinky_interfaces__srv__Emotion__FIELDS, 3, 3},
    },
    {pinky_interfaces__srv__Emotion__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = pinky_interfaces__srv__Emotion_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = pinky_interfaces__srv__Emotion_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = pinky_interfaces__srv__Emotion_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char pinky_interfaces__srv__Emotion_Request__FIELD_NAME__emotion[] = "emotion";

static rosidl_runtime_c__type_description__Field pinky_interfaces__srv__Emotion_Request__FIELDS[] = {
  {
    {pinky_interfaces__srv__Emotion_Request__FIELD_NAME__emotion, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
pinky_interfaces__srv__Emotion_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {pinky_interfaces__srv__Emotion_Request__TYPE_NAME, 36, 36},
      {pinky_interfaces__srv__Emotion_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char pinky_interfaces__srv__Emotion_Response__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field pinky_interfaces__srv__Emotion_Response__FIELDS[] = {
  {
    {pinky_interfaces__srv__Emotion_Response__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
pinky_interfaces__srv__Emotion_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {pinky_interfaces__srv__Emotion_Response__TYPE_NAME, 37, 37},
      {pinky_interfaces__srv__Emotion_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char pinky_interfaces__srv__Emotion_Event__FIELD_NAME__info[] = "info";
static char pinky_interfaces__srv__Emotion_Event__FIELD_NAME__request[] = "request";
static char pinky_interfaces__srv__Emotion_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field pinky_interfaces__srv__Emotion_Event__FIELDS[] = {
  {
    {pinky_interfaces__srv__Emotion_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {pinky_interfaces__srv__Emotion_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {pinky_interfaces__srv__Emotion_Request__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
  {
    {pinky_interfaces__srv__Emotion_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {pinky_interfaces__srv__Emotion_Response__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription pinky_interfaces__srv__Emotion_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {pinky_interfaces__srv__Emotion_Request__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {pinky_interfaces__srv__Emotion_Response__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
pinky_interfaces__srv__Emotion_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {pinky_interfaces__srv__Emotion_Event__TYPE_NAME, 34, 34},
      {pinky_interfaces__srv__Emotion_Event__FIELDS, 3, 3},
    },
    {pinky_interfaces__srv__Emotion_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = pinky_interfaces__srv__Emotion_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = pinky_interfaces__srv__Emotion_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string emotion  # Emotion input (e.g., \"hello\", \"basic\", \"angry\", \"bored\", \"fun\", \"happy\", \"interest\", \"sad\")\n"
  "---\n"
  "string response";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
pinky_interfaces__srv__Emotion__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {pinky_interfaces__srv__Emotion__TYPE_NAME, 28, 28},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 130, 130},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
pinky_interfaces__srv__Emotion_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {pinky_interfaces__srv__Emotion_Request__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
pinky_interfaces__srv__Emotion_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {pinky_interfaces__srv__Emotion_Response__TYPE_NAME, 37, 37},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
pinky_interfaces__srv__Emotion_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {pinky_interfaces__srv__Emotion_Event__TYPE_NAME, 34, 34},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
pinky_interfaces__srv__Emotion__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *pinky_interfaces__srv__Emotion__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *pinky_interfaces__srv__Emotion_Event__get_individual_type_description_source(NULL);
    sources[3] = *pinky_interfaces__srv__Emotion_Request__get_individual_type_description_source(NULL);
    sources[4] = *pinky_interfaces__srv__Emotion_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
pinky_interfaces__srv__Emotion_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *pinky_interfaces__srv__Emotion_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
pinky_interfaces__srv__Emotion_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *pinky_interfaces__srv__Emotion_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
pinky_interfaces__srv__Emotion_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *pinky_interfaces__srv__Emotion_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *pinky_interfaces__srv__Emotion_Request__get_individual_type_description_source(NULL);
    sources[3] = *pinky_interfaces__srv__Emotion_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
