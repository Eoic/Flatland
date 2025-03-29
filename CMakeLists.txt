cmake_minimum_required(VERSION 3.16)
project(Flatland VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)

# Main.
add_executable(Flatland flatland.c)

# Sources.
file(GLOB_RECURSE ENTITIES_SOURCES "entities/*.c")
file(GLOB_RECURSE UTILS_SOURCES "utils/*.c")
target_sources(Flatland PRIVATE ${ENTITIES_SOURCES} ${UTILS_SOURCES})
target_link_libraries(Flatland PRIVATE SDL3::SDL3 m)

# Libraries.
file(GLOB_RECURSE QUEUE_SOURCES "utils/queue/*.c")
add_library(queue STATIC ${QUEUE_SOURCES})
target_include_directories(queue PUBLIC utils/queue)
target_include_directories(Flatland PUBLIC "${PROJECT_BINARY_DIR}")

