#ifndef TWO_D_OBJECTS_H
#define TWO_D_OBJECTS_H

#include <vector>
#include <map>

#include "../../../physics/2d_physics/2d_physics.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Object2D
{
public:
    Object2D(std::vector<std::vector<float>> vertices) : vertices(vertices) {}

    const std::vector<std::vector<float>> get_vertices() { return vertices; }

    void translate(TwoDPhysics::Displacement displacement);

    void rotate(float angle);

    std::vector<glm::mat4> get_translation_matrix();

private:
    glm::mat4 translation = glm::mat4(1.0f);
    std::vector<std::vector<float>> vertices;
};

#endif