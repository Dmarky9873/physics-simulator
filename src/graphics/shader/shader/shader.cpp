#include "shader.h"

Shader::Shader(const std::string shader_path, const u_int16_t shader_type)
{
    // Assigns values to the class variables
    path = CURRENT_WORKING_DIRECTORY + shader_path;
    type = shader_type;

    // Compiles the shader and checks if the compilation was successful
    compile_shader();
    check_shader_compilation();
}

char *Shader::read_shader_code()
{
    // Create a string to store the shader code and reads the shader file
    char *shader_code;
    std::ifstream shader_file;

    // Ensure ifstream objects can throw exceptions
    shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    // Use a try/catch block to catch any exceptions that occur when reading the file
    try
    {
        // Open the file
        shader_file.open(path);

        std::stringstream shader_stream;

        // Read file's buffer contents into variable
        shader_stream << shader_file.rdbuf();

        shader_file.close();

        // Convert stream into char*
        std::string tmp = shader_stream.str();
        shader_code = new char[tmp.length() + 1];
        std::strcpy(shader_code, tmp.data());
    }
    catch (std::ifstream::failure &e)
    {
        // If the file is not successfully read, print an error message and return an empty char*
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
        std::strcpy(shader_code, "");
    }

    return shader_code;
}

void Shader::compile_shader()
{
    // Read the shader code from the file
    const char *shader_code = read_shader_code();

    // Create the shader and compile it
    shader = glCreateShader(type);
    glShaderSource(shader, 1, &shader_code, NULL);
    glCompileShader(shader);
}

void Shader::check_shader_compilation()
{
    // Variables to store the success and the info log
    int success;
    char infolog[512];

    // Check if the shader compilation was successful
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    // If the compilation was not successful, print an error message
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infolog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n"
                  << infolog << std::endl;
    }
}