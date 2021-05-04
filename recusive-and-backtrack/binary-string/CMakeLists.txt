cmake_minimum_required(VERSION 3.17)

set(SOURCE_FILES main.cpp generator.h generator.cpp)
set(TEST_SOURCE test.cpp generator.h generator.cpp)

add_executable(binary-string ${SOURCE_FILES})

add_executable(binary-string-test ${TEST_SOURCE})
target_link_libraries(binary-string-test PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)