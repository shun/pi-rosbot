message("### rclcpp_INCLUDE_DIRS: ${rclcpp_INCLUDE_DIRS}")

include_directories(
  include
  ${rclcpp_INCLUDE_DIRS}
  ../include
)

ament_add_gtest(
  test_piDriveController
  ./test_piDriveController_go_straight.cpp
  #  ./test_piDriveController_go_right.cpp
  #  ./test_piDriveController_go_left.cpp
  #  ./test_piDriveController_turn_right.cpp
  #  ./test_piDriveController_turn_left.cpp
)
ament_target_dependencies(
    test_piDriveController
    rclcpp
    std_msgs
    geometry_msgs
)

