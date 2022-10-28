#include "Game.h"

Game::Game(const Config &config, const std::shared_ptr<Player> &player1,
           const std::shared_ptr<Player> &player2)
    : m_config(config), players({player1, player2}) {

  // From vist select player colors
}

std::optional<Player> Game::startGame() {

  // Create board
  Board game_board = Board(m_config.getSize());

  // Running game
  bool hay_ganador = false;
  bool hay_tiempo = false;

  unsigned int current_player = 0;
  P_Color current_color = P_Color::BLUE;

  while (true) {
    Turn turno = Turn(game_board, current_color, m_config.getTime());
    bool is_valid_play = false;
    unsigned int x_move = 0;
    unsigned int y_move = 0;
    do {
      // GET jugada from vista
      bool is_time_up = turno.isTimeUp();
      if (is_time_up) {
        break;
      }
      is_valid_play = turno.validPlay(x_move, y_move);

    } while (!is_valid_play);
    // Vista.turno terminado(isTimeUp)

    turno.stopTimer();
    std::shared_ptr<Player> winner = turno.isGameOver();
    if (winner) {
      // vista.printWinner(winner);
      break;
    } else {
      current_player =
          (current_player == 0) ? current_player = 1 : current_player = 0;
      current_color = (current_color == SQ_Color::BLUE)
                          ? current_color = SQ_Color::RED
                          : current_color = SQ_Color::BLUE;
    }
  }
}
