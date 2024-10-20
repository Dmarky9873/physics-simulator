#include <iostream>

#include "window_manager/window.h"
#include "input_manager/input.h"
#include "scenes/scene_manager/scene_manager.h"

#define ONE_HUNDRED_TWENTY_FPS 1.0f / 120.0f
#define SIXTY_FPS 1.0f / 60.0f
#define THIRTY_FPS 1.0f / 30.0f
#define FIFTEEN_FPS 1.0f / 15.0f

int main()
{
    WindowManager window_manager;
    GLFWwindow *window = window_manager.createWindow(WindowManager::DEFAULT_WIDTH, WindowManager::DEFAULT_HEIGHT, WindowManager::DEFAULT_TITLE, false);
    SceneManager scene_manager = SceneManager(window, ONE_HUNDRED_TWENTY_FPS);

    if (!window)
    {
        return -1;
    }

    while (!glfwWindowShouldClose(window))
    {
        // Input
        // Closes the window if the escape key is pressed
        if (InputManager::is_key_pressed(window, GLFW_KEY_ESCAPE))
        {
            glfwSetWindowShouldClose(window, true);
        }

        // Render
        scene_manager.show(false); // FPS measurement does not work

        // Check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up
    window_manager.terminate();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    return 0;
}