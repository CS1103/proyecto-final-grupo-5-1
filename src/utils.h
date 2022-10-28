#ifndef UTILS_H
#define UTILS_H

#include "Player/Player.h"
#include "Square/Square.h"

#include <chrono>
#include <memory>
#include <vector>

// USING
using ptr_square = std::shared_ptr<Square>;
using ptr_player = std::shared_ptr<Player>;

template <typename T> using matrix = std::vector<std::vector<T>>;

using seconds = std::chrono::seconds;

#endif // UTILS_H
