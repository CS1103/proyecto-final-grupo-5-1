#ifndef TURN_H
#define TURN_H

#include "../Square/Square.h"

class Turn {

private:

  Square& mr_square;
  const unsigned int mc_turn;
  const char mc_turn_color;

public:

  Turn(Square& square, const unsigned int turnNumber, const char turnColor);


};

#endif // !TURN_H
