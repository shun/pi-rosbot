add_library(
    piDriveController SHARED
  ./piMotorController_main.cpp
  ./piDriveController.cpp

)

ament_target_dependencies(
  piDriveController
  rclcpp
  rclcpp_lifecycle
  std_msgs
  geometry_msgs
)

ament_export_interfaces(
  export_piDriveController
)

ament_export_dependencies(
  piDriveController
  rclcpp
)

target_include_directories(
  piDriveController
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_executable(
    piDriveController_node
  ./piMotorController_main.cpp
)

ament_target_dependencies(
  piDriveController_node
  piDriveController
  rclcpp
  rclcpp_lifecycle
)
install(
  DIRECTORY ../include/
  DESTINATION include
)

install(
  TARGETS piDriveController
  EXPORT export_piDriveController
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

install(
    TARGETS piDriveController_node
    DESTINATION bin/${PROJECT_NAME}
)
