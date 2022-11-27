#include "utils.h"

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
