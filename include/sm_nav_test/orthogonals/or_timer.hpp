#include <chrono>
#include <cl_ros2_timer/cl_ros2_timer.hpp>
#include <smacc2/smacc.hpp>

using namespace std::chrono_literals;

namespace sm_nav_test {
using namespace std::chrono_literals;
class OrTimer : public smacc2::Orthogonal<OrTimer> {
public:
  void onInitialize() override {
    auto client = this->createClient<cl_ros2_timer::ClRos2Timer>(1s);
  }
};
} // namespace sm_nav_test
