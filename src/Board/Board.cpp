#include "Board.h"

Board::Board(const unsigned int &size){
  tablero.resize(size);
  for (auto &vec: tablero) {

    vec.resize(size);

    for (auto &casilla: vec) {
      casilla = Square(); // Use Default Constructor
    }

  }
}
