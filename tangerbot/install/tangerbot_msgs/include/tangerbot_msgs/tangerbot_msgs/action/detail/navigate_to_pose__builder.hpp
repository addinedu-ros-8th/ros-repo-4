// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tangerbot_msgs:action/NavigateToPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tangerbot_msgs/action/navigate_to_pose.hpp"


#ifndef TANGERBOT_MSGS__ACTION__DETAIL__NAVIGATE_TO_POSE__BUILDER_HPP_
#define TANGERBOT_MSGS__ACTION__DETAIL__NAVIGATE_TO_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tangerbot_msgs/action/detail/navigate_to_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tangerbot_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_Goal_pose
{
public:
  explicit Init_NavigateToPose_Goal_pose(::tangerbot_msgs::action::NavigateToPose_Goal & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::action::NavigateToPose_Goal pose(::tangerbot_msgs::action::NavigateToPose_Goal::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_Goal msg_;
};

class Init_NavigateToPose_Goal_robot_id
{
public:
  Init_NavigateToPose_Goal_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToPose_Goal_pose robot_id(::tangerbot_msgs::action::NavigateToPose_Goal::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_NavigateToPose_Goal_pose(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::action::NavigateToPose_Goal>()
{
  return tangerbot_msgs::action::builder::Init_NavigateToPose_Goal_robot_id();
}

}  // namespace tangerbot_msgs


namespace tangerbot_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_Result_robot_id
{
public:
  explicit Init_NavigateToPose_Result_robot_id(::tangerbot_msgs::action::NavigateToPose_Result & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::action::NavigateToPose_Result robot_id(::tangerbot_msgs::action::NavigateToPose_Result::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_Result msg_;
};

class Init_NavigateToPose_Result_error_msg
{
public:
  explicit Init_NavigateToPose_Result_error_msg(::tangerbot_msgs::action::NavigateToPose_Result & msg)
  : msg_(msg)
  {}
  Init_NavigateToPose_Result_robot_id error_msg(::tangerbot_msgs::action::NavigateToPose_Result::_error_msg_type arg)
  {
    msg_.error_msg = std::move(arg);
    return Init_NavigateToPose_Result_robot_id(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_Result msg_;
};

class Init_NavigateToPose_Result_error_code
{
public:
  Init_NavigateToPose_Result_error_code()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToPose_Result_error_msg error_code(::tangerbot_msgs::action::NavigateToPose_Result::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return Init_NavigateToPose_Result_error_msg(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::action::NavigateToPose_Result>()
{
  return tangerbot_msgs::action::builder::Init_NavigateToPose_Result_error_code();
}

}  // namespace tangerbot_msgs


namespace tangerbot_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_Feedback_distance_remaining
{
public:
  explicit Init_NavigateToPose_Feedback_distance_remaining(::tangerbot_msgs::action::NavigateToPose_Feedback & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::action::NavigateToPose_Feedback distance_remaining(::tangerbot_msgs::action::NavigateToPose_Feedback::_distance_remaining_type arg)
  {
    msg_.distance_remaining = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_Feedback msg_;
};

class Init_NavigateToPose_Feedback_robot_id
{
public:
  Init_NavigateToPose_Feedback_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToPose_Feedback_distance_remaining robot_id(::tangerbot_msgs::action::NavigateToPose_Feedback::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_NavigateToPose_Feedback_distance_remaining(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::action::NavigateToPose_Feedback>()
{
  return tangerbot_msgs::action::builder::Init_NavigateToPose_Feedback_robot_id();
}

}  // namespace tangerbot_msgs


namespace tangerbot_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_SendGoal_Request_goal
{
public:
  explicit Init_NavigateToPose_SendGoal_Request_goal(::tangerbot_msgs::action::NavigateToPose_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::action::NavigateToPose_SendGoal_Request goal(::tangerbot_msgs::action::NavigateToPose_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_SendGoal_Request msg_;
};

class Init_NavigateToPose_SendGoal_Request_goal_id
{
public:
  Init_NavigateToPose_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToPose_SendGoal_Request_goal goal_id(::tangerbot_msgs::action::NavigateToPose_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_NavigateToPose_SendGoal_Request_goal(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::action::NavigateToPose_SendGoal_Request>()
{
  return tangerbot_msgs::action::builder::Init_NavigateToPose_SendGoal_Request_goal_id();
}

}  // namespace tangerbot_msgs


namespace tangerbot_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_SendGoal_Response_stamp
{
public:
  explicit Init_NavigateToPose_SendGoal_Response_stamp(::tangerbot_msgs::action::NavigateToPose_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::action::NavigateToPose_SendGoal_Response stamp(::tangerbot_msgs::action::NavigateToPose_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_SendGoal_Response msg_;
};

class Init_NavigateToPose_SendGoal_Response_accepted
{
public:
  Init_NavigateToPose_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToPose_SendGoal_Response_stamp accepted(::tangerbot_msgs::action::NavigateToPose_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_NavigateToPose_SendGoal_Response_stamp(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::action::NavigateToPose_SendGoal_Response>()
{
  return tangerbot_msgs::action::builder::Init_NavigateToPose_SendGoal_Response_accepted();
}

}  // namespace tangerbot_msgs


namespace tangerbot_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_SendGoal_Event_response
{
public:
  explicit Init_NavigateToPose_SendGoal_Event_response(::tangerbot_msgs::action::NavigateToPose_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::action::NavigateToPose_SendGoal_Event response(::tangerbot_msgs::action::NavigateToPose_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_SendGoal_Event msg_;
};

class Init_NavigateToPose_SendGoal_Event_request
{
public:
  explicit Init_NavigateToPose_SendGoal_Event_request(::tangerbot_msgs::action::NavigateToPose_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_NavigateToPose_SendGoal_Event_response request(::tangerbot_msgs::action::NavigateToPose_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_NavigateToPose_SendGoal_Event_response(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_SendGoal_Event msg_;
};

class Init_NavigateToPose_SendGoal_Event_info
{
public:
  Init_NavigateToPose_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToPose_SendGoal_Event_request info(::tangerbot_msgs::action::NavigateToPose_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_NavigateToPose_SendGoal_Event_request(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::action::NavigateToPose_SendGoal_Event>()
{
  return tangerbot_msgs::action::builder::Init_NavigateToPose_SendGoal_Event_info();
}

}  // namespace tangerbot_msgs


namespace tangerbot_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_GetResult_Request_goal_id
{
public:
  Init_NavigateToPose_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tangerbot_msgs::action::NavigateToPose_GetResult_Request goal_id(::tangerbot_msgs::action::NavigateToPose_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::action::NavigateToPose_GetResult_Request>()
{
  return tangerbot_msgs::action::builder::Init_NavigateToPose_GetResult_Request_goal_id();
}

}  // namespace tangerbot_msgs


namespace tangerbot_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_GetResult_Response_result
{
public:
  explicit Init_NavigateToPose_GetResult_Response_result(::tangerbot_msgs::action::NavigateToPose_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::action::NavigateToPose_GetResult_Response result(::tangerbot_msgs::action::NavigateToPose_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_GetResult_Response msg_;
};

class Init_NavigateToPose_GetResult_Response_status
{
public:
  Init_NavigateToPose_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToPose_GetResult_Response_result status(::tangerbot_msgs::action::NavigateToPose_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_NavigateToPose_GetResult_Response_result(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::action::NavigateToPose_GetResult_Response>()
{
  return tangerbot_msgs::action::builder::Init_NavigateToPose_GetResult_Response_status();
}

}  // namespace tangerbot_msgs


namespace tangerbot_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_GetResult_Event_response
{
public:
  explicit Init_NavigateToPose_GetResult_Event_response(::tangerbot_msgs::action::NavigateToPose_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::action::NavigateToPose_GetResult_Event response(::tangerbot_msgs::action::NavigateToPose_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_GetResult_Event msg_;
};

class Init_NavigateToPose_GetResult_Event_request
{
public:
  explicit Init_NavigateToPose_GetResult_Event_request(::tangerbot_msgs::action::NavigateToPose_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_NavigateToPose_GetResult_Event_response request(::tangerbot_msgs::action::NavigateToPose_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_NavigateToPose_GetResult_Event_response(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_GetResult_Event msg_;
};

class Init_NavigateToPose_GetResult_Event_info
{
public:
  Init_NavigateToPose_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToPose_GetResult_Event_request info(::tangerbot_msgs::action::NavigateToPose_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_NavigateToPose_GetResult_Event_request(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::action::NavigateToPose_GetResult_Event>()
{
  return tangerbot_msgs::action::builder::Init_NavigateToPose_GetResult_Event_info();
}

}  // namespace tangerbot_msgs


namespace tangerbot_msgs
{

namespace action
{

namespace builder
{

class Init_NavigateToPose_FeedbackMessage_feedback
{
public:
  explicit Init_NavigateToPose_FeedbackMessage_feedback(::tangerbot_msgs::action::NavigateToPose_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::tangerbot_msgs::action::NavigateToPose_FeedbackMessage feedback(::tangerbot_msgs::action::NavigateToPose_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_FeedbackMessage msg_;
};

class Init_NavigateToPose_FeedbackMessage_goal_id
{
public:
  Init_NavigateToPose_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavigateToPose_FeedbackMessage_feedback goal_id(::tangerbot_msgs::action::NavigateToPose_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_NavigateToPose_FeedbackMessage_feedback(msg_);
  }

private:
  ::tangerbot_msgs::action::NavigateToPose_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tangerbot_msgs::action::NavigateToPose_FeedbackMessage>()
{
  return tangerbot_msgs::action::builder::Init_NavigateToPose_FeedbackMessage_goal_id();
}

}  // namespace tangerbot_msgs

#endif  // TANGERBOT_MSGS__ACTION__DETAIL__NAVIGATE_TO_POSE__BUILDER_HPP_
