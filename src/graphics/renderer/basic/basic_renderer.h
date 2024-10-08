#ifndef BASIC_RENDERER_H
#define BASIC_RENDERER_H

#include "../../shader/program/shader_program.h"
#include <GLFW/glfw3.h>

#include <vector>
#include <string>
#include <glad/glad.h>
#include <iostream>
#include <map>

// Shader paths
#define BASIC_VERTEX_SHADER_PATH "/src/graphics/shader/src/basic/vertex_shader.vert"
#define ORANGE_FRAGMENT_SHADER_PATH "/src/graphics/shader/src/basic/orange.frag"
#define RED_FRAGMENT_SHADER_PATH "/src/graphics/shader/src/basic/red.frag"
#define WHITE_FRAGMENT_SHADER_PATH "/src/graphics/shader/src/basic/white.frag"

/**
 * @brief A basic renderer class
 *
 * Renders objects to the screen without an element buffer object
 */
class BasicRenderer
{
public:
    /**
     * @brief Renders the object to the screen
     *
     * @param is_wireframe Whether the object should be rendered in wireframe mode or fill mode
     * @param colors The colors to be used for rendering. Each color matches to a triangle in the
     * `triangles` array. The colors must be in the COLORS map. If there are not enough colors,
     * the last color will be used for the remaining objects. If there are too many colors, the
     * extra colors will be ignored.
     */
    void render(bool is_wireframe = false, std::vector<std::string> colors = {"white"});

    /**
     * @brief Sets the vertices to be rendered
     *
     * Also ensures the vertices data is properly formatted for rendering
     *
     * @param vertices 2D array where each array is a triangle and each triangle has 3 vertices
     */
    void set_vertices(const std::vector<std::vector<float>> &vertices);

private:
    /**
     * @brief The vertices to be rendered
     */
    std::vector<std::vector<float>> triangles;

    /**
     * @brief The number of triangles to be rendered
     */
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
     * @brief Initializes the vertex buffer object and vertex array object
     */
    void VBO_VAO_init();

    /**
     * @brief The colors that can be used
     *
     * The key is the color name and the value is the shader program
     */
    std::map<std::string, unsigned int> COLORS =
        {
            {"orange", ShaderProgram::create_program({Shader::create_shader(BASIC_VERTEX_SHADER_PATH, GL_VERTEX_SHADER), Shader::create_shader(ORANGE_FRAGMENT_SHADER_PATH, GL_FRAGMENT_SHADER)})},
            {"red", ShaderProgram::create_program({Shader::create_shader(BASIC_VERTEX_SHADER_PATH, GL_VERTEX_SHADER), Shader::create_shader(RED_FRAGMENT_SHADER_PATH, GL_FRAGMENT_SHADER)})},
            {"white", ShaderProgram::create_program({Shader::create_shader(BASIC_VERTEX_SHADER_PATH, GL_VERTEX_SHADER), Shader::create_shader(WHITE_FRAGMENT_SHADER_PATH, GL_FRAGMENT_SHADER)})},
    };
};

#endif