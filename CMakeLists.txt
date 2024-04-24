cmake_minimum_required(VERSION 3.10)
project(ferrite)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add subdirectories for each module
add_subdirectory(ferritelog)
add_subdirectory(ferritewin)
add_subdirectory(testbed)
