#include "Bot.h"

// random code
std::string GetRandomName() {
  std::string code;
  const unsigned int CODE_LENGTH = 6;
  for (int i = 0; i < 3; i++) {
    code += std::to_string(rand() % CODE_LENGTH);
  }
  return "Bot " + code;
}

Bot::Bot(Difficulty difficulty)
    : Player(GetRandomName()), difficulty(difficulty) {}

unsigned int EvaluateMove(const movement &movement, const Board &board) {}

movement Bot::computeMove(const Board &board) const { return {2, 4}; }
