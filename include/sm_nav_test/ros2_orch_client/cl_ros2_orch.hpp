#ifndef SM_NAV_TEST__CLIENTS__CL_ORCH_CLIENT_HPP_
#define SM_NAV_TEST__CLIENTS__CL_ORCH_CLIENT_HPP_

#include "geometry_msgs/msg/pose.hpp"
#include "smacc2/client_bases/smacc_subscriber_client.hpp"

namespace sm_nav_test {

using namespace smacc2::client_bases;

template <typename TSource, typename TOrthogonal>
struct EvTaskReceived : sc::event<EvTaskReceived<TSource, TOrthogonal>> {};

class ClRos2Orch : public SmaccSubscriberClient<geometry_msgs::msg::Pose> {
public:
  ClRos2Orch() : SmaccSubscriberClient<geometry_msgs::msg::Pose>("task_pose") {}

  template <typename TOrthogonal, typename TSourceObject>
  void onStateOrthogonalAllocation() {
    post_task_received_event_ = [this]() {
      RCLCPP_INFO(getLogger(), "ClRos2Orch::post_task_received_event_");
      this->postEvent<EvTaskReceived<TSourceObject, TOrthogonal>>();
    };
    SmaccSubscriberClient<geometry_msgs::msg::Pose>::
        onStateOrthogonalAllocation<TOrthogonal, TSourceObject>();
  }

  std::function<void()> post_task_received_event_;
};

} // namespace sm_nav_test

#endif
