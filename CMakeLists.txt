cmake_minimum_required(VERSION 3.16)
project(flatland)
enable_testing()

include(CTest)
include(FetchContent)

FetchContent_Declare(
    unity
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
    GIT_TAG v2.6.1
)

FetchContent_MakeAvailable(unity)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
add_executable(flatland flatland.c)

# Project executable.
file(GLOB_RECURSE ENTITIES_SOURCES "entities/*.c")
file(GLOB_RECURSE UTILS_SOURCES "utils/*.c")
target_sources(flatland PRIVATE ${ENTITIES_SOURCES} ${UTILS_SOURCES})
target_link_libraries(flatland PRIVATE SDL3::SDL3 m)

# Libraries.
file(GLOB_RECURSE QUEUE_SOURCES "utils/queue/*.c")
add_library(queue STATIC ${QUEUE_SOURCES})
target_include_directories(queue PUBLIC utils/queue)

# Tests.
file(GLOB_RECURSE TEST_SOURCES "tests/*.c")

foreach(TEST_FILE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_FILE})
    target_link_libraries(${TEST_NAME} PRIVATE unity queue)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()