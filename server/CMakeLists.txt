cmake_minimum_required(VERSION 3.8)

project(uhpsqld)

add_executable(uhpsqld uhpsqld.cpp)
target_link_libraries(uhpsqld parser hiredis_static)
