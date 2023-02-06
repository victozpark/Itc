cmake_minimum_required(VERSION 3.9)

project(Itc VERSION 0.8.0 DESCRIPTION "Inter thread communication")

set(CMAKE_CXX_STANDARD 11)

file(GLOB LIB_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB INC_FILES ${CMAKE_SOURCE_DIR}/include/*)

add_library(Itc SHARED ${LIB_SOURCES})

set_target_properties(Itc PROPERTIES VERSION ${PROJECT_VERSION})

target_include_directories(Itc PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_compile_options(Itc PRIVATE -Wall -Werror)

install(TARGETS Itc DESTINATION ${CMAKE_SOURCE_DIR}/release/lib)
install(FILES ${INC_FILES} DESTINATION ${CMAKE_SOURCE_DIR}/release/include)
