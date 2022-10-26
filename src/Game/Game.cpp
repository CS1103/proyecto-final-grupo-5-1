#include "Game.h"

Game::Game(const Config &config, const std::shared_ptr<Player> &player1, const std::shared_ptr<Player> &player2):
  m_config(config),
  players({player1, player2}) {}

std::optional<Player> Game::startGame(){
    // Create board
    Board game_board = Board(m_config.mc_board_size);

    // Running game
    bool hay_ganador = false;
    bool hay_tiempo = false;

    int unsigned current_Player=0;
    SQ_Color current_color = SQ_Color::BLUE;

    while(true){
        Turn turno = Turno(game_board, Players[current_Player], current_color );
        bool isValidPlay = false;
        do{
            //GET jugada from vista
            const unsigned int xMove = 0;
            const unsigned int yMove = 0;
            isTimeUp = turno.isTimeUp();
            if (isTimeUp){
                break;
            }
            isValidPlay = turno.validPlay(xMove, yMove);

        }while(!isValidPlay);
        // Vista.turno terminado(isTimeUp)

        turno.stopTimer();
        std::shared_ptr<Player> winner = turno.isGameOver();
        if(winner){
            //vista.printWinner(winner);
            break;
        }
        else{
            current_Player = (current_Player == 0) ? current_Player = 1: current_Player = 0;
            current_color = (current_color == SQ_Color::BLUE) ? current_color = SQ_Color::RED : current_color = SQ_Color::BLUE;
        }
    }
}
