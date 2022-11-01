#ifndef SYSTEM_H
#define SYSTEM_H

#include "../Game/Game.h"
#include "../PlayerController/PlayerController.h"
#include "../View/View.h"
#include <memory>
#include <tuple>
#include <vector>

class System {
private:
  // Vector de players
  PlayerController players;
  // Vector de games
  std::vector<std::unique_ptr<Game>> games;

  View vista;

  void addGameOrPlayer();

public:
  void run();
  System() = default;
};

#endif // !SYSTEM_H
