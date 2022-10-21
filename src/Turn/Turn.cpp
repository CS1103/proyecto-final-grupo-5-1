#include "Turn.h"


Turn::Turn(Board &board, const char &turnColor, const std::chrono::seconds &timeLimit):
  mr_board(board),
  mc_turn_color(turnColor)
{
  m_countdown_timer = std::jthread([&timeLimit](){

    std::this_thread::sleep_for(timeLimit);

  });
}


bool Turn::validPlay(const unsigned int &squareX, const unsigned int &squareY){

  return mr_board.setSquare(squareX, squareY, mc_turn_color);

}

bool Turn::isGameOver() const{

  return mr_board.verifyConnection();

}

bool Turn::isTimeUp() const{
  return this -> m_time_limit_over;
}


void Turn::stopTimer(){
  m_countdown_timer.request_stop();
}
