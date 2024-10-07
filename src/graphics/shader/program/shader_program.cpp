#include "shader_program.h"

ShaderProgram::ShaderProgram(const std::vector<unsigned int> &shaders)
{
    // Assign the shaders to the class variable and create the program
    this->shaders = shaders;
    create_program();
}

void ShaderProgram::create_program()
{
    // Create the shader program and assign the ID to `program`
    program = glCreateProgram();

    // Attach each shader to the program
    for (unsigned int shader : shaders)
    {
        glAttachShader(program, shader);
    }

    // Link the program and set it as the current program
    glLinkProgram(program);
    glUseProgram(program);

    // Delete the shaders
    for (unsigned int shader : shaders)
    {
        glDeleteShader(shader);
    }
}