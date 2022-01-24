cmake_minimum_required(VERSION 3.8)
project(talktoqt)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# find the header files
include_directories(include/talktoqt)

add_executable(qttalker src/publisher.cpp)
ament_target_dependencies(qttalker rclcpp std_msgs)




install(TARGETS
  qttalker
  DESTINATION lib/${PROJECT_NAME})


# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)


ament_package()
