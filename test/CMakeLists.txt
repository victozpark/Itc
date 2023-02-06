cmake_minimum_required(VERSION 3.9)

project(Itc_TEST VERSION 0.0.0 DESCRIPTION "Test program")

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/../release/include)
link_directories(${CMAKE_SOURCE_DIR}/../release/lib)
link_libraries (-lpthread -lItc)


add_executable(main Main.cpp MyService.cpp)