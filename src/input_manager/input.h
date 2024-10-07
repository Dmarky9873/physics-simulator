#ifndef INPUT_MANAGER_INPUT_H
#define INPUT_MANAGER_INPUT_H

#include <GLFW/glfw3.h>

class InputManager
{
public:
    /**
     * @brief Processes input from the user
     *
     * @param window The window to process input for
     */
    void process_input(GLFWwindow *window);
};

#endif