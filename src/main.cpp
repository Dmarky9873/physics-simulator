#include <iostream>

#include "window_manager/window.h"
#include "input_manager/input.h"

int main()
{
    WindowManager window_manager;
    GLFWwindow *window = window_manager.createWindow(800, 600, "LearnOpenGL");
    InputManager input_manager;

    if (!window)
    {
        return -1;
    }

    while (!glfwWindowShouldClose(window))
    {
        // Input
        input_manager.process_input(window);

        // Rendering commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    window_manager.terminate();

    return 0;
}