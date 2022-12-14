#include "Square.h"
#include <iostream>

Square::Square() { this->color = SQ_Color::EMPTY; }

Square::Square(SQ_Color color) : color(color) {}

void Square::setColor(const SQ_Color &color) { this->color = color; }

bool Square::setColorValidation(const SQ_Color &color) {

  if (this->color == SQ_Color::EMPTY && color != SQ_Color::EMPTY) {
    this->color = color;
    return true;
  }
  return false;
}

SQ_Color Square::getColor() const { return this->color; }
