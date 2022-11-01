#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "../utils.h"
#include <initializer_list>
#include <memory>
#include <vector>

class PlayerController {
public:
  PlayerController(const std::initializer_list<std::string> &names);
  PlayerController() = default;
  bool addPlayer(const ptr_player &player);
  bool addPlayer(const std::string &name);
  void removePlayer(const ptr_player &player);
  ptr_player operator[](const unsigned int &index) const;
  ptr_player operator[](const std::string &name) const;
  bool operator<(size_t size) const;
  bool operator>(size_t size) const;

private:
  std::vector<ptr_player> mp_players;
};

#endif // !PLAYER_CONTROLLER_H
