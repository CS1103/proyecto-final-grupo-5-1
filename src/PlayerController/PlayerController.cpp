#include "PlayerController.h"
#include <initializer_list>

// Constructor with initializer list to construct Players
PlayerController::PlayerController(
    const std::initializer_list<std::string> &names) {
  for (const auto &name : names) {
    this->mp_players.emplace_back(std::make_shared<Player>(Player(name)));
  }
}

bool PlayerController::addPlayer(const ptr_player &player) {
  // If player is already in the list, return false
  if (std::find(this->mp_players.begin(), this->mp_players.end(), player) !=
      this->mp_players.end()) {
    return false;
  }
  mp_players.push_back(player);
  return true;
}

bool PlayerController::addPlayer(const std::string &name) {
  // If name is already in the list, return false
  if (std::find_if(this->mp_players.begin(), this->mp_players.end(),
                   [&name](const ptr_player &player) {
                     return player->getName() == name;
                   }) != this->mp_players.end()) {
    return false;
  }
  mp_players.push_back(std::make_shared<Player>(Player(name)));
  return true;
}

void PlayerController::removePlayer(const ptr_player &player) {
  mp_players.erase(std::remove(mp_players.begin(), mp_players.end(), player),
                   mp_players.end());
}

ptr_player PlayerController::operator[](const unsigned int &index) const {
  return mp_players[index];
}

// Find player by name
ptr_player PlayerController::operator[](const std::string &name) const {
  auto player_it = std::find(mp_players.begin(), mp_players.end(), name);
  if (player_it != mp_players.end()) {
    return *player_it;
  }
  throw std::invalid_argument("Player not found");
}

bool PlayerController::operator<(size_t size) const {
  return mp_players.size() < size;
}
bool PlayerController::operator>(size_t size) const {
  return mp_players.size() > size;
}
