#ifndef SQUARE_H
#define SQUARE_H

#include "../utils.h"

using UTILS::SQ_Color;

class Square {

private:
  SQ_Color color;

public:
  Square();
  //~Square() = default;
  Square(SQ_Color color);
  bool setColorValidation(const SQ_Color &color);
  void setColor(const SQ_Color &color);
  [[nodiscard]] SQ_Color getColor() const;
};

class StartSquare : public Square {
  using Square::Square;
};
class EndSquare : public Square {
  using Square::Square;
};

#endif // !SQUARE_H
