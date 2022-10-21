#include "Square.h"

bool Square::setColor(SQ_Color color){
  if (this->color == SQ_Color::EMPTY){
    this->color = color;
    return true;
  }
  return false;
}

SQ_Color Square::getColor(){
  return this->color;
}

Square::Square(SQ_Color color):
  color(color) {}
