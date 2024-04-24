cmake_minimum_required(VERSION 3.10)
project(ferrite)

# Set default build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -std=c2x")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0 -DFDEBUG")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add subdirectories for each module
add_subdirectory(ferritelog)
add_subdirectory(ferritewin)
add_subdirectory(testbed)

add_custom_target(
	run
    COMMAND testbed  # Replace 'testbed' with the name of your executable
    DEPENDS testbed  # Replace 'testbed' with the name of your executable
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Running the program"
)
