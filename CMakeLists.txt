cmake_minimum_required(VERSION 3.29)
project(physics_simulator)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable and source files (including glad.c for GLAD)
add_executable(physics_simulator
    src/main.cpp
    include/glad/glad.c
    src/window_manager/window.cpp
    src/input_manager/input.cpp
    src/graphics/shader/shader/shader.cpp
    src/graphics/shader/program/shader_program.cpp
    src/graphics/renderer/basic/basic_renderer.cpp
    src/graphics/renderer/inline_color/inline_color_renderer.cpp

    # Dear ImGui core source files
    include/imgui/imgui_demo.cpp
    include/imgui/imgui_draw.cpp
    include/imgui/imgui_widgets.cpp
    include/imgui/imgui.cpp
    include/imgui/imgui_tables.cpp

    # Dear ImGui backend source files
    include/imgui/imgui_impl_glfw.cpp
    include/imgui/imgui_impl_opengl3.cpp

    # Scenes
    src/scenes/scene_manager/scene_manager.cpp
    src/scenes/2d/2d_scenes.cpp
)


target_include_directories(physics_simulator PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
)

# Link directories for the GLFW library
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Find OpenGL (required for linking)
find_package(OpenGL REQUIRED)

# Link libraries and frameworks to the executable
target_link_libraries(physics_simulator 
    OpenGL::GL
    ${CMAKE_SOURCE_DIR}/lib/libglfw3.a
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreFoundation"
    "-framework AppKit"
)

# Set macOS deployment target
set(CMAKE_OSX_DEPLOYMENT_TARGET "15.0")