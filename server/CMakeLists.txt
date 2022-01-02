cmake_minimum_required(VERSION 3.8)

project(uhpsqld)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(uhpsqld uhpsqld.cpp)
target_link_libraries(uhpsqld parser hiredis_static executor network pthread)
