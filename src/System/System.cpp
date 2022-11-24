#include "System.h"

/*
  PlayerController players;
  // Vector de games
  std::vector<std::unique_ptr<Game>> games;

  View vista;
*/

void System::addGameOrPlayer() {
  char option;
  bool valid_game = false;

  do {
    option = vista.newGameOrPlayer();
    if (option == 'g') {
      if (players < 2) {
        vista.showMsg("No hay suficientes jugadores");
        continue;
      }
      valid_game = true;
    } else if (option == 'p') {

      std::cout << "here";
      if (!players.addPlayer(vista.createPlayer())) {
        vista.showMsg("Ya existe un jugador con ese nombre");
      }
    }
  } while (!valid_game);
}

void System::run() {
  vista.startScreen();
  addGameOrPlayer();

  game_sett game_settings = vista.createGame(players.getNames());
  Config conf = Config(std::get<2>(game_settings), std::get<3>(game_settings),
                       std::get<4>(game_settings));

  auto pl1 = players[std::get<0>(game_settings)];
  auto pl2 = players[std::get<1>(game_settings)];

  // Create game object
  games.emplace_back(std::make_unique<Game>(Game(conf, pl1, pl2)));
}
