#include <iostream>
#include "Game.h"
using namespace std;


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
