cmake_minimum_required(VERSION 3.5)
project(pi_drive)

# Default to C99
#if(NOT CMAKE_C_STANDARD)
#  set(CMAKE_C_STANDARD 99)
#endif()

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

#ament_auto_find_build_dependencies(REQUIRED ${geometry_msgs_INCLUDE_DIRS})

include_directories(
  include
  ${rclcpp_INCLUDE_DIRS}
  ${rclcpp_components_INCLUDE_DIRS}
  ${rclcpp_lifecycle_INCLUDE_DIRS}
  ${std_msgs_INCLUDE_DIRS}
  ${geometry_msgs_INCLUDE_DIRS}
)

add_subdirectory(src)

if(BUILD_TESTING)
    #add_subdirectory(test)
endif()

ament_package()
