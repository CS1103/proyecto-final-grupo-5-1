#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <memory>
#include "../View/View.h"
#include "../PlayerController/PlayerController.h"
#include "../Game/Game.h"

class System{
private:
    // Vector de players
    PlayerController players;
    // Vector de games
    std::vector<std::unique_ptr<Game>> games;

    View vista;

public:
  System() = default;
  void run();
};

#endif // !SYSTEM_H
