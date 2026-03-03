#include "sm_nav_test/ros2_orch_client/cl_ros2_orch.hpp"
#include "sm_nav_test/ros2_orch_client/components/cp_goal_storage.hpp"
#include <smacc2/smacc.hpp>

using namespace std::chrono_literals;

namespace sm_nav_test {
using namespace std::chrono_literals;
class OrRos2Orch : public smacc2::Orthogonal<OrRos2Orch> {
public:
  void onInitialize() override {
    auto client = this->createClient<sm_nav_test::ClRos2Orch>();
    client->createComponent<cl_ros2_orch::CpGoalStorage>();
  }
};
} // namespace sm_nav_test
