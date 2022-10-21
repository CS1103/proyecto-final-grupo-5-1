#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "../Square/Square.h"

class Board {

private:
  std::vector<std::vector<Square>> tablero;

public:
  Board(const unsigned int &size);

  void updateBoard();

  bool verifyConnection();

};

#endif // !BOARD_H
