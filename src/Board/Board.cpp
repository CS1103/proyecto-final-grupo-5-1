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

bool Board::verifyConnection(){
  return true;
}

bool Board::setSquare(unsigned int squareX, unsigned int squareY, SQ_Color turnColor){
  return tablero[squareX][squareY].setColor(turnColor);
}

void Board::updateBoard(){
}
