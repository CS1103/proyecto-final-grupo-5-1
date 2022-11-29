#ifndef BOT_H
#define BOT_H

enum class Difficulty : unsigned int {
  NOOB = 1,
  EASY = 5,
  MEDIUM = 10,
  HARD = 20,
  MOHEX = 50
};

#include "../Board/Board.h"
#include "../Player/Player.h"
#include "../utils.h"

using UTILS::movement;

class Bot : public Player {

private:
  Difficulty difficulty;

public:
  Bot(Difficulty difficulty = Difficulty::NOOB);

  [[nodiscard]] movement computeMove(const Board &board) const;
  // Juego del bot
  [[nodiscard]] bool automatizarBot(const P_Color &playerColor,
                                    const Board &board) const;
  // Funcion format (traida de board)
  [[nodiscard]] UTILS::matrix<UTILS::ptr_square> formatBot(const P_Color &color,
                                                           Board board) const;

  double getWins(Board &board, SQ_Color color);

  std::pair<int, int> next(const Board &board, SQ_Color color);
};

#endif // !BOT_H
