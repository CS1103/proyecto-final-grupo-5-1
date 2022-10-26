#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <vector>
#include <memory>

#include "../Player/Player.h"

using namespace std;

class PlayerController
{
public:
  PlayerController();
  void addPlayer(shared_ptr<Player> player);
  void removePlayer(shared_ptr<Player> player);
  void getPlayerAt(unsigned int index);

private:
  std::vector<std::shared_ptr<Player>> mp_players;

  
};

#endif // !PLAYER_CONTROLLER_H
