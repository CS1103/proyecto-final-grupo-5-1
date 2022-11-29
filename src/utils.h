#ifndef UTILS_H
#define UTILS_H

//#include "SFML/System/Vector2.hpp" // overloading vector2f
#include <chrono>
#include <memory>
#include <optional>
#include <random>
#include <vector>

class Square;
class Player;

namespace UTILS {

enum class TipoJ : unsigned int {
  HUMANO_HUMANO = 0,
  HUMANO_COMPUTADOR = 1,
  COMPUTADOR_COMPUTADOR = 2
};

enum class SQ_Color : char { EMPTY = ' ', RED = 'r', BLUE = 'b' };

enum class P_Color : char { BLUE = 'b', RED = 'r', NONE = '0' };

using movement = std::pair<unsigned int, unsigned int>;

using ptr_square = std::shared_ptr<Square>;
using ptr_player = std::shared_ptr<Player>;

template <typename T> using matrix = std::vector<std::vector<T>>;
using seconds = std::chrono::seconds;

using game_sett = std::tuple<std::string, std::string, TipoJ, unsigned int,
                             std::optional<seconds>>;

/*
class Vector2f : public sf::Vector2f {
public:
  Vector2f(float xPos, float yPos) : sf::Vector2f(xPos, yPos) {}
  Vector2f(const sf::Vector2f &vec) : sf::Vector2f(vec) {}

  auto &operator[](unsigned int index) {
    if (index == 0) {
      return x;
    }
    if (index == 1) {
      return y;
    }
    throw std::out_of_range("Vector2f::operator[]");
  }
};
*/

} // namespace UTILS

bool operator==(UTILS::SQ_Color square, UTILS::P_Color player);
bool operator==(UTILS::P_Color player, UTILS::SQ_Color square);
std::ostream &operator<<(std::ostream &oss, const UTILS::SQ_Color &color);

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

#endif // !#UTILS_H
