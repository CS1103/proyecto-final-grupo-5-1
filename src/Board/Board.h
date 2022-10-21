#include <vector>
#include "../Square/Square.h"

#ifndef BOARD_H
#define BOARD_H

class Board {
private:
  std::vector<std::vector<Square>> tablero(11);

public:
  Board() {  for (int i=0; i<11; i++)  tablero[i].resize(11); }

  void generateBoard();

  void updateBoard();

  bool verifyConnection();

};

#endif // !BOARD_H