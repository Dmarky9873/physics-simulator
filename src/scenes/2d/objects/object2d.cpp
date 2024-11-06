#include "object2d.h"

void Object2D::translate(TwoDPhysics::Displacement displacement)
{
    translation = glm::translate(translation, glm::vec3(displacement.get_x_component(), displacement.get_y_component(), 0.0f));
}

void Object2D::rotate(float angle)
{
    translation = glm::rotate(translation, angle, glm::vec3(0.0f, 0.0f, 1.0f));
}

std::vector<glm::mat4> Object2D::get_translation_matrix()
{
    std::vector<glm::mat4> translation_matrix;
    for (int i = 0; i < vertices.size(); i++)
    {
        translation_matrix.push_back(translation);
    }
    return translation_matrix;
}