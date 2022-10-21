#ifndef TURN_H
#define TURN_H

//#include "../Board/Board.h"
#include <chrono>
#include <thread>

class Turn {

private:

  Board &mr_board;
  //Board mr_board;
  char mc_turn_color;
  std::chrono::seconds mc_time_limit; 
  bool m_time_limit_over;
  std::jthread m_countdown_timer;

public:

  Turn(Board &board, const char &turnColor, const std::chrono::seconds &timeLimit);

  bool validPlay(const unsigned int &squareX, const unsigned int &squareY);

  [[nodiscard]] bool isGameOver() const;

  [[nodiscard]] bool isTimeUp() const;

  void stopTimer();


};

#endif // !TURN_H
