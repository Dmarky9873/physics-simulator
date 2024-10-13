#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <string>
#include <functional>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include "../2d/2d_scenes.h"

class SceneManager
{
public:
    /**
     * @brief Constructor for the SceneManager class
     *
     * @param window The window to render scenes to
     */
    SceneManager(GLFWwindow *window);

    /**
     * @brief Shows the current scene
     */
    void show();

    /**
     * @brief The body of the scene
     *
     * This is a function pointer that points to the current scene
     */
    std::function<void()> body;

private:
    // Scene variables
    // 2D
    float two_d_triangle_test_speed_coef = 1;
    bool two_d_triangle_test_is_paused = false;

    // Scenes

    /**
     * @brief The start menu scene
     *
     * This scene is the first scene that is shown when the program starts
     */
    void sc_start_menu();

    // 2D

    /**
     * @brief The 2D selector scene
     *
     * This scene is where the user can select a 2D simulation to run
     */
    void sc_2d_selector();

    /**
     * @brief The 2D triangle test scene
     *
     * This scene is a test scene for general 2D rendering
     */
    void sc_2d_triangle_test();
};

#endif