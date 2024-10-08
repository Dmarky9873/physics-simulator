#ifndef BASIC_RENDERER_H
#define BASIC_RENDERER_H

#include "../../shader/program/shader_program.h"
#include <vector>
#include <string>
#include <glad/glad.h>
#include <iostream>

#define VERTEX_SHADER_PATH "/src/graphics/shader/src/vertex_shader.vert"
#define ORANGE_PATH "/src/graphics/shader/src/orange.frag"
#define RED_PATH "/src/graphics/shader/src/red.frag"
#define WHITE_PATH "/src/graphics/shader/src/white.frag"

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
    void set_vertices(const std::vector<std::vector<float>> &vertices);

    /**
     * @brief Changes the color of the object being rendered
     *
     * @param color The color to change the object to
     */
    void color_picker(std::string color);

private:
    /**
     * @brief The vertices to be rendered
     */
    std::vector<std::vector<float>> vertices;
    size_t num_triangles;

    /**
     * @brief The vertex buffer object
     */
    unsigned int *VBOs;

    /**
     * @brief The vertex array object
     */
    unsigned int *VAOs;

    /**
     * @brief Initializes the shader program
     */
    void
    program_init(std::vector<unsigned int> shaders);

    /**
     * @brief Initializes the vertex buffer object and vertex array object
     */
    void VBO_VAO_init();
};

#endif