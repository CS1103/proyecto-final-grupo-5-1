#include "View.h"

int main(int argc, char *argv[]) {

  View vista;
  vista.startScreen();

  char option;
  bool valid_game = false;

  do {
    option = vista.newGameOrPlayer();
    if (option == 'g') {
      // If size of players < 2, then vista.error("not enough players") and
      // break;
      valid_game = true;
    } else if (option == 'p') {
      // new player = vista.newPlayer();
      //  players.push_back(new player);
    }
  } while (!valid_game);
  // Set config and players
  std::tuple<std::string, std::string, TipoJ, seconds, unsigned int>
      game_settings;
  gameSettings = vista.createGame(players);
  new config(gameSettings[2], gameSettings[3], gameSettings[4]);
  new Game(gameSettings[0], gameSettings[1], config);
  vista.startGame();
}
