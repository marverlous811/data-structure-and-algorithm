cmake_minimum_required(VERSION 3.17)
project(algorithm_and_data_structure)

set(CMAKE_CXX_STANDARD 17)
#include(cmake/CPMSimple.cmake)

if(APPLE)
    if(DEFINED ENV{VCPKG_ROOT})
        set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
                CACHE STRING "")
        message(" [INFO] VCPKG CMAKE_TOOLCHAIN_FILE = ${CMAKE_TOOLCHAIN_FILE}")
        set(CMAKE_PREFIX_PATH "$ENV{VCPKG_ROOT}/installed/x64-osx")
    endif()
endif()

# UsingRepo(googletest "https://github.com/google/googletest.git")
if (APPLE)
    message("INFO ${CMAKE_PREFIX_PATH}")
    find_package(GTest CONFIG REQUIRED)
else()
    find_package(GTest CONFIG REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})
endif ()
enable_testing()

add_subdirectory(recusive-and-backtrack)
add_subdirectory(link-list)

add_executable(algorithm_and_data_structure main.cpp)