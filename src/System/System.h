#ifndef SYSTEM_H
#define SYSTEM_H

#include "../Game/Game.h"
#include "../PlayerController/PlayerController.h"
//#include "../View/View.h"
#include <memory>
#include <tuple>
#include <vector>

using UTILS::game_sett;

class System {
private:
  PlayerController players;
  std::vector<std::unique_ptr<Game>> games;
  // View vista;

  void addGameOrPlayer();
  std::string getPlayer(unsigned int number);

public:
  void run();
  System() = default;
};

#endif // !SYSTEM_H
