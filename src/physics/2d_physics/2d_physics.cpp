#include "2d_physics.h"

TwoDPhysics::Velocity TwoDPhysics::KinematicEquations::calculate_final_velocity(const Velocity initial_velocity, const Acceleration acceleration, float time)
{
    TwoDPhysics::Velocity final_velocity;
    TwoDPhysics::Acceleration acceleration_copy;

    Acceleration a = acceleration;
    Velocity v_i = initial_velocity;

    acceleration_copy.set_magnitude(a.get_magnitude());
    acceleration_copy.set_angle(a.get_angle());

    acceleration_copy.multiply_scalar(time);

    final_velocity.set_magnitude(v_i.get_magnitude());
    final_velocity.set_angle(v_i.get_angle());

    final_velocity.add_vector2(acceleration_copy);

    return final_velocity;
}

TwoDPhysics::Displacement TwoDPhysics::KinematicEquations::calculate_displacement(const Velocity initial_velocity, const Acceleration acceleration, float time)
{
    TwoDPhysics::Displacement displacement;

    Velocity v_i = initial_velocity;
    Acceleration a = acceleration;

    v_i.multiply_scalar(time);

    a.multiply_scalar(0.5 * pow(time, 2));

    displacement.add_vector2(v_i);

    displacement.add_vector2(a);

    return displacement;
}
