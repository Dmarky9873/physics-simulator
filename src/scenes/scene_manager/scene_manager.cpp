#include "scene_manager.h"

SceneManager::SceneManager(GLFWwindow *window, float frame_duration)
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

    // Sets the frame step (basically the fps)
    frame_dur = frame_duration;
}

void SceneManager::measure_fps()
{
    // Measure the frames per second by counting the frames and dividing by the time since last reset
    std::cout << "FPS: " << (frame / (glfwGetTime() - start_time)) << std::endl;
}

void SceneManager::step_frame()
{
    // Calculate the time since the last frame change
    float delta_time = glfwGetTime() - prev_time;

    // If the time since the last frame change is greater than the desired frame duration, change the frame
    if (delta_time >= frame_dur)
    {
        // Set the previous time to the current time and increment the frame
        prev_time = glfwGetTime();
        frame++;
    }
}

// This should be called every frame in main loop
void SceneManager::show(bool show_fps)
{
    // Set the background color
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Configure ImGui style
    ImGui::StyleColorsDark();

    // Start the ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // Draw the current scene
    body();
    if (show_fps)
        measure_fps();

    if (is_paused)
        start_time = glfwGetTime();
    else
        step_frame();

    // Render everything at the end of the frame so imgui is always on top
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData()); // Renders the ImGui draw data
}

void SceneManager::change_scene(const std::function<void()> &new_scene)
{
    body = new_scene;
    reset();
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
        // Change the scene if 2D button is clicked
        change_scene(std::bind(&SceneManager::sc_2d_selector, this));
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
        // Change the scene to the 2D selector if the back button is clicked
        change_scene(std::bind(&SceneManager::sc_2d_selector, this));
    }

    // Slider for speed of triangle movement
    if (ImGui::SliderFloat("Speed Coefficient", &two_d_triangle_test_speed_coef, 0.1f, 10.0f))
    {
        // Reset and pause the frame if the speed is changed
        frame = 0;
    }
    ImGui::Checkbox("Pause", &is_paused);

    // Reset button
    ImGui::SameLine();
    if (ImGui::Button("Reset"))
    {
        frame = 0;
        start_time = glfwGetTime();
    }

    ImGui::End(); // End the ImGui window
    // Render triangles under the ImGui window
    two_d_scenes.sc_2d_triangle_test_render(two_d_triangle_test_speed_coef, frame, frame_dur);
}

void SceneManager::draw_angle_circle(ImDrawList *draw_list, ImVec2 center, float radius, float angle)
{
    // Draw the circle outline
    draw_list->AddCircle(center, radius, IM_COL32(255, 255, 255, 255), 64, 2.0f);

    // Calculate the end point of the arrow based on the angle
    ImVec2 arrowEnd = ImVec2(
        center.x + radius * cos(angle),
        center.y + radius * -sin(angle));

    // Draw the arrow (a line from the center to the calculated endpoint)
    draw_list->AddLine(center, arrowEnd, IM_COL32(255, 255, 255, 255), 2.0f);
}

void SceneManager::sc_2d_projectile_motion()
{
    // Create your ImGui window and UI elements
    ImGui::Begin("Projectile Motion");
    if (ImGui::Button("Back"))
    {
        // Change the scene to the 2D selector if the back button is clicked
        change_scene(std::bind(&SceneManager::sc_2d_selector, this));
    }

    // Slider for speed of triangle movement
    if (ImGui::SliderFloat("Initial Velocity", &two_d_projectile_motion_initial_velocity, 0.1f, 10.0f))
    {
        // Reset and pause the frame if the speed is changed
        frame = 0;
    }

    if (ImGui::SliderFloat("Gravitational Acceleration", &two_d_projectile_motion_gravitational_acceleration, 1.0f, 20.0f))
    {
        // Reset and pause the frame if the speed is changed
        frame = 0;
    }
    ImGui::Checkbox("Pause", &is_paused);

    // Reset button
    ImGui::SameLine();
    if (ImGui::Button("Reset"))
    {
        frame = 0;
        start_time = glfwGetTime();
    }
    ImGui::NewLine();
    ImDrawList *draw_list = ImGui::GetWindowDrawList();
    ImVec2 center = ImGui::GetCursorScreenPos();
    center.x += 50; // Adjust as needed for positioning
    center.y += 70;
    float radius = 40.0f;

    // Angle in radians for the direction of the arrow
    if (ImGui::SliderFloat("Launch Angle", &two_d_projectile_motion_launch_angle, 0.0f, 360.0f))
    {
        // Reset and pause the frame if the speed is changed
        frame = 0;
    }

    // Draw the direction circle with an arrow
    draw_angle_circle(draw_list, center, radius, two_d_projectile_motion_launch_angle * M_PI / 180.0f);

    ImGui::End(); // End the ImGui window
    // Render triangles under the ImGui window
    two_d_scenes.sc_2d_projectile_motion_render(two_d_projectile_motion_launch_angle, two_d_projectile_motion_gravitational_acceleration, two_d_projectile_motion_initial_velocity, frame, frame_dur);
}

void SceneManager::reset()
{
    frame = 0;
    is_paused = false;
    start_time = glfwGetTime();
}

void SceneManager::sc_2d_selector()
{
    // Create title of imgui popup
    ImGui::Begin("2D Selector");
    if (ImGui::Button("Back"))
    {
        // Change the scene if user wants to go back
        change_scene(std::bind(&SceneManager::sc_start_menu, this));
    }

    // General UI elements
    ImGui::Text("Choose a 2D simulation");

    if (ImGui::Button("Triangle Test"))
    {
        // Change the scene if user wants to see the triangle test
        change_scene(std::bind(&SceneManager::sc_2d_triangle_test, this));
    }
    else if (ImGui::Button("Projectile Motion"))
    {
        // Change the scene if user wants to see the projectile motion
        change_scene(std::bind(&SceneManager::sc_2d_projectile_motion, this));
    }

    // End the ImGui window
    ImGui::End();
}