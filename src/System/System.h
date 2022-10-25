#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <memory>
#include "../PlayerController/PlayerController.h"
#include "../Game/Game.h"

class System
  
{

public:
  System();
  void run();

private:

  PlayerController players;
  std::vector<std::unique_ptr<Game>> games;
  
};

#endif // !SYSTEM_H
