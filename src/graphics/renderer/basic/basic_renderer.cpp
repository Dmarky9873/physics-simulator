#include "basic_renderer.h"

BasicRenderer::BasicRenderer()
{
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
        glBufferData(GL_ARRAY_BUFFER, triangles[i].size() * sizeof(float), triangles[i].data(), GL_DYNAMIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);
    }
}

void BasicRenderer::set_vertices(const std::vector<std::vector<float>> &vertices)
{
    // Gets the new vertices to be rendered and primes the vertex buffer objects and vertex array objects
    this->triangles = vertices;
    num_triangles = vertices.size();

    VBO_VAO_init();
}

void BasicRenderer::render(bool is_wireframe, std::vector<std::string> colors)
{
    // Set the background color
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Gets the number of colors
    size_t num_colors = colors.size();

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

        // Uses the last used color if there isn't enough colors
        if (i > num_colors)
        {
            glUseProgram(COLORS[colors[num_colors]]);
        }
        else
        {
            glUseProgram(COLORS[colors[i]]);
        }
        // float timeValue = glfwGetTime();
        // float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
        // int vertexColorLocation = glGetUniformLocation(COLORS["white"], "our_color");
        // glUseProgram(COLORS["white"]);
        // glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

        // Render the vertices
        glBindVertexArray(VAOs[i]);
        glDrawArrays(GL_TRIANGLES, 0, num_vertices / 3);
    }
}