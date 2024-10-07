#include "input.h"

bool InputManager::is_key_pressed(GLFWwindow *window, int key)
{
    if (glfwGetKey(window, key) == GLFW_PRESS)
    {
        return true;
    }
    return false;
}