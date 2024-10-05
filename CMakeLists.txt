cmake_minimum_required(VERSION 3.29)
project(physics_simulator)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable and source files (including glad.c for GLAD)
add_executable(physics_simulator
    src/main.cpp
    src/third_party/glad.c
    src/window_manager/window.cpp
    src/input_manager/input.cpp
)

# Add include directories for GLAD and GLFW
include_directories(${CMAKE_SOURCE_DIR}/include)

# Link directories for GLFW library
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Link OpenGL and GLFW
find_package(OpenGL REQUIRED)
target_link_libraries(physics_simulator OpenGL::GL)

# Link GLFW library statically from the lib directory
target_link_libraries(physics_simulator ${CMAKE_SOURCE_DIR}/lib/libglfw3.a)

# Link macOS system frameworks
target_link_libraries(physics_simulator
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreFoundation"
    "-framework AppKit"
)