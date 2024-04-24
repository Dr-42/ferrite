# Define the executable target
file(GLOB TESTBED_SOURCES src/*.c)
file(GLOB TESTBED_HEADERS src/include/*.h)

add_executable(testbed ${TESTBED_SOURCES} ${TESTBED_HEADERS})

# Link the libraries
target_link_libraries(testbed PRIVATE ferritelog ferritewin)
