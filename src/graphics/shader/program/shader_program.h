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
    ShaderProgram(const std::vector<Shader> &shaders);

    unsigned int get_program() { return program; }

private:
    // Shader program ID
    unsigned int program;

    std::vector<Shader> shaders;

    void create_program();
};

#endif