#ifndef BOARD_H
#define BOARD_H

#include "../Player/Player.h"
#include "../Square/Square.h"
#include "../utils.h"

#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

class Board {

private:
  UTILS::matrix<UTILS::ptr_square> tablero;
  [[nodiscard]] UTILS::matrix<unsigned int>
  createCircuit(UTILS::P_Color color) const;
  [[nodiscard]] UTILS::matrix<UTILS::ptr_square> format(const UTILS::P_Color &color) const;

public:
  Board(const unsigned int &size);

  [[nodiscard]] bool verifyConnection(const UTILS::P_Color &color) const;
  [[nodiscard]] bool erifyConnection(const UTILS::P_Color &color) const;

  void setSquare(const unsigned int &squareX, const unsigned int &squareY,
                 const UTILS::SQ_Color &turnColor) const;

  [[nodiscard]] bool
  setSquareValidation(const unsigned int &squareX, const unsigned int &squareY,
                      const UTILS::SQ_Color &turnColor) const;

  [[nodiscard]] float evaluateBoard() const;
  UTILS::matrix<UTILS::ptr_square> get_tablero();
  void show() const;


    bool inBoard(int x, int y);

    bool place(int x, int y, SQ_Color color);

    bool badMove(int x, int y);

    std::vector<std::pair<int, int>> getEmpty();
};
#endif // !BOARD_H
