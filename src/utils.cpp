#include "utils.h"
#include <random>

using namespace UTILS;

bool operator==(SQ_Color square, P_Color player) {
  if (square == SQ_Color::EMPTY && player == P_Color::NONE) {
    return true;
  }
  if (square == SQ_Color::RED && player == P_Color::RED) {
    return true;
  }
  return square == SQ_Color::BLUE && player == P_Color::BLUE;
}
bool operator==(P_Color player, SQ_Color square) {
  if (square == SQ_Color::EMPTY && player == P_Color::NONE) {
    return true;
  }
  if (square == SQ_Color::RED && player == P_Color::RED) {
    return true;
  }
  return square == SQ_Color::BLUE && player == P_Color::BLUE;
}
std::ostream &operator<<(std::ostream &oss, const UTILS::SQ_Color &color) {
  oss << (color == SQ_Color::RED ? 'R' : color == SQ_Color::BLUE ? 'B' : ' ');
  return oss;
}

template <typename T> T GenerarRandomNum(std::pair<T, T> rango) {

  std::random_device r_d;
  std::default_random_engine generator(r_d());

  T ranum;
  if constexpr (std::is_integral<T>::value) {
    std::uniform_int_distribution<T> rand_num(rango.first, rango.second);
    ranum = rand_num(generator);
  } else if constexpr (std::is_floating_point<T>::value) {
    std::uniform_real_distribution<T> rand_num(rango.first, rango.second);
    ranum = rand_num(generator);
  }

  return ranum;
}
