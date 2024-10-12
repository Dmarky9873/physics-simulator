#include <iostream>

#include "window_manager/window.h"
#include "input_manager/input.h"
#include "graphics/shader/shader/shader.h"
#include "graphics/shader/program/shader_program.h"
#include "graphics/renderer/basic/basic_renderer.h"
#include "graphics/renderer/inline_color/inline_color_renderer.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

void draw();

int main()
{
    WindowManager window_manager;
    GLFWwindow *window = window_manager.createWindow(WindowManager::DEFAULT_WIDTH, WindowManager::DEFAULT_HEIGHT, WindowManager::DEFAULT_TITLE);
    BasicRenderer basic_renderer;
    InlineColorRenderer inline_color_renderer;

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
    ImGui_ImplOpenGL3_Init();

    std::vector<std::vector<float>> vertices = {{
        // positions         // colors
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // top
    }};
    std::vector<std::string> colors = {"white", "white"};

    if (!window)
    {
        return -1;
    }

    while (!glfwWindowShouldClose(window))
    {

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::ShowDemoWindow(); // Show demo window! :)

        // Input
        if (InputManager::is_key_pressed(window, GLFW_KEY_ESCAPE))
        {
            glfwSetWindowShouldClose(window, true);
        }

        // Rendering commands
        // basic_renderer.set_vertices(vertices);
        // basic_renderer.render(false, {"red", "white"});

        inline_color_renderer.set_vertices(vertices);
        inline_color_renderer.render(false);

        // Rendering
        // (Your code clears your framebuffer, renders your other stuff etc.)
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        // (Your code calls glfwSwapBuffers() etc.)

        // Check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    window_manager.terminate();

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    return 0;
}

void draw()
{

    // std::vector<float> vertices = {
    //     // first triangle
    //     0.5f, 0.5f, 0.0f,   // top right
    //     0.5f, -0.5f, 0.0f,  // bottom right
    //     -0.5f, 0.5f, 0.0f,  // top left
    //                         // second triangle
    //     0.5f, -0.5f, 0.0f,  // bottom right
    //     -0.5f, -0.5f, 0.0f, // bottom left
    //     -0.5f, 0.5f, 0.0f   // top left
    // };
    // unsigned int indices[] = {
    //     // note that we start from 0!
    //     0, 1, 3, // first triangle
    //     1, 2, 3  // second triangle
    // };

    // unsigned int EBO;
    // glGenBuffers(1, &EBO);

    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    // BasicRenderer renderer;

    // renderer.set_vertices(vertices);

    // renderer.render(true);
}