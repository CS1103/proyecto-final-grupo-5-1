#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../utils.h"
#include <SFML/Graphics.hpp>

[[maybe_unused]] const float SPEED_RATIO = 100000;
[[maybe_unused]] const float ACCEL_RATIO = 10000000;

// Store sprite, speed, acceleration and distance
struct Movement {

  std::string sprite;
  Vector2f speed;
  Vector2f acceleration;
  Vector2f max_distance;

  Movement(std::string sprite, sf::Vector2f speed, sf::Vector2f acceleration,
           sf::Vector2f distance);
};

#endif // !MOVEMENT_H
