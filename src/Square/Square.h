#ifndef SQUARE_H
#define SQUARE_H

enum class SQ_Color : char { EMPTY = ' ', RED = 'r', BLUE = 'b' };

class Square {

private:
  SQ_Color color;

public:
  // Square() = default; //WHYYY
  //~Square() = default;
  Square(SQ_Color color);
  bool setColor(const SQ_Color &color);
  [[nodiscard]] SQ_Color getColor() const;
};

class StartSquare : public Square {
  using Square::Square;
};
class EndSquare : public Square {
  using Square::Square;
};

#endif // !SQUARE_H
