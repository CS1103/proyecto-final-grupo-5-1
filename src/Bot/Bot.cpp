#include "Bot.h"
// FUNCIONES EXTERNAS -------------
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

std::pair<int, int> Bot::next(Board board, SQ_Color color) {

  auto copy = board.format(static_cast<P_Color>(color));
  board = Board(copy);

  auto blank = board.getAvailableMoves();

  double best_valuation = 0;
  std::pair<unsigned int, unsigned int> best_move = blank[0];

  for (auto &move : blank) {

    double move_valuation =
        board.evaluateMove(move, color, static_cast<unsigned int>(difficulty));
    if (move_valuation > best_valuation) {
      best_valuation = move_valuation;
      best_move = move;
    }
  }
  return best_move;
}
