#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../utils.h" // Vector2f

[[maybe_unused]] const float SPEED_RATIO = 100000;
[[maybe_unused]] const float ACCEL_RATIO = 10000000;

// Store sprite, speed, acceleration and distance
template <typename T> struct Movement {

  T object;
  Vector2f speed;
  Vector2f acceleration;
  Vector2f max_distance;

  Movement(T &object, const Vector2f &speed, const Vector2f &acceleration,
           const Vector2f &distance);
};

#endif // !MOVEMENT_H
