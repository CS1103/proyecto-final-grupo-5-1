#include "Square.h"

Square::Square(SQ_Color color):
  color(color) {}

bool Square::setColor(SQ_Color color){
  /*
  if (this->color == SQ_Color::EMPTY && color != SQ_Color::EMPTY){
    this->color = color;
    return true;
  }
  return false;
  */
  this->color = color;
  return true;

}

SQ_Color Square::getColor(){
  return this->color;
}

