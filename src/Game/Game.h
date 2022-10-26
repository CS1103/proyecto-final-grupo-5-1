#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>
#include <optional>
#include "../Config/Config.h"
#include "../Player/Player.h"
#include "../Board/Board.h"

class Game{
private:
    // Aditional configuration to each game
    Config m_config;
    // Player1 & player2
    std::vector<std::shared_ptr<Player>> players;

public:
  Game(const Config &config, const std::shared_ptr<Player> &player1, const std::shared_ptr<Player> &player2);
  std::optional<Player> startGame();
};

#endif // !GAME_H
