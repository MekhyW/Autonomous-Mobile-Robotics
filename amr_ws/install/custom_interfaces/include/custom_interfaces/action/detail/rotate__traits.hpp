// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:action/Rotate.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__ACTION__DETAIL__ROTATE__TRAITS_HPP_
#define CUSTOM_INTERFACES__ACTION__DETAIL__ROTATE__TRAITS_HPP_

#include "custom_interfaces/action/detail/rotate__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::action::Rotate_Goal>()
{
  return "custom_interfaces::action::Rotate_Goal";
}

template<>
inline const char * name<custom_interfaces::action::Rotate_Goal>()
{
  return "custom_interfaces/action/Rotate_Goal";
}

template<>
struct has_fixed_size<custom_interfaces::action::Rotate_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_interfaces::action::Rotate_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_interfaces::action::Rotate_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::action::Rotate_Result>()
{
  return "custom_interfaces::action::Rotate_Result";
}

template<>
inline const char * name<custom_interfaces::action::Rotate_Result>()
{
  return "custom_interfaces/action/Rotate_Result";
}

template<>
struct has_fixed_size<custom_interfaces::action::Rotate_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_interfaces::action::Rotate_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_interfaces::action::Rotate_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::action::Rotate_Feedback>()
{
  return "custom_interfaces::action::Rotate_Feedback";
}

template<>
inline const char * name<custom_interfaces::action::Rotate_Feedback>()
{
  return "custom_interfaces/action/Rotate_Feedback";
}

template<>
struct has_fixed_size<custom_interfaces::action::Rotate_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_interfaces::action::Rotate_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_interfaces::action::Rotate_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "custom_interfaces/action/detail/rotate__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::action::Rotate_SendGoal_Request>()
{
  return "custom_interfaces::action::Rotate_SendGoal_Request";
}

template<>
inline const char * name<custom_interfaces::action::Rotate_SendGoal_Request>()
{
  return "custom_interfaces/action/Rotate_SendGoal_Request";
}

template<>
struct has_fixed_size<custom_interfaces::action::Rotate_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<custom_interfaces::action::Rotate_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<custom_interfaces::action::Rotate_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<custom_interfaces::action::Rotate_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<custom_interfaces::action::Rotate_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::action::Rotate_SendGoal_Response>()
{
  return "custom_interfaces::action::Rotate_SendGoal_Response";
}

template<>
inline const char * name<custom_interfaces::action::Rotate_SendGoal_Response>()
{
  return "custom_interfaces/action/Rotate_SendGoal_Response";
}

template<>
struct has_fixed_size<custom_interfaces::action::Rotate_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<custom_interfaces::action::Rotate_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<custom_interfaces::action::Rotate_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::action::Rotate_SendGoal>()
{
  return "custom_interfaces::action::Rotate_SendGoal";
}

template<>
inline const char * name<custom_interfaces::action::Rotate_SendGoal>()
{
  return "custom_interfaces/action/Rotate_SendGoal";
}

template<>
struct has_fixed_size<custom_interfaces::action::Rotate_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_interfaces::action::Rotate_SendGoal_Request>::value &&
    has_fixed_size<custom_interfaces::action::Rotate_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_interfaces::action::Rotate_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_interfaces::action::Rotate_SendGoal_Request>::value &&
    has_bounded_size<custom_interfaces::action::Rotate_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<custom_interfaces::action::Rotate_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<custom_interfaces::action::Rotate_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_interfaces::action::Rotate_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::action::Rotate_GetResult_Request>()
{
  return "custom_interfaces::action::Rotate_GetResult_Request";
}

template<>
inline const char * name<custom_interfaces::action::Rotate_GetResult_Request>()
{
  return "custom_interfaces/action/Rotate_GetResult_Request";
}

template<>
struct has_fixed_size<custom_interfaces::action::Rotate_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<custom_interfaces::action::Rotate_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<custom_interfaces::action::Rotate_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "custom_interfaces/action/detail/rotate__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::action::Rotate_GetResult_Response>()
{
  return "custom_interfaces::action::Rotate_GetResult_Response";
}

template<>
inline const char * name<custom_interfaces::action::Rotate_GetResult_Response>()
{
  return "custom_interfaces/action/Rotate_GetResult_Response";
}

template<>
struct has_fixed_size<custom_interfaces::action::Rotate_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<custom_interfaces::action::Rotate_Result>::value> {};

template<>
struct has_bounded_size<custom_interfaces::action::Rotate_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<custom_interfaces::action::Rotate_Result>::value> {};

template<>
struct is_message<custom_interfaces::action::Rotate_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::action::Rotate_GetResult>()
{
  return "custom_interfaces::action::Rotate_GetResult";
}

template<>
inline const char * name<custom_interfaces::action::Rotate_GetResult>()
{
  return "custom_interfaces/action/Rotate_GetResult";
}

template<>
struct has_fixed_size<custom_interfaces::action::Rotate_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_interfaces::action::Rotate_GetResult_Request>::value &&
    has_fixed_size<custom_interfaces::action::Rotate_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_interfaces::action::Rotate_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_interfaces::action::Rotate_GetResult_Request>::value &&
    has_bounded_size<custom_interfaces::action::Rotate_GetResult_Response>::value
  >
{
};

template<>
struct is_service<custom_interfaces::action::Rotate_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<custom_interfaces::action::Rotate_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_interfaces::action::Rotate_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "custom_interfaces/action/detail/rotate__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::action::Rotate_FeedbackMessage>()
{
  return "custom_interfaces::action::Rotate_FeedbackMessage";
}

template<>
inline const char * name<custom_interfaces::action::Rotate_FeedbackMessage>()
{
  return "custom_interfaces/action/Rotate_FeedbackMessage";
}

template<>
struct has_fixed_size<custom_interfaces::action::Rotate_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<custom_interfaces::action::Rotate_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<custom_interfaces::action::Rotate_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<custom_interfaces::action::Rotate_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<custom_interfaces::action::Rotate_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<custom_interfaces::action::Rotate>
  : std::true_type
{
};

template<>
struct is_action_goal<custom_interfaces::action::Rotate_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<custom_interfaces::action::Rotate_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<custom_interfaces::action::Rotate_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // CUSTOM_INTERFACES__ACTION__DETAIL__ROTATE__TRAITS_HPP_
