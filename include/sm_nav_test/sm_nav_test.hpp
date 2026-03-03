#include <smacc2/smacc.hpp>

// CLIENTS
#include <cl_ros2_timer/cl_ros2_timer.hpp>
#include <nav2z_client/nav2z_client.hpp>
#include <sm_nav_test/ros2_orch_client/cl_ros2_orch.hpp>

// CLIENT BEHAVIORS
#include "ros2_orch_client/client_behaviors/cb_has_task.hpp"
#include "ros2_orch_client/client_behaviors/cb_nav_to_storage_pose.hpp"
#include <cl_ros2_timer/client_behaviors/cb_timer_countdown_loop.hpp>
#include <cl_ros2_timer/client_behaviors/cb_timer_countdown_once.hpp>

// ORTHOGONALS
#include "orthogonals/or_navigation.hpp"
#include "orthogonals/or_ros_orch.hpp"
#include "orthogonals/or_timer.hpp"

using namespace boost;
using namespace smacc2;

namespace sm_nav_test {
// STATE
class StIdle;
class StState1;
class StGoalSend;

//--------------------------------------------------------------------
// STATE_MACHINE
struct SmNavTest : public smacc2::SmaccStateMachineBase<SmNavTest, StIdle> {
  using SmaccStateMachineBase::SmaccStateMachineBase;

  virtual void onInitialize() override {
    this->createOrthogonal<OrTimer>();
    this->createOrthogonal<OrRos2Orch>();
    this->createOrthogonal<OrNavigation>();
  }
};

} // namespace sm_nav_test

#include "states/st_goal_send.hpp"
#include "states/st_idle.hpp"
#include "states/st_state_1.hpp"
