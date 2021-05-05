cmake_minimum_required(VERSION 3.17)

file(GLOB_RECURSE SOURCE_LINKLIST "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADER_LINKLIST "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE TEST_LINKLIST "${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp")

include_directories(./include')

add_executable(link_list ${SOURCE_LINKLIST})
target_include_directories(link_list PUBLIC include)

add_executable(linklist-test ${TEST_LINKLIST})
target_include_directories(linklist-test PUBLIC include)
target_link_libraries(linklist-test PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)