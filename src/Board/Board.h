#ifndef BOARD_H
#define BOARD_H

#include "../Player/Player.h"
#include "../Square/Square.h"

#include "../utils.h"

#include <memory>
#include <vector>

class Board {

private:
  matrix<ptr_square> tablero;

public:
  Board(const unsigned int &size);

  bool verifyConnection(const P_Color &color);

  bool setSquare(unsigned int squareX, unsigned int squareY,
                 SQ_Color turnColor);
};
#endif // !BOARD_H
