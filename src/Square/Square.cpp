#include "Square.h"

bool Square::setColor(SQ_Color color){
  if (this->color == SQ_Color::EMPTY){
    this->color = color;
    return true;
  }
  return false;
}
