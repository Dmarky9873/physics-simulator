#include <iostream>

#include "window_manager/window.h"
#include "input_manager/input.h"
#include "graphics/shader/shader/shader.h"
#include "graphics/shader/program/shader_program.h"
#include "graphics/renderer/basic/basic_renderer.h"
#include "graphics/renderer/inline_color/inline_color_renderer.h"

void draw();

int main()
{
    WindowManager window_manager;
    GLFWwindow *window = window_manager.createWindow(WindowManager::DEFAULT_WIDTH, WindowManager::DEFAULT_HEIGHT, WindowManager::DEFAULT_TITLE);
    BasicRenderer basic_renderer;
    InlineColorRenderer inline_color_renderer;

    std::vector<std::vector<float>> vertices = {{
        // positions         // colors
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // top
    }};
    std::vector<std::string> colors = {"white", "white"};

    if (!window)
    {
        return -1;
    }

    while (!glfwWindowShouldClose(window))
    {
        // Input
        if (InputManager::is_key_pressed(window, GLFW_KEY_ESCAPE))
        {
            glfwSetWindowShouldClose(window, true);
        }

        // Rendering commands
        // basic_renderer.set_vertices(vertices);
        // basic_renderer.render(false, {"red", "white"});

        inline_color_renderer.set_vertices(vertices);
        inline_color_renderer.render(false);

        // Check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    window_manager.terminate();

    return 0;
}

void draw()
{

    // std::vector<float> vertices = {
    //     // first triangle
    //     0.5f, 0.5f, 0.0f,   // top right
    //     0.5f, -0.5f, 0.0f,  // bottom right
    //     -0.5f, 0.5f, 0.0f,  // top left
    //                         // second triangle
    //     0.5f, -0.5f, 0.0f,  // bottom right
    //     -0.5f, -0.5f, 0.0f, // bottom left
    //     -0.5f, 0.5f, 0.0f   // top left
    // };
    // unsigned int indices[] = {
    //     // note that we start from 0!
    //     0, 1, 3, // first triangle
    //     1, 2, 3  // second triangle
    // };

    // unsigned int EBO;
    // glGenBuffers(1, &EBO);

    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    // BasicRenderer renderer;

    // renderer.set_vertices(vertices);

    // renderer.render(true);
}