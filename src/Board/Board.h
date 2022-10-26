#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <vector>
#include "../Square/Square.h"
#include "../Player/Player.h"
using namespace std;
class Board {

private:
  vector<vector<shared_ptr<Square>>> tablero;

public:
  Board(const unsigned int &size);

  bool verifyConnection(const P_Color &color);

  bool setSquare(unsigned int squareX, unsigned int squareY, SQ_Color turnColor);

};

#endif // !BOARD_H
