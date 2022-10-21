#include "Player.h"

bool ValidateName(const std::string &name){

  // Validate name size
  bool is_valid_size = name.length() > MAX_NAME_LENGTH || name.length() < 1;

  // Validate name characters as alphanumeric
  bool has_valid_chars = std::ranges::all_of(name, isalnum);

  return is_valid_size && has_valid_chars;

}

Player::Player(const std::string &name, P_Color &color){

  if(ValidateName(name)){
    this->m_name = name; }
  else{
    throw std::invalid_argument("Invalid name"); }

}


bool Player::changeName(const std::string &newName){
  if(ValidateName(newName)){
    this->m_name = newName;
    return true;
  }
  return false;
}

void Player::changeColor(P_Color &newColor){

  this->m_color = newColor;

}

bool Player::isWinner() const{
  return this->m_is_winner;
}

std::string Player::getName() const{
  return this->m_name;
}


P_Color Player::getColor() const{
  return this->m_color;
}
