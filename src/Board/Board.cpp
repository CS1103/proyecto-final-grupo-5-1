#include "Board.h"
#include <queue>

Board::Board(const unsigned int &size){
  tablero.resize(size);
  for (auto &vec: tablero) {

    vec.resize(size);

    for (auto &casilla: vec) {
      casilla = Square(SQ_Color::EMPTY); // Use Default Constructor
    }

  }
}

std::vector<std::vector<Square>> Format(const P_Color &color, std::vector<std::vector<Square>> tableroBase){
  size_t size = tableroBase.size();
  switch (color) {
    case P_Color::BLUE:
      tableroBase.insert(tableroBase.begin(), std::vector<Square>(size, Square(SQ_Color::BLUE)));
      return tableroBase;
    case P_Color::RED:
      for(auto &vec: tableroBase){
        vec.insert(vec.begin(), Square(SQ_Color::RED));
      }
      return tableroBase;
  }
}


bool Board::verifyConnection(const P_Color &color){

  // 1) Create BFS queue q
  std::queue<Square> queue;

  std::vector<std::vector<Square>> formated_tablero = Format(color, tablero);

  // 2)scan the matrix
  for(auto& vec: formated_tablero){
    for(auto& casilla: vec){
      if(static_cast<SQ_Color>(color) == casilla.getColor()){
        queue.push(casilla);
        break;
      }
    }
  }

  /*
  // 3) run BFS algorithm with q.
  while (!queue.empty()) {
    
    Square casilla = queue.front();
    queue.pop();
    pos_x = casilla.getX();

      int i = x.i;
      int j = x.j;

      // skipping cells which are not valid.
      // if outside the matrix bounds
      if (i < 0 || i > R || j < 0 || j > C)
          continue;

      // if they are walls (value is 0).
      if (M[i][j] == 0)
          continue;

      // 3.1) if in the BFS algorithm process there was a
      // vertex x=(i,j) such that M[i][j] is 2 stop and
      // return true
      if (M[i][j] == 2)
          return true;

      // marking as wall upon successful visitation
      M[i][j] = 0;

      // pushing to queue u=(i,j+1),u=(i,j-1)
      //                 u=(i+1,j),u=(i-1,j)
      for (int k = -1; k <= 1; k += 2) {
          q.push(BFSElement(i + k, j));
          q.push(BFSElement(i, j + k));
      }
  }

  // BFS algorithm terminated without returning true
  // then there was no element M[i][j] which is 2, then
  // return false
  return false;
  */
  return true;
}

bool Board::setSquare(unsigned int squareX, unsigned int squareY, SQ_Color turnColor){
  return tablero[squareX][squareY].setColor(turnColor);
}

void Board::updateBoard(){
}
