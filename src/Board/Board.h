#ifndef BOARD_H
#define BOARD_H

#include "../utils.h"

#include "../Player/Player.h"
#include "../Square/Square.h"

#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>
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
  // Mostrar en Consola

  void show() const;
};
#endif // !BOARD_H
