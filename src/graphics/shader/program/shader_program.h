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
     * @brief Creates the shader program
     */
    static unsigned int create_program(const std::vector<unsigned int> &shaders);
};

#endif