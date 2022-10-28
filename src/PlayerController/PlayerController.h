#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <initializer_list>
#include <memory>
#include <vector>

#include "../utils.h"

class PlayerController {
public:
  PlayerController(const std::initializer_list<std::string> &names);
  void addPlayer(const ptr_player &player);
  void removePlayer(const ptr_player &player);
  ptr_player operator[](const unsigned int &index) const;
  ptr_player operator[](const std::string &name) const;

private:
  std::vector<ptr_player> mp_players;
};

#endif // !PLAYER_CONTROLLER_H
