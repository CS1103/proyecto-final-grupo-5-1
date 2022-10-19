#include "Player.h"

bool validateName(std::string name){

  // Validate name size
  if (name.length() > 20 || name.length() < 1){
    return false;
  }

  // Validate name characters as alphanumeric
  for(auto ch: name){
    if(!isalnum(ch)) {
      return false;
    }
  }

  return true;

}

Player::Player(const std::string &name, char &color){

  if(validateName(name))
    this->m_name = name;
  else
    throw std::invalid_argument("Invalid name");

  color = tolower(color);

  if (color == 'r' || color == 'b')
    this->m_color = color;
  else
    throw std::invalid_argument("Invalid color");

}


bool Player::ChangeName(const std::string &new_name){
  if(validateName(new_name)){
    this->m_name = new_name;
    return true;
  }
  return false;
}

bool Player::ChangeColor(char &new_color){

  new_color = tolower(new_color);
  if (new_color == 'r' || new_color == 'b'){
    this->m_color = new_color;
    return true;
  }
  return false;
}

bool Player::IsWinner(){
  return this->m_is_winner;
}

std::string Player::GetName() const{
  return this->m_name;
}

char Player::GetColor() const{
  return this->m_color;
}
