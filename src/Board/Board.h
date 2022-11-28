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

public:
  Board(UTILS::matrix<UTILS::ptr_square> &matrix);

  [[nodiscard]] UTILS::matrix<UTILS::ptr_square>
  format(const UTILS::P_Color &color) const;

  Board(const unsigned int &size);

  [[nodiscard]] bool verifyConnection(const UTILS::P_Color &color) const;

  void setSquare(const unsigned int &squareX, const unsigned int &squareY,
                 const UTILS::SQ_Color &turnColor) const;

  [[nodiscard]] bool
  setSquareValidation(const unsigned int &squareX, const unsigned int &squareY,
                      const UTILS::SQ_Color &turnColor) const;

  void show() const;

  [[nodiscard]] std::vector<std::pair<unsigned int, unsigned int>>
  getAvailableMoves() const;

  SQ_Color winner();

  void bfsSearch(std::vector<std::pair<int, int>> &start,
                 std::vector<bool> &condition);

  // move evaluation
  //
  // ejecuta el movimiento
  // evalua la posición
  // deshace el movimiento
  // retorna la evaluación
  double evaluateMove(std::pair<unsigned int, unsigned int>, SQ_Color color,
                      unsigned int depth);
};
#endif // !BOARD_H
