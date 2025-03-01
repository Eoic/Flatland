cmake_minimum_required(VERSION 3.16)
project(flatland)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)

add_executable(flatland flatland.c)

file(GLOB ENTITIES_SOURCES "entities/*.c")
file(GLOB UTILS_SOURCES "utils/*.c")
target_sources(flatland PRIVATE ${ENTITIES_SOURCES} ${UTILS_SOURCES})

target_link_libraries(flatland PRIVATE SDL3::SDL3 m)