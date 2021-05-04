cmake_minimum_required(VERSION 3.17)

file(GLOB_RECURSE SOURCE_LINKLIST "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADER_LINKLIST "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

include_directories(./include')

add_executable(link_list ${SOURCE_LINKLIST})
target_include_directories(link_list PUBLIC include)