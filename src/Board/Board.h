#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <vector>
#include "../Square/Square.h"
#include "../Player/Player.h"

// USING

using ptr_square = std::shared_ptr<Square>;
using ptr_player = std::shared_ptr<Player>;

template <typename T>
using matrix = std::vector<std::vector<T>>;


class Board {

private:
  matrix<ptr_square> tablero;

public:
  Board(const unsigned int &size);

  bool verifyConnection(const P_Color &color);

  bool setSquare(unsigned int squareX, unsigned int squareY, SQ_Color turnColor);

};
#endif // !BOARD_H
