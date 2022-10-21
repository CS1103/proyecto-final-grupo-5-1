#ifndef SQUARE_H
#define SQUARE_H

enum class SQ_Color: char { EMPTY, RED = 'r', BLUE = 'b' };

class Square {

private:
  SQ_Color color;

public:

  bool setColor(SQ_Color color);

};

#endif // !SQUARE_H
