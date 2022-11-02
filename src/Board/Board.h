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

  [[nodiscard]] bool verifyConnection(const P_Color &color) const;

  [[nodiscard]] bool setSquare(const unsigned int &squareX,
                               const unsigned int &squareY,
                               const SQ_Color &turnColor) const;
};
#endif // !BOARD_H
