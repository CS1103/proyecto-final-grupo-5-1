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
#include "vector"

using UTILS::movement;

class Bot : public Player {
private:
    Difficulty difficulty;
public:
    Bot(Difficulty difficulty = Difficulty::EASY, P_Color color = P_Color::BLUE);
    [[nodiscard]] movement computeMove(const Board &board) const;
    // Juego del bot
    bool automatizarBot(const P_Color &playerColor,  const Board &board) const;
    // Funcion format (traida de board)
    [[nodiscard]] UTILS::matrix<UTILS::ptr_square> formatBot(const P_Color &color, Board board) const;

    double getWins(const Board &board,SQ_Color color) const;

    std::pair<int, int> next(const Board &board, SQ_Color color);
};

#endif // !BOT_H
