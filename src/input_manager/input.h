#ifndef INPUT_MANAGER_INPUT_H
#define INPUT_MANAGER_INPUT_H

#include <GLFW/glfw3.h>

class InputManager
{
public:
    void process_input(GLFWwindow *window);
};

#endif