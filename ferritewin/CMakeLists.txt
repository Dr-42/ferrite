# Define the library target
file(GLOB WIN_SOURCES src/*.c)
file(GLOB WIN_HEADERS src/include/*.h)

add_library(ferritewin SHARED ${WIN_SOURCES} ${WIN_HEADERS})

# Specify include directories
target_include_directories(ferritewin PUBLIC src/include)

# Link the ferritelog library
target_link_libraries(ferritewin PRIVATE ferritelog)

# Link system libraries based on the platform
if(WIN32)
    target_link_libraries(ferritewin PRIVATE vulkan-1)
elseif(UNIX AND NOT APPLE)
    target_link_libraries(ferritewin PRIVATE wayland-client vulkan)
endif()
