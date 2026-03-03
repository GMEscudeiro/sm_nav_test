#pragma once

#include <geometry_msgs/msg/pose.hpp>
#include <smacc2/component.hpp>

namespace cl_ros2_orch {

class CpGoalStorage : public smacc2::ISmaccComponent {
public:
  CpGoalStorage() {};

  void onInitialize() override {
    RCLCPP_INFO(getLogger(), "CpGoalStorage initialization");
    this->requiresClient(ros2OrchClient_);
    ros2OrchClient_->onMessageReceived(&CpGoalStorage::setTask, this);
  }

  void setTask(const geometry_msgs::msg::Pose &pose) {
    pose_ = pose;
    has_task_ = true;
    ros2OrchClient_->post_task_received_event_();
  }

  geometry_msgs::msg::Pose popPose() {
    has_task_ = false;
    return pose_;
  }

  bool hasTask() { return has_task_; };

private:
  sm_nav_test::ClRos2Orch *ros2OrchClient_;
  geometry_msgs::msg::Pose pose_;
  bool has_task_ = false;
};
} // namespace cl_ros2_orch
