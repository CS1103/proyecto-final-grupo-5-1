#include "Movement.h"

template <typename T>
Movement<T>::Movement(T &object, const Vector2f &speed,
                      const Vector2f &acceleration, const Vector2f &distance)
    : object(object), speed(speed / SPEED_RATIO),
      acceleration(acceleration / ACCEL_RATIO), max_distance(distance) {}
