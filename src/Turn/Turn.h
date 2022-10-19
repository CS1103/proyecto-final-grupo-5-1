#ifndef TURN_H
#define TURN_H

#include "../Board/Board.h"

class Turn {

private:

  Board &mr_board;
  const char mc_turn_color;

public:

  Turn(Board &board, const char &turnColor);

  bool validPlay(const unsigned int &square_x, const unsigned int &square_y);

  bool isGameOver();

};

#endif // !TURN_H
