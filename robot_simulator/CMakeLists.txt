cmake_minimum_required(VERSION 3.0.0)
project(robot_simulator VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/inc)

add_library(robot_simulator src/robot_simulator.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)