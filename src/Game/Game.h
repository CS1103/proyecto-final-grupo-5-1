#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>
#include <optional>
#include "../Config/Config.h"
#include "../Player/Player.h"


class Game
{
public:

  Game(const Config &config, const std::shared_ptr<Player> &player1, const std::shared_ptr<Player> &player2);
  std::optional<Player> startGame();

private:

  Config m_config;
  std::vector<std::shared_ptr<Player>> players;
  
};

#endif // !GAME_H
