#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include "../shader/shader.h"
#include <vector>
#include <string>
#include <glad/glad.h>
#include <iostream>

/**
 * @brief A class to manage shader programs
 */
class ShaderProgram
{
public:
    /**
     * @brief Constructor for the ShaderProgram class
     *
     * Creates a shader program from a list of shaders
     *
     * @param shaders A vector of shaders to create the program from
     */
    ShaderProgram(const std::vector<unsigned int> &shaders);

    /**
     * @brief Gets the shader program (its ID)
     *
     * @return The shader program's ID
     */
    unsigned int get_program() { return program; }

private:
    /**
     * @brief The shader program's ID
     */
    unsigned int program;

    /**
     * @brief The shaders to be used within the program
     */
    std::vector<unsigned int> shaders;

    /**
     * @brief Creates the shader program
     */
    void create_program();
};

#endif