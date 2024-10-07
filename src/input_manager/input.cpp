#include "input.h"

void InputManager::check_for_keypress(GLFWwindow *window, uint8_t key)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}