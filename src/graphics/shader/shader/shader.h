#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glad/glad.h>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>

/**
 * @brief A class to manage shaders
 */
class Shader
{
public:
    /**
     * @brief Constructor for the Shader class
     *
     * Compiles a shader from code in `shader_path`.
     *
     * @param shader_path The path to the shader source code file
     * @param shader_type The type of shader (uses OpenGL constants)
     */
    Shader(const std::string shader_path, const u_int16_t shader_type);

    /**
     * @brief Gets the shader (its program ID)
     *
     * @return The shader's ID
     */
    unsigned int get_shader() { return shader; }

private:
    /**
     * @brief The shader's program ID
     */
    unsigned int shader;

    /**
     * @brief The path to the shader source code file
     */
    std::string path;

    /**
     * @brief The type of shader (uses OpenGL constants)
     */
    u_int16_t type;

    /**
     * @brief The current working directory of the program
     */
    std::string CURRENT_WORKING_DIRECTORY = std::__fs::filesystem::current_path();

    /**
     * @brief Reads the shader code from the source code file and returns it as a char*
     *
     * @return The shader code as a char*
     */
    char *read_shader_code();

    /**
     * @brief Compiles the shader, setting `shader` to the shader's program ID.
     *
     * The shader code is read from the source code file and compiled.
     */
    void compile_shader();

    /**
     * @brief Checks if the shader compilation was successful
     *
     * If the shader compilation was not successful, an error message is printed.
     */
    void check_shader_compilation();
};

#endif