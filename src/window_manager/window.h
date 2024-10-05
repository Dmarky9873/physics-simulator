#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class WindowManager
{
public:
    GLFWwindow *createWindow(int width, int height, const char *title);
    void terminate(); // Handles cleanup and termination of GLFW
};

#endif