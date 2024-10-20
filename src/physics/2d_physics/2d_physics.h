#ifndef TWO_D_PHYSICS_H
#define TWO_D_PHYSICS_H

#include "../core_math/core_math.h"

class TwoDPhysics
{
public:
    struct Displacement : protected CoreMath::Vector2
    {
    public:
        /**
         * @brief The distance of the displacement in meters.
         */
        float get_distance_meters() { return get_magnitude(); };

        /**
         * @brief The distance of the displacement in kilometers.
         */
        float get_distance_kilometers() { return get_magnitude() / 1000.0f; };

        /**
         * @brief The distance of the displacement in miles.
         */
        float get_distance_miles() { return get_magnitude() / 1609.34f; };
    };

    struct Velocity : protected CoreMath::Vector2
    {
    public:
        /**
         * @brief The speed of the velocity in m/s.
         */
        float get_speed_meters_per_second() { return get_magnitude(); };

        /**
         * @brief The speed of the velocity in km/h.
         */
        float get_speed_kilometers_per_hour() { return get_magnitude() * 3.6f; };

        /**
         * @brief The speed of the velocity in mph.
         */
        float get_speed_miles_per_hour() { return get_magnitude() * 2.23694f; };
    };

    struct Acceleration : protected CoreMath::Vector2
    {
    public:
        /**
         * @brief The acceleration of the velocity in m/s^2.
         */
        float get_abs_acceleration_meters_per_second_squared() { return get_magnitude(); };

        /**
         * @brief The acceleration of the velocity in km/h^2.
         */
        float get_abs_acceleration_kilometers_per_hour_squared() { return get_magnitude() * 12960.0f; };

        /**
         * @brief The acceleration of the velocity in mph^2.
         */
        float get_abs_acceleration_miles_per_hour_squared() { return get_magnitude() * 8036.8f; };
    };
};

#endif