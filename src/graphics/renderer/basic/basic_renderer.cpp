#include "basic_renderer.h"

BasicRenderer::BasicRenderer()
{
    // Set the background color
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Initialize the shader program, vertex buffer object, and vertex array object
    program_init();
    VBO_init();
    VAO_init();
}

void BasicRenderer::program_init()
{
    // Create the vertex and fragment shaders
    Shader vertex_shader(VERTEX_SHADER_PATH, GL_VERTEX_SHADER);
    Shader fragment_shader(FRAGMENT_SHADER_PATH, GL_FRAGMENT_SHADER);

    // Create the shader program
    ShaderProgram shader_program({vertex_shader.get_shader(), fragment_shader.get_shader()});

    // Use the shader program when rendering
    glUseProgram(shader_program.get_program());
}

void BasicRenderer::VBO_init()
{
    // Create the vertex buffer object
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void BasicRenderer::VAO_init()
{
    // Create the vertex array object
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
}

void BasicRenderer::set_vertices(const std::vector<float> &vertices)
{
    // Gets the new vertices to be rendered
    this->vertices = vertices;

    // Copy vertices array in buffer for graphics card to use
    glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(float), this->vertices.data(), GL_DYNAMIC_DRAW);

    // Set our vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
}

void BasicRenderer::render(bool is_wireframe)
{
    // Set the polygon mode to wireframe or fill based on desire
    if (is_wireframe)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    size_t vertices_len = vertices.size();

    // Check if there are vertices to render or if there are an incorrect number of vertices data
    if (vertices_len == 0)
    {
        std::cout << "No vertices to render" << std::endl;
        return;
    }
    else if (vertices_len % 3 != 0)
    {
        std::cout << "ERROR::RENDER::NUM VERTICES DATA NOT MULTIPLE OF THREE" << std::endl;
        return;
    }

    // Render the vertices
    glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 3);
}