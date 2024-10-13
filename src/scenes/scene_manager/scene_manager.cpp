#include "scene_manager.h"

SceneManager::SceneManager(GLFWwindow *window)
{
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     // Enable docking

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();

    // Set the current scene to the start menu
    body = std::bind(&SceneManager::sc_start_menu, this);
}

// This should be called every frame in main loop
void SceneManager::show()
{
    // Configure ImGui style
    ImGui::StyleColorsDark();

    // Start the ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // Draw the current scene
    body();

    // Render everything at the end of the frame so imgui is always on top
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData()); // Renders the ImGui draw data
}

// Scenes

void SceneManager::sc_start_menu()
{
    // Create title of imgui popup
    ImGui::Begin("Choose an option");

    // UI elements
    ImGui::Text("Welcome to Physics Sim \n\nBy: Daniel Markusson");

    if (ImGui::Button("2D"))
    {
        // Change the scene if 2D is clicked
        body = std::bind(&SceneManager::sc_2d_selector, this);
    }

    // End the ImGui window
    ImGui::End();
}

void SceneManager::sc_2d_triangle_test()
{
    // Create your ImGui window and UI elements
    ImGui::Begin("Triangle Test");
    if (ImGui::Button("Back"))
    {
        // Change the scene
        body = std::bind(&SceneManager::sc_2d_selector, this);
    }

    // Slider for speed of triangle movement
    ImGui::SliderFloat("Speed Coefficient", &two_d_triangle_test_speed_coef, 0.1f, 10.0f);

    // Render triangles
    sc_2d_triangle_test_render(two_d_triangle_test_speed_coef);

    ImGui::End(); // End the ImGui window
}

void SceneManager::sc_2d_selector()
{
    // Create title of imgui popup
    ImGui::Begin("2D Selector");
    if (ImGui::Button("Back"))
    {
        // Change the scene if user wants to go back
        body = std::bind(&SceneManager::sc_start_menu, this);
    }

    // General UI elements
    ImGui::Text("Choose a 2D simulation");

    if (ImGui::Button("Triangle Test"))
    {
        // Change the scene if user wants to see the triangle test
        body = std::bind(&SceneManager::sc_2d_triangle_test, this);
    }

    // End the ImGui window
    ImGui::End();
}