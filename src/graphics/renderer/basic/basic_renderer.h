#ifndef BASIC_RENDERER_H
#define BASIC_RENDERER_H

#include "../../shader/program/shader_program.h"
#include <vector>
#include <string>
#include <glad/glad.h>
#include <iostream>

#define VERTEX_SHADER_PATH "/src/graphics/shader/src/vertex_shader.vert"
#define FRAGMENT_SHADER_PATH "/src/graphics/shader/src/fragment_shader.frag"

/**
 * @brief A basic renderer class
 *
 * Renders objects to the screen without an element buffer object
 */
class BasicRenderer
{
public:
    /**
     * @brief Constructor for the BasicRenderer class
     *
     * Sets the background color along with initializing the shader program, vertex buffer object, and vertex array object
     */
    BasicRenderer();

    /**
     * @brief Renders the object to the screen
     *
     * @param is_wireframe Whether the object should be rendered in wireframe mode or fill mode
     */
    void render(bool is_wireframe);

    /**
     * @brief Sets the vertices to be rendered
     *
     * Also ensures the vertices data is properly formatted for rendering
     *
     * @param vertices The vertices to be rendered
     */
    void set_vertices(const std::vector<float> &vertices);

private:
    /**
     * @brief The vertices to be rendered
     */
    std::vector<float> vertices;

    /**
     * @brief Initializes the shader program
     */
    void program_init();

    /**
     * @brief Initializes the vertex buffer object
     */
    void VBO_init();

    /**
     * @brief Initializes the vertex array object
     */
    void VAO_init();
};

#endif