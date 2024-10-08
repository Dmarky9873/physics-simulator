#ifndef BASIC_RENDERER_H
#define BASIC_RENDERER_H

#include "../../shader/program/shader_program.h"
#include <vector>
#include <string>
#include <glad/glad.h>
#include <iostream>
#include <map>

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
    BasicRenderer();
    /**
     * @brief Renders the object to the screen
     *
     * @param is_wireframe Whether the object should be rendered in wireframe mode or fill mode
     */
    void render(bool is_wireframe = false, std::vector<std::string> colors = {"white"});

    /**
     * @brief Sets the vertices to be rendered
     *
     * Also ensures the vertices data is properly formatted for rendering
     *
     * @param vertices The vertices to be rendered
     */
    void set_vertices(const std::vector<std::vector<float>> &vertices);

private:
    /**
     * @brief The vertices to be rendered
     */
    std::vector<std::vector<float>> triangles;
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

    /**
     * @brief The colors that can be used
     *
     * The key is the color name and the value is the shader program
     */
    std::map<std::string, unsigned int> COLORS =
        {
            {"orange", ShaderProgram::create_program({Shader::create_shader(VERTEX_SHADER_PATH, GL_VERTEX_SHADER), Shader::create_shader(ORANGE_PATH, GL_FRAGMENT_SHADER)})},
            {"red", ShaderProgram::create_program({Shader::create_shader(VERTEX_SHADER_PATH, GL_VERTEX_SHADER), Shader::create_shader(RED_PATH, GL_FRAGMENT_SHADER)})},
            {"white", ShaderProgram::create_program({Shader::create_shader(VERTEX_SHADER_PATH, GL_VERTEX_SHADER), Shader::create_shader(WHITE_PATH, GL_FRAGMENT_SHADER)})},
            {"red", 1},
    };
};

#endif