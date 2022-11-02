#include "Turn.h"

Turn::Turn(const Board &board, const P_Color &playerColor,
           const std::chrono::seconds &timeLimit)
    : mr_board(board), mc_player_color(playerColor),

      // Limit the time for the player to make a move
      m_countdown_timer(std::jthread(
          [&timeLimit]() { std::this_thread::sleep_for(timeLimit); })) {}

bool Turn::validPlay(const unsigned int &squareX,
                     const unsigned int &squareY) const {

  // One of this must work
  // auto color = static_cast<SQ_Color>(static_cast<char>(mc_player_color));
  auto color = static_cast<SQ_Color>(mc_player_color);
  return mr_board.setSquare(squareX, squareY, color);
}

std::optional<P_Color> Turn::isGameOver() const {

  if (mr_board.verifyConnection(P_Color::RED)) {
    return P_Color::RED;
  }
  if (mr_board.verifyConnection(P_Color::BLUE)) {
    return P_Color::BLUE;
  }
  return std::nullopt;
}

bool Turn::isTimeUp() const { return this->m_time_limit_over; }

void Turn::stopTimer() { m_countdown_timer.request_stop(); }
