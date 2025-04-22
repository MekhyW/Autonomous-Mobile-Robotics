// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:action/Aula9.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__ACTION__DETAIL__AULA9__BUILDER_HPP_
#define CUSTOM_INTERFACES__ACTION__DETAIL__AULA9__BUILDER_HPP_

#include "custom_interfaces/action/detail/aula9__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_Aula9_Goal_count_up_to
{
public:
  Init_Aula9_Goal_count_up_to()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::action::Aula9_Goal count_up_to(::custom_interfaces::action::Aula9_Goal::_count_up_to_type arg)
  {
    msg_.count_up_to = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::Aula9_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::Aula9_Goal>()
{
  return custom_interfaces::action::builder::Init_Aula9_Goal_count_up_to();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_Aula9_Result_final_count
{
public:
  Init_Aula9_Result_final_count()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::action::Aula9_Result final_count(::custom_interfaces::action::Aula9_Result::_final_count_type arg)
  {
    msg_.final_count = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::Aula9_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::Aula9_Result>()
{
  return custom_interfaces::action::builder::Init_Aula9_Result_final_count();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_Aula9_Feedback_current_number
{
public:
  Init_Aula9_Feedback_current_number()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::action::Aula9_Feedback current_number(::custom_interfaces::action::Aula9_Feedback::_current_number_type arg)
  {
    msg_.current_number = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::Aula9_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::Aula9_Feedback>()
{
  return custom_interfaces::action::builder::Init_Aula9_Feedback_current_number();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_Aula9_SendGoal_Request_goal
{
public:
  explicit Init_Aula9_SendGoal_Request_goal(::custom_interfaces::action::Aula9_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::action::Aula9_SendGoal_Request goal(::custom_interfaces::action::Aula9_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::Aula9_SendGoal_Request msg_;
};

class Init_Aula9_SendGoal_Request_goal_id
{
public:
  Init_Aula9_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Aula9_SendGoal_Request_goal goal_id(::custom_interfaces::action::Aula9_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Aula9_SendGoal_Request_goal(msg_);
  }

private:
  ::custom_interfaces::action::Aula9_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::Aula9_SendGoal_Request>()
{
  return custom_interfaces::action::builder::Init_Aula9_SendGoal_Request_goal_id();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_Aula9_SendGoal_Response_stamp
{
public:
  explicit Init_Aula9_SendGoal_Response_stamp(::custom_interfaces::action::Aula9_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::action::Aula9_SendGoal_Response stamp(::custom_interfaces::action::Aula9_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::Aula9_SendGoal_Response msg_;
};

class Init_Aula9_SendGoal_Response_accepted
{
public:
  Init_Aula9_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Aula9_SendGoal_Response_stamp accepted(::custom_interfaces::action::Aula9_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Aula9_SendGoal_Response_stamp(msg_);
  }

private:
  ::custom_interfaces::action::Aula9_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::Aula9_SendGoal_Response>()
{
  return custom_interfaces::action::builder::Init_Aula9_SendGoal_Response_accepted();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_Aula9_GetResult_Request_goal_id
{
public:
  Init_Aula9_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::action::Aula9_GetResult_Request goal_id(::custom_interfaces::action::Aula9_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::Aula9_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::Aula9_GetResult_Request>()
{
  return custom_interfaces::action::builder::Init_Aula9_GetResult_Request_goal_id();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_Aula9_GetResult_Response_result
{
public:
  explicit Init_Aula9_GetResult_Response_result(::custom_interfaces::action::Aula9_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::action::Aula9_GetResult_Response result(::custom_interfaces::action::Aula9_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::Aula9_GetResult_Response msg_;
};

class Init_Aula9_GetResult_Response_status
{
public:
  Init_Aula9_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Aula9_GetResult_Response_result status(::custom_interfaces::action::Aula9_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Aula9_GetResult_Response_result(msg_);
  }

private:
  ::custom_interfaces::action::Aula9_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::Aula9_GetResult_Response>()
{
  return custom_interfaces::action::builder::Init_Aula9_GetResult_Response_status();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace action
{

namespace builder
{

class Init_Aula9_FeedbackMessage_feedback
{
public:
  explicit Init_Aula9_FeedbackMessage_feedback(::custom_interfaces::action::Aula9_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::action::Aula9_FeedbackMessage feedback(::custom_interfaces::action::Aula9_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::action::Aula9_FeedbackMessage msg_;
};

class Init_Aula9_FeedbackMessage_goal_id
{
public:
  Init_Aula9_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Aula9_FeedbackMessage_feedback goal_id(::custom_interfaces::action::Aula9_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Aula9_FeedbackMessage_feedback(msg_);
  }

private:
  ::custom_interfaces::action::Aula9_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::action::Aula9_FeedbackMessage>()
{
  return custom_interfaces::action::builder::Init_Aula9_FeedbackMessage_goal_id();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__ACTION__DETAIL__AULA9__BUILDER_HPP_
