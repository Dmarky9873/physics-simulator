#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include "../shader/shader.h"
#include <vector>
#include <string>
#include <glad/glad.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/**
 * @brief A class to manage shader programs
 */
class ShaderProgram
{
public:
    /**
     * @brief Creates a shader program
     * 
     * Creates a shader program and assigns the ID to `program`
     *
     * @param shaders The shaders to be used in the program
     */
    ShaderProgram(const std::vector<unsigned int> &shaders) : program(create_program(shaders)) {}

    /**
     * @brief Creates a shader program statically—without an instance of the class.
     * 
     * @param shaders The shaders to be used in the program
     */
    static unsigned int create_program(const std::vector<unsigned int> &shaders);

    /**
     * @brief Gets the program ID
     * 
     * @return The program
     */
    unsigned int get_program() { return program; }

    /**
     * @brief Sets a boolean uniform
     * 
     * @param name The name of the uniform to be modified
     * @param value The value to set the uniform to
     */
    void setBool(const std::string &name, bool value);

    /**
     * @brief Sets an integer uniform
     * 
     * @param name The name of the uniform to be modified
     * @param value The value to set the uniform to
     */
    void setInt(const std::string &name, int value);

    /**
     * @brief Sets a float uniform
     * 
     * @param name The name of the uniform to be modified
     * @param value The value to set the uniform to
     */
    void setFloat(const std::string &name, float value);

    /**
     * @brief Sets a 4x4 matrix uniform
     * 
     * @param name The name of the uniform to be modified
     * @param value The value to set the uniform to
     */
    void setMat4f(const std::string &name, const glm::mat4 &value);

private:
    /**
     * @brief The program ID
     */
    unsigned int program;


};

#endif