#include "core_math.h"

void CoreMath::Vector2::add_vector2(Vector2 velocity)
{
    float x_component = get_x_component() + velocity.get_x_component();
    float y_component = get_y_component() + velocity.get_y_component();
    float magnitude = sqrt(pow(x_component, 2) + pow(y_component, 2));
    float angle = atan2(y_component, x_component) * 180.0f / M_PI;

    set_magnitude(magnitude);
    set_angle(angle);
}