#include <initializer_list>
#include "PlayerController.h"

// Constructor with initializer list to construct Players
PlayerController::PlayerController(
    const std::initializer_list<std::string> &names) {
  for (const auto &name : names) {
    this->mp_players.emplace_back(std::make_shared<Player>(Player(name)));
  }
}

void PlayerController::addPlayer(const ptr_player &player) {
  mp_players.push_back(player);
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
