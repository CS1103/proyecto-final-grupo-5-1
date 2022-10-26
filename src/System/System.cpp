#include "System.h"

System::System(){
    // onstruir vista
    vista
    controlladoraPersonas
    PersonController pControler();
    vectorJuegos

}

void System::run(){
    // Datos de jugadores
    //Config config = vista.getConfig()

    // Configuracion
    Config config(TipoJ::HUMANO_HUMANO, std::chrono::seconds(180));

    // Añadir jugadores
    pController.addPlayer(make_shared<Player>(Player("name")) )
    pController.addPlayer(make_shared<Player>(Player("name2")) )

    // Llamar a game
    Game juego1(config, pController[0], pController.at(1));
    juego1.startGame();

}