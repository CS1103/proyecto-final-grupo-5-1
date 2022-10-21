#include "Turn.h"


Turn::Turn(Board &board, const P_Color &playerColor, const std::chrono::seconds &timeLimit):
  mr_board(board),
  mc_player_color(playerColor)
{
  m_countdown_timer = std::jthread([&timeLimit](){

    std::this_thread::sleep_for(timeLimit);

  });
}


bool Turn::validPlay(const unsigned int &squareX, const unsigned int &squareY){

  auto color = static_cast<SQ_Color>(static_cast<char>(mc_player_color));
  return mr_board.setSquare(squareX, squareY, color);

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
