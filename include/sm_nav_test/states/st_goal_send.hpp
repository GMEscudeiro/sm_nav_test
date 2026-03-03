#include <smacc2/smacc.hpp>

namespace sm_nav_test {
using namespace cl_ros2_timer;
using namespace smacc2::default_transition_tags;

// STATE DECLARATION
struct StGoalSend : smacc2::SmaccState<StGoalSend, SmNavTest> {
  using SmaccState::SmaccState;

  // TRANSITION TABLE
  typedef mpl::list<

      Transition<EvCbSuccess<cl_ros2_orch::CbNavToStoragePose, OrNavigation>,
                 StState1, SUCCESS>

      >
      reactions;

  // STATE FUNCTIONS
  static void staticConfigure() {
    configure_orthogonal<OrNavigation, cl_ros2_orch::CbNavToStoragePose>();
  }

  void runtimeConfigure() { RCLCPP_INFO(getLogger(), "Entering State1"); }

  void onEntry() { RCLCPP_INFO(getLogger(), "On Entry!"); }

  void onExit() { RCLCPP_INFO(getLogger(), "On Exit!"); }
};
} // namespace sm_nav_test
