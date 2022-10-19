#include "Player.h"

void Player::ChangeName(std::string new_name){
  this->m_name = new_name;
}

void Player::ChangeColor(char new_color){
  this->m_color = new_color;
}

bool Player::IsWinner(){
  return this->m_is_winner;
}

/*
std::string Player::GetName(){
  return this->m_name;
}

char Player::GetColor(){
  return this->m_color;
}
*/
