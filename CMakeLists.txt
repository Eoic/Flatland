cmake_minimum_required(VERSION 3.16)
project(flatland)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)

add_executable(flatland WIN32 flatland.c entities/player.c entities/player.h)
target_link_libraries(flatland PRIVATE SDL3::SDL3)