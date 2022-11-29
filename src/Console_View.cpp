#include "Board/Board.h"
#include "Config/Config.h"
#include "Game/Game.h"
#include "Player/Player.h"
#include "Square/Square.h"
#include "Turn/Turn.h"
#include "Bot/Bot.h"

void JugadorJugador() {
  std::string nombre1;
  std::string nombre2;
  std::cout << "\n ❏ Jugador 1 ingrese su nombre ▷ " << std::endl;
  std::cin >> nombre1;
  std::cout << "\n ❏ Jugador 2 ingrese su nombre ▷ " << std::endl;
  std::cin >> nombre2;
  Player player1(nombre1, P_Color::BLUE);
  Player player2(nombre2, P_Color::RED);
  TipoJ tipo1 = TipoJ::HUMANO_HUMANO;
  Config config(tipo1);
  Game game(config, std::make_shared<Player>(player1),
            std::make_shared<Player>(player2));
  std::cout << "Que empiece el juego! 🔹🔸🤺" << std::endl;

  game.startCliGame();
  // Turn turno(board, P_Color::BLUE, std::chrono::seconds(1));
}

void JugadorComputador() {
    std::string nombre1;
    std::string nombre2;
    std::cout << "\n ❏ Jugador  ingrese su nombre ▷ " << std::endl;
    std::cin >> nombre1;
    Player player1(nombre1, P_Color::RED);
    Bot bot(Difficulty::EASY, P_Color::BLUE);
    TipoJ tipo1 = TipoJ::HUMANO_COMPUTADOR;
    Config config(tipo1);
    Game game(config,std::make_shared<Player>(bot),std::make_shared<Player>(player1));
    std::cout << "Que empiece el juego! ¿Un bot te ganara? 🔹🔸🤺" << std::endl;

    game.startCliGame();
}

void Menu() {
  int option = 0;
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
    JugadorJugador();
    break;
  case 2:
      std::cout << "\n Elegiste el modo JUGADOR VS COMPUTADOR 🧑‍💻" << std::endl;
    JugadorComputador();
    break;
  }
}
