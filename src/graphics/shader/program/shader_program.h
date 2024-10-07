#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include <string>
#include <glad/glad.h>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>

/**
 * @brief A class to manage shader programs
 */
class ShaderProgram
{
public:
    ShaderProgram(const std::string vertex_shader_path, const std::string fragment_shader_path);
    // Shader program ID
    unsigned int program;

private:
};

#endif