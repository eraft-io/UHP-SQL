cmake_minimum_required(VERSION 3.8)

project(parser)

list(APPEND parser_sources bison_parser.cpp)
list(APPEND parser_sources expr.cc)
list(APPEND parser_sources flex_lexer.cpp)
list(APPEND parser_sources prepare_statement.cpp)
list(APPEND parser_sources sql_parser_result.cpp)
list(APPEND parser_sources sql_parser.cpp)
list(APPEND parser_sources sql_statement.cpp)
list(APPEND parser_sources sqlhelper.cpp)
list(APPEND parser_sources statements.cpp)

set(parser_INCLUDE_DIR ${parser_sources_SOURCE_DIR})

add_library(parser ${parser_sources})
target_include_directories(parser PUBLIC ${parser_INCLUDE_DIR})

add_executable(parser_demo example.cpp)
target_include_directories(parser_demo PUBLIC ${parser_demo_INCLUDE_DIR})
target_link_libraries(parser_demo parser)
