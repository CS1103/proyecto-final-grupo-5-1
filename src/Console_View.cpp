#include "Player/Player.h"
#include "Board/Board.h"
#include "Square/Square.h"
#include "Turn/Turn.h"

void jugador_jugador(){
    std::string nombre1;
    std::string nombre2;
    std::cout<<"Jugador 1 ingrese su nombre"<<std::endl;
    std::cin>>nombre1;
    std::cout<<"Jugador 2 ingrese su nombre"<<std::endl;
    std::cin>>nombre2;
    Player player1(nombre1, P_Color::RED);
    Player player2(nombre2, P_Color::BLUE);
    Board board(11);

    Turn turno(board, P_Color::BLUE, std::chrono::seconds(1));
    board.show();
}

void jugador_computador(){

}

void menu(){
    int option=0;
    std::cout<<"Bienevenido al CHIQUIHEX"<<std::endl;
    std::cout<<"Seleccione el modo de juego"<<std::endl;
    std::cout << "1. JUGADOR  VS JUGADOR " << std::endl;
    std::cout << "2. JUGADOR  VS COMPUTADOR " << std::endl;

    std::cin>>option;
    while(option!=1 && option!=2){
        std::cout<<"Opcion no valida, ingrese nuevamente"<<std::endl;
        std::cin>>option;
    }
    switch (option) {
        case 1:
            std::cout<<"ELEGISTE EL MODO JUGADOR VS JUGADOR"<<std::endl;
            jugador_jugador();
        break;
        case 2:
            std::cout<<"ELEGISTE EL MODO JUGADOR VS COMPUTADOR"<<std::endl;
        break;
    }
}

