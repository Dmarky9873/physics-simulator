#ifndef TWO_D_SCENES_H
#define TWO_D_SCENES_H

#include <string>
#include <functional>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "../../graphics/renderer/inline_color/inline_color_renderer.h"

/**
 * @brief Renders a 2D triangle test scene
 *
 * Meant to be used as a test to see if 2D rendering is working
 */
void sc_2d_triangle_test_render();

#endif