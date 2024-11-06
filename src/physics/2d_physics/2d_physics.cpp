#include "2d_physics.h"

TwoDPhysics::Velocity TwoDPhysics::KinematicEquations::calculate_final_velocity(Velocity initial_velocity, Acceleration acceleration, float time)
{
    TwoDPhysics::Velocity final_velocity;
    TwoDPhysics::Acceleration acceleration_copy;

    acceleration_copy.set_magnitude(acceleration.get_magnitude());
    acceleration_copy.set_angle(acceleration.get_angle());

    acceleration_copy.multiply_scalar(time);

    final_velocity.set_magnitude(initial_velocity.get_magnitude());
    final_velocity.set_angle(initial_velocity.get_angle());

    final_velocity.add_vector2(acceleration_copy);

    return final_velocity;
}
