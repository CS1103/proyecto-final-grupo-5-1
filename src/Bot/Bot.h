#ifndef BOT_H
#define BOT_H

enum class Difficulty : unsigned int {
  NOOB = 0,
  EASY = 1,
  MEDIUM = 2,
  HARD = 3,
  MOHEX = 4
};

#include "../Board/Board.h"
#include "../Player/Player.h"
#include "../utils.h"

using UTILS::movement;

class Bot : public Player {
public:
  Bot(Difficulty difficulty = Difficulty::EASY);
  [[nodiscard]] movement computeMove(const Board &board) const;

private:
  Difficulty difficulty;
};

#endif // !BOT_H
