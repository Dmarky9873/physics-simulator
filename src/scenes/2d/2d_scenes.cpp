#include "2d_scenes.h"

void sc_2d_triangle_test_render(float speed_coef)
{
    // Creates an instance of the renderer class
    InlineColorRenderer inline_color_renderer;

    // Creates the vertices for the triangles
    std::vector<std::vector<float>> vertices = {{// positions         // colors
                                                 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
                                                 -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
                                                 0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f},
                                                {// positions         // colors
                                                 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
                                                 -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
                                                 0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f},

                                                {// positions         // colors
                                                 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
                                                 -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
                                                 0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f}};

    // Gets the time value so that the triangles can perform actions as a function of time
    float time_value = glfwGetTime();
    float spin = sin(time_value * 0.5f * speed_coef) * 360.0f;

    // Creates the transformation matrices for the triangles and sets them to a placebo value
    glm::mat4 trans1 = glm::mat4(1.0f);
    glm::mat4 trans2 = glm::mat4(1.0f); // Will remain as a placebo value to show what happens when no transformation is applied
    glm::mat4 trans3 = glm::mat4(1.0f);

    // Applies the transformations to the transformation matrices
    trans1 = glm::translate(trans1, glm::vec3(-0.5f, -0.5f, 0.0f));
    trans1 = glm::rotate(trans1, (glm::radians(spin)), glm::vec3(0.0f, 0.0f, 1.0f));
    trans1 = glm::scale(trans1, glm::vec3(0.5f, 0.5f, 0.5f));

    trans3 = glm::translate(trans3, glm::vec3(sin(time_value * speed_coef), 0.0f, 0.0f));
    trans3 = glm::scale(trans3, glm::vec3(0.25f, 0.25f, 0.25f));

    // Renders the triangles
    inline_color_renderer.set_vertices(vertices, {trans1, trans2, trans3});
    inline_color_renderer.render(false);
}