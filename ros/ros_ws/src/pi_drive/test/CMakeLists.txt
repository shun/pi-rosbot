#find_package(ament_lint_auto REQUIRED)
# the following line skips the linter which checks for copyrights
# uncomment the line when a copyright and license is not present in all source files
#set(ament_cmake_copyright_FOUND TRUE)
# the following line skips cpplint (only works in a git repo)
# uncomment the line when this package is not in a git repo
#set(ament_cmake_cpplint_FOUND TRUE)
#ament_lint_auto_find_test_dependencies()

find_package(ament_cmake_gtest REQUIRED)


ament_add_gtest(
  test_piDriveController
  ./test_piDriveController_go_straight.cpp
  #  ./test_piDriveController_go_right.cpp
  #  ./test_piDriveController_go_left.cpp
  #  ./test_piDriveController_turn_right.cpp
  #  ./test_piDriveController_turn_left.cpp
)

target_link_libraries(
  test_piDriveController
  rclcpp
  rclcpp_lifecycle
  std_msgs
  geometry_msgs
)

ament_target_dependencies(
  test_piDriveController
  rclcpp
  rclcpp_lifecycle
  std_msgs
  geometry_msgs
)
