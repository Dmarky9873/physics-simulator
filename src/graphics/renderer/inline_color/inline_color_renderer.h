#ifndef INLINE_COLOR_RENDERER_H
#define INLINE_COLOR_RENDERER_H

#include "../../shader/program/shader_program.h"
#include <GLFW/glfw3.h>

#include <vector>
#include <string>
#include <glad/glad.h>
#include <iostream>
#include <map>

#define INLINE_VERTEX_SHADER_PATH "/src/graphics/shader/src/inline_color/vertex_shader.vert"
#define INLINE_FRAGMENT_SHADER_PATH "/src/graphics/shader/src/inline_color/fragment_shader.frag"

/**
 * @brief A basic renderer class
 *
 * Renders objects to the screen without an element buffer object
 */
class InlineColorRenderer
{
public:
    /**
     * @brief Sets the program for the renderer
     */
    InlineColorRenderer();

    /**
     * @brief Renders the object to the screen
     *
     * @param is_wireframe Whether the object should be rendered in wireframe mode or fill mode
     */
    void render(bool is_wireframe = false);

    /**
     * @brief Sets the vertices to be rendered
     *
     * Raises errors if the vertices data is not properly formatted for rendering
     *
     * @param vertices The vertices to be rendered
     */
    void set_vertices(const std::vector<std::vector<float>> &vertices, std::vector<glm::mat4> trans = {glm::mat4(1.0f)});

private:
    std::vector<glm::mat4> translations = {glm::mat4(1.0f)};

    /**
     * @brief The triangles to be rendered
     */
    std::vector<std::vector<float>>
        triangles;

    /**
     * @brief The number of triangles to be rendered
     */
    size_t num_triangles;

    ShaderProgram shader_program = ShaderProgram({Shader::create_shader(INLINE_VERTEX_SHADER_PATH, GL_VERTEX_SHADER), Shader::create_shader(INLINE_FRAGMENT_SHADER_PATH, GL_FRAGMENT_SHADER)});

    /**
     * @brief The vertex buffer object
     */
    unsigned int *VBOs;

    /**
     * @brief The vertex array object
     */
    unsigned int *VAOs;

    /**
     * @brief Initializes the vertex buffer object and vertex array object
     */
    void VBO_VAO_init();
};

#endif