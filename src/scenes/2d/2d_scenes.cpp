#include "2d_scenes.h"

void TwoDScenes::sc_2d_triangle_test_render(float speed_coef, int frame, float frame_duration)
{
    // Calculates the animation index (a value between -1 and 1 corresponding to the frame of the program)
    float animation_index = sin(frame * speed_coef * frame_duration);
    // Creates the vertices for the triangles
    std::vector<std::vector<float>>
        vertices = {{// positions         // colors
                     0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
                     -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
                     0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f},
                    {// positions         // colors
                     0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
                     -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
                     0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f},

                    {// positions         // colors
                     0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
                     -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
                     0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f}};

    // Calculates the spin of the triangles and sets it to a radian value of the animation index
    float spin = animation_index * 3.14159f;

    // Creates the transformation matrices for the triangles and sets them to a placebo value
    glm::mat4 trans1 = glm::mat4(1.0f);
    glm::mat4 trans2 = glm::mat4(1.0f); // Will remain as a placebo value to show what happens when no transformation is applied
    glm::mat4 trans3 = glm::mat4(1.0f);

    // Applies the transformations to the transformation matrices
    trans1 = glm::translate(trans1, glm::vec3(-0.5f, -0.5f, 0.0f));
    trans1 = glm::rotate(trans1, spin, glm::vec3(0.0f, 0.0f, 1.0f));
    trans1 = glm::scale(trans1, glm::vec3(0.5f, 0.5f, 0.5f));

    trans3 = glm::translate(trans3, glm::vec3(animation_index, 0.0f, 0.0f));
    trans3 = glm::scale(trans3, glm::vec3(0.25f, 0.25f, 0.25f));

    // Renders the triangles
    inline_color_renderer.set_vertices(vertices, {trans1, trans2, trans3});
    inline_color_renderer.render(false);
}

void TwoDScenes::sc_2d_projectile_motion_render(float initial_angle, float gravity, float initial_velocity, int frame, float frame_duration)
{
    Object2D projectile({
        {
            // position
            -0.75f,
            0.0f,
            0.0f,
            //  Colors
            255.0f / 255.0f,
            255.0f / 255.0f,
            255.0f / 255.0f,
            // position
            -0.5f,
            0.0f,
            0.0f,
            //  Colors
            255.0f / 255.0f,
            255.0f / 255.0f,
            255.0f / 255.0f,
            // position
            -0.75f,
            0.25f,
            0.0f,
            //  Colors
            255.0f / 255.0f,
            255.0f / 255.0f,
            255.0f / 255.0f,
        },
        {
            // position
            -0.75f,
            0.25f,
            0.0f,
            //  Colors
            255.0f / 255.0f,
            255.0f / 255.0f,
            255.0f / 255.0f,

            // position
            -0.5f,
            0.25f,
            0.0f,
            //  Colors
            255.0f / 255.0f,
            255.0f / 255.0f,
            255.0f / 255.0f,

            // position
            -0.5f,
            0.0f,
            0.0f,
            //  Colors
            255.0f / 255.0f,
            255.0f / 255.0f,
            255.0f / 255.0f,
        },
    });
    Object2D wall({
        {// position
         -0.5f,
         -1.0f,
         0.0f,
         //  Colors
         153.0f / 255.0f,
         76.0f / 255.0f,
         0.0f / 255.0f,
         //  position
         -1.0f,
         -1.0f,
         0.0f,
         //  Colors
         153.0f / 255.0f,
         76.0f / 255.0f,
         0.0f / 255.0f,
         //  position
         -1.0f,
         0.0f,
         0.0f,
         //  Colors
         153.0f / 255.0f,
         76.0f / 255.0f,
         0.0f / 255.0f},
        {
            // position
            -1.0f,
            0.0f,
            0.0f,
            //  Colors
            153.0f / 255.0f,
            76.0f / 255.0f,
            0.0f / 255.0f,
            // position
            -0.5f,
            0.0f,
            0.0f,
            //  Colors
            153.0f / 255.0f,
            76.0f / 255.0f,
            0.0f / 255.0f,
            -0.5f,
            -1.0f,
            0.0f,
            //  Colors
            153.0f / 255.0f,
            76.0f / 255.0f,
            0.0f / 255.0f,
        },
    });
    TwoDPhysics::Acceleration a;
    a.set_magnitude(gravity);
    a.set_angle(270.0f);
    float t = frame * frame_duration;

    TwoDPhysics::Velocity v_i;
    v_i.set_magnitude(initial_velocity);
    v_i.set_angle(initial_angle);

    TwoDPhysics::Displacement displacement = TwoDPhysics::KinematicEquations::calculate_displacement(v_i, a, t);

    projectile.translate(displacement);

    std::vector<Object2D> objects = {wall, projectile};
    render(objects);
}

void TwoDScenes::render(std::vector<Object2D> objects, bool is_wireframe)
{
    std::vector<std::vector<float>> vertices;
    std::vector<glm::mat4> translations;

    for (Object2D object : objects)
    {
        std::vector<std::vector<float>> object_vertices = object.get_vertices();
        vertices.insert(vertices.end(), object_vertices.begin(), object_vertices.end());

        for (glm::mat4 translation_matrix : object.get_translation_matrix())
        {
            translations.push_back(translation_matrix);
        }
    }

    // Renders the triangles
    inline_color_renderer.set_vertices(vertices, translations);
    inline_color_renderer.render(is_wireframe);
}