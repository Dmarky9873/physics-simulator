#include "basic_renderer.h"

BasicRenderer::BasicRenderer()
{
    // Default to white color
    color_picker("white");
}

void BasicRenderer::program_init(std::vector<unsigned int> shaders)
{
    // Create the shader program
    ShaderProgram shader_program(shaders);

    // Use the shader program when rendering
    glUseProgram(shader_program.get_program());
}

void BasicRenderer::color_picker(std::string color)
{
    Shader vertex_shader(VERTEX_SHADER_PATH, GL_VERTEX_SHADER);

    if (color == "orange")
    {
        // Create the fragment shader
        Shader fragment_shader(ORANGE_PATH, GL_FRAGMENT_SHADER);

        // Initialize the shader program
        program_init({vertex_shader.get_shader(), fragment_shader.get_shader()});
    }
    else
    {
        // Create the fragment shader
        Shader fragment_shader(WHITE_PATH, GL_FRAGMENT_SHADER);

        // Initialize the shader program
        program_init({vertex_shader.get_shader(), fragment_shader.get_shader()});
    }
}

void BasicRenderer::VBO_VAO_init()
{
    // Create the vertex buffer object
    VBOs = new unsigned int[num_triangles];
    glGenBuffers(num_triangles, VBOs);

    // Create the vertex array object
    VAOs = new unsigned int[num_triangles];
    glGenVertexArrays(num_triangles, VAOs);

    // Bind the vertex array object and vertex buffer object
    for (int i = 0; i < num_triangles; i++)
    {
        glBindVertexArray(VAOs[i]);
        glBindBuffer(GL_ARRAY_BUFFER, VBOs[i]);
        glBufferData(GL_ARRAY_BUFFER, vertices[i].size() * sizeof(float), vertices[i].data(), GL_DYNAMIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);
    }
}

void BasicRenderer::set_vertices(const std::vector<std::vector<float>> &vertices)
{
    // Gets the new vertices to be rendered and primes the vertex buffer objects and vertex array objects
    this->vertices = vertices;
    num_triangles = vertices.size();

    VBO_VAO_init();
}

void BasicRenderer::render(bool is_wireframe)
{
    // Set the background color
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the polygon mode to wireframe or fill based on desire
    if (is_wireframe)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // Check if there are vertices to render or if there are an incorrect number of vertices data

    // Render the vertices
    for (int i = 0; i < num_triangles; i++)
    {
        size_t num_vertices = vertices[i].size();
        if (num_triangles == 0)
        {
            std::cout << "No vertices to render" << std::endl;
            return;
        }
        else if (num_vertices % 3 != 0)
        {
            std::cout << "ERROR::RENDER::NUM VERTICES DATA NOT MULTIPLE OF THREE" << std::endl;
            return;
        }
        glBindVertexArray(VAOs[i]);
        glDrawArrays(GL_TRIANGLES, 0, num_vertices / 3);
    }
}