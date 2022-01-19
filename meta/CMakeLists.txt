cmake_minimum_required(VERSION 3.8)

project(meta)

list(APPEND meta_sources database.cc)
list(APPEND meta_sources datatable.cc)
list(APPEND meta_sources tablecolumn.cc)
list(APPEND meta_sources dbms.cc)


set(meta_INCLUDE_DIR ${meta_sources_SOURCE_DIR})

add_library(meta ${meta_sources})
target_include_directories(meta PUBLIC ${meta_INCLUDE_DIR})
target_link_libraries(meta  hiredis_static parser network)
