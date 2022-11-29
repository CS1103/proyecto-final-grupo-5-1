#include "System.h"
#include "../Bot/Bot.h"

/*
  PlayerController players;
  // Vector de games
  std::vector<std::unique_ptr<Game>> games;

  View vista;
*/

/*
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
*/

std::string System::getPlayer(unsigned int number) {
  std::string nombre;
  std::cout << "\n❏ Jugador " << number << " ingrese su nombre ▷ " << std::endl;
  std::cin >> nombre;
  while (!players.addPlayer(nombre)) {
    std::cout << "❌ nombre invalido\n";
    // clean cin
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> nombre;
  }
  return nombre;
}

std::string System::getBot() {
  UTILS::ptr_player bot = std::make_shared<Bot>();
  players.addPlayer(bot);
  return bot->getName();
}

unsigned int GetGameType() {
  unsigned int option = 0;
    std::cout << "\n\t\t ├┴┬┴█≣█┴┬┴┤ 🔹🔸 BIENVENIDO AL CHIQUIHEX 🔹🔸 ├┴┬┴█≣█┴┬┴┤ \n" << std::endl;
    std::cout << "\n❏ Seleccione el modo de juego (1 o 2):  " << std::endl;
    std::cout << "\n\t 1. JUGADOR  VS JUGADOR " << std::endl;
    std::cout << "\n\t 2. JUGADOR  VS COMPUTADOR " << std::endl;

  std::cin >> option;
  while (option != 1 && option != 2) {
      std::cout << "\n❌ Opcion no valida, ingrese nuevamente ❌" << std::endl;
    std::cin >> option;
  }
  switch (option) {
  case 1:
      std::cout << "\n Elegiste el modo JUGADOR VS JUGADOR 🧑🧑" << std::endl;
    break;
  case 2:
      std::cout << "\n Elegiste el modo JUGADOR VS COMPUTADOR 🧑‍💻" << std::endl;
    break;
  default:
    break;
  }
  return option;
}

void System::run() {
  std::string pl1;
  std::string pl2;
  Config conf;
  switch (GetGameType()) {
  case 1:
    pl1 = getPlayer(1);
    pl2 = getPlayer(2);
    break;
  case 2:
    pl1 = getPlayer(1);
    pl2 = getBot();
    break;
  default:
    break;
  }
  Game game(conf, players[pl1], players[pl2]);
  game.startCliGame();
}
