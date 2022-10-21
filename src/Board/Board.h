#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "../Square/Square.h"
#include "../Player/Player.h"

class Board {

private:
  std::vector<std::vector<Square>> tablero;

public:
  Board(const unsigned int &size);

  void updateBoard();

  bool verifyConnection(const P_Color &color);

  bool setSquare(unsigned int squareX, unsigned int squareY, SQ_Color turnColor);

};

#endif // !BOARD_H
