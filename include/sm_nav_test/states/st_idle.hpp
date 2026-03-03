#include "sm_nav_test/ros2_orch_client/client_behaviors/cb_has_task.hpp"
#include <smacc2/smacc.hpp>

namespace sm_nav_test {
using namespace cl_ros2_timer;
using namespace smacc2::default_transition_tags;

// STATE DECLARATION
struct Idle : smacc2::SmaccState<Idle, SmNavTest> {
  using SmaccState::SmaccState;

  // TRANSITION TABLE
  typedef mpl::list<

      Transition<EvTaskReceived<ClRos2Orch, OrRos2Orch>, StGoalSend, SUCCESS>

      >
      reactions;

  // STATE FUNCTIONS
  static void staticConfigure() {
    configure_orthogonal<OrRos2Orch, cl_ros2_orch::CbHasTask>();
  }

  void runtimeConfigure() {}

  void onEntry() { RCLCPP_INFO(getLogger(), "On Entry!"); }

  void onExit() { RCLCPP_INFO(getLogger(), "On Exit!"); }
};
} // namespace sm_nav_test
