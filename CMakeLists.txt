cmake_minimum_required(VERSION 3.10)
project(ferrite)

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
