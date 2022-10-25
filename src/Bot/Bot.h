#ifndef BOT_H
#define BOT_H

enum class Difficulty: unsigned int { NOOB = 0, EASY = 1, MEDIUM = 2, HARD = 3, MOHEX = 4};

#include "../Player/Player.h"
#include "../Board/Board.h"

class Bot: public Player
{
public:
  Bot(Difficulty difficulty = Difficulty::EASY);
  [[nodiscard]] std::pair<unsigned int, unsigned int> computeMove(const Board &board) const;

private:

  Difficulty difficulty;
  
};



#endif // !BOT_H
