#include "Turn.h"

Turn::Turn(Board &board, const char &turnColor):
  mr_board(board),
  mc_turn_color(turnColor) {}

bool Turn::validPlay(const unsigned int &squareX, const unsigned int &squareY){

  if( mr_board.setSquare(square_x, square_y, mc_turn_color) ){
    return true;
  }
  return false;

}

bool Turn::isGameOver(){
  if (mr_board.verifyConnection()){
    return true;
  }
  return false;

}

void Turn::startTimer(){


}

bool
