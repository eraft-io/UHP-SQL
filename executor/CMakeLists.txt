cmake_minimum_required(VERSION 3.8)

project(executor)

list(APPEND executor_sources create_executor.cpp)
list(APPEND executor_sources delete_executor.cpp)
list(APPEND executor_sources executor.cpp)
list(APPEND executor_sources insert_executor.cpp)
list(APPEND executor_sources select_executor.cpp)
list(APPEND executor_sources update_executor.cpp)


set(executor_INCLUDE_DIR ${executor_sources_SOURCE_DIR})

add_library(executor ${executor_sources})
target_include_directories(executor PUBLIC ${executor_INCLUDE_DIR})
target_link_libraries(executor hiredis_static parser network)
