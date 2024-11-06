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
     *
     * @param fps The frames per second to render the scenes at
     */
    SceneManager(GLFWwindow *window, float fps);

    /**
     * @brief Shows the current scene
     *
     * @param show_fps Whether or not to show the frames per second in the console
     */
    void show(bool show_fps = false);

    /**
     * @brief The body of the scene
     *
     * This is a function pointer that points to the current scene
     */
    std::function<void()> body;

private:
    // Utility functions

    /**
     * @brief Measures the frames per second of the program
     */
    void measure_fps();

    // Animation variables

    /**
     * @brief The current frame of the scene
     */
    int frame = 0;

    /**
     * @brief Whether or not the scene is paused
     */
    bool is_paused = false;

    /**
     * @brief The duration of a frame in seconds (1 / fps)
     */
    float frame_dur;

    /**
     * @brief The last time a frame was changed
     */
    float prev_time = glfwGetTime();

    /**
     * @brief The start time of the current scene
     */
    float start_time = glfwGetTime();

    // Animation functions

    /**
     * @brief Resets the scene
     *
     * This function resets the frame counter (to zero), start time (to the current time), and pause state (to false)
     */
    void reset();

    /**
     * @brief Steps the frame
     *
     * This function increments the frame counter if and only if the current scene is not paused
     * and if the elapsed time since the last frame increment is longer than the desired frame duration
     */
    void step_frame();

    /**
     * @brief Changes the current scene
     *
     * This function changes the current scene to the new scene along with resetting the frame counter, start time, and pause state
     *
     * @param new_scene The new scene to change to
     */
    void change_scene(const std::function<void()> &new_scene);

    // Scene variables: variables that are meant for individual scenes
    // 2D Scene Variables

    /**
     * @brief The speed coefficient of the triangles in the 2D triangle test scene
     */
    float two_d_triangle_test_speed_coef = 1;

    float two_d_projectile_motion_initial_velocity = 1.0f;

    float two_d_projectile_motion_gravitational_acceleration = 9.81f;

    float two_d_projectile_motion_launch_angle = 0.0f;

    // 3D Scene Variables

    // Scenes

    // 2D Scenes

    /**
     * @brief Class storing rendering data for all the 2D scenes
     */
    TwoDScenes two_d_scenes;

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

    void sc_2d_projectile_motion();

    // 2D Scene Elements
    void draw_angle_circle(ImDrawList *draw_list, ImVec2 center, float radius, float angle);
};

#endif