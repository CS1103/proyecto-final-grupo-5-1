#include "Player.h"
#include <string>
using namespace std;
bool ValidateName(const std::string &name){

  string error;

  // Validate name size
  bool is_valid_size = name.length() <= MAX_NAME_LENGTH && name.length() >= 1;

  error += is_valid_size ? "": "Name must be between 1 and " + to_string(MAX_NAME_LENGTH) + " characters\n";

  // isalnum -> chequea si el numero es un alphanumerico (letra o digito)
  // isspace -> chequea si es un espacio en blanco
  bool has_valid_chars = ranges::all_of(name,[](const auto &als){return isalnum(als) || isspace(als); });

  error += has_valid_chars ? "": "Name must only contain alphanumeric characters and spaces\n";

  if(error.empty()){
    return true;
  }

  throw invalid_argument(error);

}

Player::Player(const string &name, const P_Color &color){

  if(ValidateName(name)){
    this->m_name = name; }
  else{
    throw invalid_argument("Invalid name"); }
  // genera una excepción cuando se detecta un problema, lo que nos permite crear un error personalizado.

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

string Player::getName() const{
  return this->m_name;
}


P_Color Player::getColor() const{
  return this->m_color;
}
