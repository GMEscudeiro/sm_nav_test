#ifndef SM_NAV_TEST__CLIENTS__CB_HAS_TASK_HPP_
#define SM_NAV_TEST__CLIENTS__CB_HAS_TASK_HPP_

#include "sm_nav_test/ros2_orch_client/cl_ros2_orch.hpp"
#include "sm_nav_test/ros2_orch_client/components/cp_goal_storage.hpp"
#include "smacc2/smacc_client_behavior_base.hpp"
namespace cl_ros2_orch {

class CbHasTask : public smacc2::ISmaccClientBehavior {
public:
  CbHasTask() {}
  void onEntry() override {
    RCLCPP_INFO(getLogger(), "CbSendGoal::onEntry()");
    this->requiresComponent(cp_goal_storage_);
    this->requiresClient(cl_ros2_orch_);
    if (cp_goal_storage_->hasTask() == true) {
      cl_ros2_orch_->post_task_received_event_();
    }
  }

private:
  cl_ros2_orch::CpGoalStorage *cp_goal_storage_;
  sm_nav_test::ClRos2Orch *cl_ros2_orch_;
};
} // namespace cl_ros2_orch
#endif // SM_NAV_TEST__CLIENTS__CB_HAS_TASK_HPP_
