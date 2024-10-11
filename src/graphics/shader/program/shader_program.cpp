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


void ShaderProgram::setBool(const std::string &name, bool value)
{
    glUniform1i(glGetUniformLocation(program, name.c_str()), (int)value);
}

void ShaderProgram::setInt(const std::string &name, int value)
{
    glUniform1i(glGetUniformLocation(program, name.c_str()), value);
}

void ShaderProgram::setFloat(const std::string &name, float value)
{
    glUniform1f(glGetUniformLocation(program, name.c_str()), value);
}

void ShaderProgram::setMat4f(const std::string &name, const glm::mat4 &value)
{
    glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}