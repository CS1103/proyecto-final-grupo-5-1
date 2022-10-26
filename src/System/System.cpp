#include "System.h"

/*System::System(){

}*/

void System::run(){
    // Configuracion
    Config config;

    // Llamar a game
    Game(config, player1, player2);
}