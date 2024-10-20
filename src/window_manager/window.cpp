#include "window.h"
#include <iostream>

const char *WindowManager::DEFAULT_TITLE = "Physics Sim";

GLFWwindow *WindowManager::createWindow(int width, int height, const char *title, bool resizable)
{
    // Initialize GLFW
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return nullptr;
    }

    // Configure GLFW (version 3.3, core profile)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // For macOS compatibility
    glfwWindowHint(GLFW_RESIZABLE, resizable);

    // Create the window
    GLFWwindow *window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }

    // Make the window's context the current context
    glfwMakeContextCurrent(window);

    // Load GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return nullptr;
    }

    // Update viewport size when the window is resized
    if (resizable)
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    return window;
}

void WindowManager::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    // Set the viewport size to the new window size
    glViewport(0, 0, width, height);
}

void WindowManager::terminate()
{
    glfwTerminate();
}