cmake_minimum_required(VERSION 3.17)
project(algorithm_and_data_structure)

set(CMAKE_CXX_STANDARD 17)
#include(cmake/CPMSimple.cmake)


# UsingRepo(googletest "https://github.com/google/googletest.git")
enable_testing()
find_package(GTest CONFIG REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory(recusive-and-backtrack)
add_subdirectory(link-list)

add_executable(algorithm_and_data_structure main.cpp)