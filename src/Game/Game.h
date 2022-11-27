#ifndef GAME_H
#define GAME_H

#include "../Config/Config.h"
#include "../Player/Player.h"
#include "../Turn/Turn.h"
#include "../utils.h"
#include <memory>
#include <optional>
#include <vector>

using UTILS::ptr_player;

class Game {
private:
  // Aditional configuration to each game
  Config m_config;
  // Player1 & player2
  std::vector<ptr_player> players;

public:
  Game(const Config &config, const ptr_player &player1,
       const ptr_player &player2);
  std::optional<std::shared_ptr<Player>> startGame();
  std::optional<std::shared_ptr<Player>> startCliGame();
  [[nodiscard]] std::tuple<unsigned int, unsigned int> getMove() const;
};

#endif // !GAME_H
