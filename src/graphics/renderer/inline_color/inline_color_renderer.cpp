#include "inline_color_renderer.h"

InlineColorRenderer::InlineColorRenderer()
{
    // Create the shader program and use it
    glUseProgram(shader_program.get_program());
}

void InlineColorRenderer::VBO_VAO_init()
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
        glBufferData(GL_ARRAY_BUFFER, triangles[i].size() * sizeof(float), triangles[i].data(), GL_DYNAMIC_DRAW);
        // Position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);
        // Color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }
}

void InlineColorRenderer::set_vertices(const std::vector<std::vector<float>> &vertices, std::vector<glm::mat4> trans)
{
    // Set the translation matrix
    translations = std::move(trans);

    // Gets the new vertices to be rendered and primes the vertex buffer objects and vertex array objects
    this->triangles = vertices;
    num_triangles = vertices.size();

    VBO_VAO_init();
}

void InlineColorRenderer::render(bool is_wireframe)
{
    // Set the polygon mode to wireframe or fill based on desire
    if (is_wireframe)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // Render the vertices
    for (int i = 0; i < num_triangles; i++)
    {
        // Gets the number of vertices
        size_t num_vertices = triangles[i].size();

        // Check if there are vertices to render or if there are an incorrect number of vertices data
        if (num_triangles == 0)
        {
            std::cout << "No triangles to render" << std::endl;
            return;
        }
        else if (num_vertices % 3 != 0)
        {
            std::cout << "ERROR::RENDER::NUM VERTICES DATA NOT MULTIPLE OF THREE" << std::endl;
            return;
        }

        if (i > translations.size())
            shader_program.setMat4f("transform", glm::mat4(1.0f));
        else
            shader_program.setMat4f("transform", translations[i]);

        // Render the vertices
        glBindVertexArray(VAOs[i]);
        glDrawArrays(GL_TRIANGLES, 0, 18 /*num_vertices*/ / 3);
        glBindVertexArray(VAOs[i]);
        glDrawArrays(GL_TRIANGLES, 0, 18 /*num_vertices*/ / 3);
    }
}