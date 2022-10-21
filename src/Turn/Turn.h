#ifndef TURN_H
#define TURN_H

#include "../Board/Board.h"
//#include "../Player/Player.h" // Temporal include
#include <chrono>
#include <thread>
#include <optional>

class Turn {

private:

  Board &mr_board;
  //Board mr_board;
  P_Color mc_player_color;
  bool m_time_limit_over;
  std::jthread m_countdown_timer;

public:

  Turn(Board &board, const P_Color &playerColor, const std::chrono::seconds &timeLimit);

  bool validPlay(const unsigned int &squareX, const unsigned int &squareY);

  [[nodiscard]] std::optional<P_Color> isGameOver() const;

  [[nodiscard]] bool isTimeUp() const;

  void stopTimer();


};

#endif // !TURN_H
