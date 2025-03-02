cmake_minimum_required(VERSION 3.16)
project(flatland)
enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
# find_package(CMocka REQUIRED)

# Define your project targets
add_executable(flatland flatland.c)

# Define the test target (use the correct name for the test executable)
# add_executable(queue_test tests/test_queue.c utils/queue/queue.c)

# Add other sources for the flatland target
file(GLOB_RECURSE ENTITIES_SOURCES "entities/*.c")
file(GLOB_RECURSE UTILS_SOURCES "utils/*.c")
target_sources(flatland PRIVATE ${ENTITIES_SOURCES} ${UTILS_SOURCES})

# Link CMocka to the queue_test target (not "test_queue")
# target_link_libraries(queue_test PRIVATE cmocka)

# Add the test to CTest
# add_test(NAME queue_test COMMAND queue_test)

# Create a custom target to run tests
# add_custom_target(run_tests
#     COMMAND ${CMAKE_CTEST_COMMAND}
#     DEPENDS queue_test
# )

# Link libraries for the flatland executable
target_link_libraries(flatland PRIVATE SDL3::SDL3 m)
