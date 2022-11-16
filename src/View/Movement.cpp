#include "Movement.h"

Movement::Movement(std::string sprite, sf::Vector2f speed,
                   sf::Vector2f acceleration, sf::Vector2f distance)
    : sprite(std::move(sprite)), speed(speed / SPEED_RATIO),
      acceleration(acceleration / ACCEL_RATIO), max_distance(distance) {}
