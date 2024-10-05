#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class WindowManager
{
public:
    /**
     * @brief Creates a window using GLFW
     *
     * @param width The width of the window
     * @param height The height of the window
     * @param title The title of the window
     */
    GLFWwindow *createWindow(int width, int height, const char *title);

    /**
     * @brief Terminates GLFW and cleans up resources.
     */
    void terminate();

private:
    /**
     * @brief Callback function for when the window is resized
     *
     * @param window The window that was resized
     * @param width The new width of the window
     * @param height The new height of the window
     */
    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
};

#endif