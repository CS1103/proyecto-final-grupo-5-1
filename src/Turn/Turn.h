#ifndef TURN_H
#define TURN_H

#include "../Board/Board.h"
#include <chrono>
#include <thread>

class Turn {

private:

  Board &mr_board;
  char mc_turn_color;
  bool m_time_limit_over;

public:

  Turn(Board &board, const char &turnColor);

  bool validPlay(const unsigned int &squareX, const unsigned int &squareY);

  bool isGameOver();

  void startTimer(const std::chrono::seconds &timeLimit);

  bool isTimeLimitOver();

  void stopTimer();


};

#endif // !TURN_H
