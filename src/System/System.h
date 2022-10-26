#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <memory>
#include "../PlayerController/PlayerController.h"
#include "../Game/Game.h"

class System{
private:
    // Vector de players
    PlayerController players;
    // Vector de games
    std::vector<std::unique_ptr<Game>> games;

public:
  System() = default;
  void run();
};

#endif // !SYSTEM_H
