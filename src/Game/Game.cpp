#include "Game.h"

Game::Game(const Config &config, const std::shared_ptr<Player> &player1,
           const std::shared_ptr<Player> &player2)
    : m_config(config), players({player1, player2}) {

  // From vist select player colors
}

std::optional<std::shared_ptr<Player>> Game::startGame() {

  // Create board
  Board game_board = Board(m_config.BOARD_SIZE);
  // Running game
  bool is_time_up = false;
  std::optional<P_Color> winner_color;

  unsigned int current_player = 0;
  P_Color current_color = P_Color::BLUE;

  while (true) {
    Turn turno = Turn(game_board, current_color, m_config.time_limit);
    bool is_valid_play = false;
    unsigned int x_move = 0;
    unsigned int y_move = 0;
    do {
      // GET jugada from vista
      is_time_up = turno.isTimeUp();
      if (is_time_up) {
        break;
      }
      is_valid_play = turno.validPlay(x_move, y_move);

    } while (!is_valid_play);
    // Vista.turno terminado(isTimeUp)

    turno.stopTimer();
    winner_color = turno.isGameOver();
    if (winner_color.has_value()) {
      // vista.printWinner(winner);

      // Return players from players that matches winner_color
      switch (winner_color.value()) {
      case P_Color::BLUE:
        return players[0];
      case P_Color::RED:
        return players[1];
      case P_Color::NONE:
        throw std::runtime_error("Winner color is NONE");
      }
    }
    current_player = (current_player == 0) ? 1 : 0;
    current_color =
        (current_color == P_Color::BLUE) ? P_Color::RED : P_Color::BLUE;
  }
}

std::optional<std::shared_ptr<Player>> Game::startGame2() {

  // Create board
  Board game_board = Board(m_config.BOARD_SIZE);
  game_board.show();

  // Running game
  bool is_time_up = false;
  std::optional<P_Color> winner_color;

  unsigned int current_player = 0;
  P_Color current_color = P_Color::BLUE;

  while (true) {
    Turn turno = Turn(game_board, current_color, m_config.time_limit);
    bool is_valid_play = false;
    unsigned int x_move = 0;
    unsigned int y_move = 0;

    do {
      std::cout << "Ingrese la coordenada X "
                << players[current_player]->getName() << ":" << std::endl;
      std::cin >> x_move;
      std::cout << "Ingrese la coordenada Y "
                << players[current_player]->getName() << ":" << std::endl;
      std::cin >> y_move;

      // GET jugada from vista
      is_time_up = turno.isTimeUp();
      if (is_time_up) {
        break;
      }
      is_valid_play = turno.validPlay(x_move, y_move);

    } while (!is_valid_play);
    // Vista.turno terminado(isTimeUp)

    turno.stopTimer();
    winner_color = turno.isGameOver();
    if (winner_color.has_value()) {
      // vista.printWinner(winner);

      // Return players from players that matches winner_color
      switch (winner_color.value()) {
      case P_Color::BLUE:
        return players[0];
      case P_Color::RED:
        return players[1];
      case P_Color::NONE:
        throw std::runtime_error("Winner color is NONE");
      }
    }
    game_board.show();
    current_player = (current_player == 0) ? 1 : 0;
    current_color =
        (current_color == P_Color::BLUE) ? P_Color::RED : P_Color::BLUE;
  }
}
