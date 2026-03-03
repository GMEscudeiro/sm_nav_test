#include <sm_nav_test/sm_nav_test.hpp>

//--------------------------------------------------------------------
int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  smacc2::run<sm_nav_test::SmNavTest>();
}
