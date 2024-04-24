# Define the library target
file(GLOB LOG_SOURCES src/*.c)
file(GLOB LOG_HEADERS src/include/*.h)

add_library(ferritelog SHARED ${LOG_SOURCES} ${LOG_HEADERS})

# Specify include directories
target_include_directories(ferritelog PUBLIC src/include)
