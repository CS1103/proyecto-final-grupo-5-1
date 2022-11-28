#include "Game.h"
#include <stack>

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

std::tuple<unsigned int, unsigned int> Game::getMove() const {

  unsigned int x_move = 0;
  unsigned int y_move = 0;
  char y_char = 0;

  bool is_valid_move = false;

  do {

    // reset cin
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Ingrese la coordenada X(numérica): ";
    std::cin >> x_move;
    std::cout << "Ingrese la coordenada Y: ";
    std::cin >> y_char;
    y_move = int(tolower(y_char)) - 96;
    // muy altas
    if (x_move > m_config.BOARD_SIZE || y_move > m_config.BOARD_SIZE) {
      std::cout << "Coordenada fuera de rango. Intente de nuevo" << std::endl;
      continue;
    }
    // muy bajas
    if (x_move < 0 || y_move < 0) {
      std::cout << "Coordenada fuera de rango. Intente de nuevo" << std::endl;
      continue;
    }

    is_valid_move = true;

  } while (!is_valid_move);

  return std::make_tuple(x_move - 1, y_move - 1);
}

std::optional<std::shared_ptr<Player>> Game::startCliGame() {
    // Juego para humano vs humano
    if(m_config.tipo_juego == UTILS::TipoJ::HUMANO_HUMANO) {

        // predefined moves
        std::stack<std::tuple<unsigned int, unsigned int>> moves_blue;
        std::stack<std::tuple<unsigned int, unsigned int>> moves_red;

        for (int i = 11; i > 0; i--) {
            moves_red.push(std::make_tuple(i - 1, 0));
            moves_blue.push(std::make_tuple(i - 1, 5));
        }

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
            game_board.show();

            do {
                // print player color
                switch (current_color) {
                    case P_Color::BLUE:
                        std::cout << "Blue player (" << players[current_player]->getName()
                                  << ") move: \n";
                        break;
                    case P_Color::RED:
                        std::cout << "Red player (" << players[current_player]->getName()
                                  << ") move: \n";
                        break;
                    default:
                        throw std::runtime_error("Invalid player color");
                }

                // predefined moves
                /*
                if (!moves_red.empty()) {
                    switch (current_color) {
                        case P_Color::BLUE:
                            std::tie(x_move, y_move) = moves_blue.top();
                            moves_blue.pop();
                            break;
                        case P_Color::RED:
                            std::tie(x_move, y_move) = moves_red.top();
                            moves_red.pop();
                            break;
                        default:
                            throw std::runtime_error("Invalid player color");
                    }

                }
                 else {
                 */
                    std::tie(x_move, y_move) = getMove();
                //}

                // GET jugada from vista
                is_time_up = turno.isTimeUp();
                if (is_time_up) {
                    break;
                }
                is_valid_play = turno.validPlay(x_move, y_move);
                if (!is_valid_play) {
                    std::cout << "Invalid play, try again" << std::endl;
                }

            } while (!is_valid_play);
            // Vista.turno terminado(isTimeUp)
            game_board.show();
            turno.stopTimer();
            winner_color = turno.isGameOver();
            if (winner_color.has_value()) {
                // vista.printWinner(winner);

                // Return players from players that matches winner_color
                switch (winner_color.value()) {
                    case P_Color::BLUE:
                        std::cout << "Blue player (" << players[0]->getName()
                                  << ") wins! \n";
                        return players[0];
                    case P_Color::RED:
                        std::cout << "Red player (" << players[1]->getName()
                                  << ") wins! \n";
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
    // Juego Humano-Computador
    else if (m_config.tipo_juego == UTILS::TipoJ::HUMANO_COMPUTADOR){
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
            game_board.show();

            do {
                // print player color
                switch (current_color) {
                    case P_Color::BLUE:
                        std::cout << "Blue player (" << players[current_player]->getName()
                                  << ") move: \n";
                        break;
                    case P_Color::RED:
                        std::cout << "Red player (" << players[current_player]->getName()
                                  << ") move: \n";
                        break;
                    default:
                        throw std::runtime_error("Invalid player color");
                }

                // predefined moves
                if (current_player==1) {
                    std::tie(x_move, y_move) = getMove();
                }
                else if(current_player==0) {
                    Bot bot(Difficulty::EASY, P_Color::BLUE);
                    // Verificacion de mejor jugada(camino a seguir)
                    if(current_color==P_Color::BLUE){
                        std::tie(x_move, y_move) = bot.next(game_board,SQ_Color::RED);
                    }
                    else{
                        std::tie(x_move, y_move) = bot.next(game_board,SQ_Color::BLUE);
                    }

                    /*
                    x_move=rand()%(m_config.BOARD_SIZE-1) ;
                    y_move=rand()%(m_config.BOARD_SIZE-1) ;
                     */
                    //std::tie(x_move, y_move) = players[current_player]->computeMove(game_board);
                }

                // GET jugada from vista
                is_time_up = turno.isTimeUp();
                if (is_time_up) {
                    break;
                }
                is_valid_play = turno.validPlay(x_move, y_move);
                if (!is_valid_play) {
                    std::cout << "Invalid play, try again" << std::endl;
                }

            } while (!is_valid_play);
            // Vista.turno terminado(isTimeUp)
            game_board.show();
            turno.stopTimer();
            winner_color = turno.isGameOver();
            if (winner_color.has_value()) {
                // vista.printWinner(winner);

                // Return players from players that matches winner_color
                switch (winner_color.value()) {
                    case P_Color::BLUE:
                        std::cout << "Blue player (" << players[0]->getName()
                                  << ") wins! \n";
                        return players[0];
                    case P_Color::RED:
                        std::cout << "Red player (" << players[1]->getName()
                                  << ") wins! \n";
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
}
