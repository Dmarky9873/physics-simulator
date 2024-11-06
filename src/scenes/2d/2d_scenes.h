#ifndef TWO_D_SCENES_H
#define TWO_D_SCENES_H

#include <string>
#include <functional>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "../../graphics/renderer/inline_color/inline_color_renderer.h"
#include "../../window_manager/window.h"
#include "objects/object2d.h"
#include "../../physics/2d_physics/2d_physics.h"

class TwoDScenes
{
public:
    /**
     * @brief Renders a 2D triangle test scene
     *
     * Meant to be used as a test to see if 2D rendering is working
     *
     * @param speed_coef The speed coefficient of the triangle (subject to change based on a slider)
     * @param frame The current frame counter of the program
     * @param frame_duration The duration of a frame in seconds (1 / fps)
     */
    void sc_2d_triangle_test_render(float speed_coef, int frame, float frame_duration);

    void sc_2d_projectile_motion_render(float initial_velocity, int frame, float frame_duration);

private:
    glm::mat4 blank_translation = glm::mat4(1.0f);

    /**
     * @brief The renderer for the 2D scenes
     */
    InlineColorRenderer inline_color_renderer;
    void render(std::vector<Object2D>, bool is_wireframe = false);
};

#endif