#include "Game.h"

Game::Game(const Config &config, const std::shared_ptr<Player> &player1, const std::shared_ptr<Player> &player2):
  m_config(config),
  players({player1, player2}) {}


std::optional<Player> Game::startGame(){
    // Player
    shared_ptr<Player> player1 = players[0];

    // There is an additional config
    if(m_config != NULL){
        // Change default config
    }
    // Create board
    Board game_board = Board(config.size);

    // Running game
    bool m_playing = true;
    bool hay_ganador = false;
    bool hay_tiempo = false;

    while(m_playing){


        // Continua corriendo si queda tiempo
        hay_tiempo =

        // Continua corriendo si no hay ganador
        hay_ganador = players[0]->isWinner() == false and players[1]->isWinner()== false;

        if(hay_ganador)
            m_playing = true;

    }
}
// PSEUDOCODIGO

/*
 Iniciar Juego:

 config_opcional = vista.configurarJuego()
 if config_opcional != None:
    cambiar configuracion


  board = Board(config.tamaño)
 
 while (game is not over)
 {

  turno = Turno(board, color, config.tiempo)


  do{

    //Alternativas del temporizador:

    // ALTERNATIVA 2: Utilizar eventos
    // GET MOVIMIENTO x, y
    // Utilizar vista?
    
    // ALTERNATIVA 1: Validar tras cada movimiento (funcional)
    if turno->isTimeLimitOver(){
      break
    }

    is_valid = turno->valid play(casilla x, casilla y):
  } while (!is_valid)

  turno->stop_timer()

  game_over = turno->game_over()

 }

 vista.mostrar_resultado()

*/
