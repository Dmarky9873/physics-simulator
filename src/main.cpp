#include <iostream>

#include "window_manager/window.h"
#include "input_manager/input.h"
#include "graphics/shader/shader/shader.h"

#define VERTEX_SHADER_PATH "/src/graphics/shader/src/vertex_shader.vert"
#define FRAGMENT_SHADER_PATH "/src/graphics/shader/src/fragment_shader.frag"

void draw();

int main()
{
    WindowManager window_manager;
    GLFWwindow *window = window_manager.createWindow(WindowManager::DEFAULT_WIDTH, WindowManager::DEFAULT_HEIGHT, WindowManager::DEFAULT_TITLE);
    InputManager input_manager;

    if (!window)
    {
        return -1;
    }

    while (!glfwWindowShouldClose(window))
    {
        // Input
        input_manager.process_input(window);

        // Rendering commands
        draw();

        // Check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    window_manager.terminate();

    return 0;
}

void draw()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    float vertices[] = {
        0.5f, 0.5f, 0.0f,   // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f   // top left
    };
    unsigned int indices[] = {
        // note that we start from 0!
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    unsigned int EBO;
    glGenBuffers(1, &EBO);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    Shader vertex_shader(VERTEX_SHADER_PATH, GL_VERTEX_SHADER);

    Shader fragment_shader(FRAGMENT_SHADER_PATH, GL_FRAGMENT_SHADER);

    unsigned int shader_program;
    shader_program = glCreateProgram();

    glAttachShader(shader_program, vertex_shader.get_shader());
    glAttachShader(shader_program, fragment_shader.get_shader());
    glLinkProgram(shader_program);

    glUseProgram(shader_program);
    glDeleteShader(vertex_shader.get_shader());
    glDeleteShader(fragment_shader.get_shader());

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    // 1. bind Vertex Array Object
    glBindVertexArray(VAO);
    // 2. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // 3. then set our vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // ..:: Drawing code (in render loop) :: ..
    // 4. draw the object
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // wireframe mode
    // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // fill mode
    glUseProgram(shader_program);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    // glDrawArrays(GL_TRIANGLES, 0, 3);
}