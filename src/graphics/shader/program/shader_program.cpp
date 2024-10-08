#include "shader_program.h"

unsigned int ShaderProgram::create_program(const std::vector<unsigned int> &shaders)
{
    // Create the shader program and assign the ID to `program`
    unsigned int program = glCreateProgram();

    // Attach each shader to the program
    for (unsigned int shader : shaders)
    {
        glAttachShader(program, shader);
    }

    // Link the program and set it as the current program
    glLinkProgram(program);

    // Delete the shaders
    for (unsigned int shader : shaders)
    {
        glDeleteShader(shader);
    }

    return program;
}