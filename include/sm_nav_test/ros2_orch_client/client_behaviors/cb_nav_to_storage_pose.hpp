#pragma once

#include <geometry_msgs/msg/pose.hpp>

#include "nav2z_client/client_behaviors/cb_navigate_global_position.hpp"

namespace cl_ros2_orch {

class CbNavToStoragePose : public cl_nav2z::CbNavigateGlobalPosition {
public:
  CbNavToStoragePose() {};

  void onEntry() override {
    this->requiresComponent(cp_goal_storage_);

    if (cp_goal_storage_ && cp_goal_storage_->hasTask()) {
      auto target_pose = cp_goal_storage_->popPose();

      RCLCPP_INFO(getLogger(),
                  "CbNavToStoragePose: Configurando goal vindo do Storage.");

      this->setGoal(target_pose);
    } else {
      RCLCPP_ERROR(
          getLogger(),
          "CbNavToStoragePose: Tentativa de navegar sem tarefa no storage!");
    }

    cl_nav2z::CbNavigateGlobalPosition::onEntry();
  }

  cl_ros2_orch::CpGoalStorage *cp_goal_storage_;
};

} // namespace cl_ros2_orch
