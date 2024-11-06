#ifndef CORE_MATH_H
#define CORE_MATH_H

#include <cmath>

class CoreMath
{
public:
    struct Vector2
    {
    public:
        /**
         * @brief The magnitude of the velocity.
         *
         * Uses SI units.
         */
        float get_magnitude() { return magnitude; };

        /**
         * @brief The angle of the velocity.
         *
         * Uses degrees in standard position.
         */
        float get_angle() { return angle; };

        /**
         * @brief The angle of the velocity.
         *
         * Uses radians in standard position.
         */
        float get_angle_radians() { return angle * M_PI / 180.0f; };

        /**
         * @brief The x-component of the velocity.
         *
         * Uses SI units.
         */
        float get_x_component() { return magnitude * cos(angle * M_PI / 180.0f); };

        /**
         * @brief The y-component of the velocity.
         *
         * Uses SI units.
         */
        float get_y_component() { return magnitude * sin(angle * M_PI / 180.0f); };

        /**
         * @brief Sets the magnitude of the velocity.
         *
         * @param magnitude The magnitude of the velocity.
         */
        void set_magnitude(float magnitude) { this->magnitude = magnitude; };

        /**
         * @brief Sets the angle of the velocity.
         *
         * @param angle The angle of the velocity.
         */
        void set_angle(float angle) { this->angle = angle; };

        /**
         * @brief Adds a vector to the current vector.
         *
         * @param velocity The vector to add.
         */
        void add_vector2(Vector2 velocity);

        /**
         * @brief Multiplies the vector by a scalar.
         *
         * @param scalar The scalar to multiply by.
         */
        void multiply_scalar(float scalar);

    private:
        /**
         * @brief The magnitude of the vector.
         */
        float magnitude = 0.0f;

        /**
         * @brief The angle of the vector.
         *
         * Uses degrees in standard position.
         */
        float angle = 0.0f;
    };
};

#endif