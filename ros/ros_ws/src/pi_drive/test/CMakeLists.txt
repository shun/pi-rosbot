include_directories(
  include
  ${rclcpp_INCLUDE_DIRS}
)

ament_add_gtest(
  test_piDriveController
  test_piDriveController.cpp
)

#ament_target_dependencies(
#  test_piDriveController
#  ${dependencies}
#)

target_link_libraries(
  test_piDriveController
  ${rclcpp_LIBRARIES}
)

