/*#include "System/System.h"

int main(int argc, char *argv[]) {
    System sistema;
    sistema.run();
}*/

#include "Player/Player.h"
#include "Board/Board.h"
#include "Square/Square.h"
#include "Turn/Turn.h"

using namespace std;

int main (int argc, char *argv[])
{
    Player player("Player 1", P_Color::RED);
    Board board(10);
    Square square(SQ_Color::RED);

    Turn turno(board, P_Color::BLUE, std::chrono::seconds(1));

    board.show();


    return 0;
}
