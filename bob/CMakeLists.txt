cmake_minimum_required(VERSION 3.0.0)
project(bob VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/inc)

add_library(bob src/bob.cpp)