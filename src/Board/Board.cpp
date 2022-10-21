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

      tableroBase.insert(tableroBase.begin(), std::vector<Square>(size - 1, Square(SQ_Color::BLUE)));
      tableroBase[0][size] = StartSquare(SQ_Color::BLUE);

      tableroBase.insert(tableroBase.end(), std::vector<Square>(size - 1, Square(SQ_Color::BLUE)));
      tableroBase[0][size] = EndSquare(SQ_Color::BLUE);

      return tableroBase;

    case P_Color::RED:

      for(auto it = tableroBase.begin(); it != (tableroBase.end() - 1); ++it){
        it->insert(it->begin(), Square(SQ_Color::RED));
        it->insert(it->end(), Square(SQ_Color::RED));
      }

      tableroBase[size].insert(tableroBase[size].begin(), StartSquare(SQ_Color::RED));
      tableroBase[size].insert(tableroBase[size].end(), EndSquare(SQ_Color::RED));


      return tableroBase;
  }
}


bool Board::verifyConnection(const P_Color &playerColor){

  // 1) Create BFS queue q
  std::queue<Square> queue;

  std::vector<std::vector<Square>> formated_tablero = Format(playerColor, tablero);

  // 2)scan the matrix
  for(auto& vec: formated_tablero){
    for(auto& casilla: vec){
      if(typeid(casilla) == typeid(StartSquare)){ // Is there a better way?
        queue.push(casilla);
        break;
      }
    }
  }

  // BFS
  while (!queue.empty()) {
    
    // Store as top_casilla and pop
    Square top_casilla = queue.front();
    queue.pop();

    // if they are invalid paths (empty or enemy)
    SQ_Color top_color = top_casilla.getColor();
    if (top_color == SQ_Color::EMPTY || top_color == static_cast<SQ_Color>(playerColor)) {
        continue;
    }

    if(typeid(top_casilla) == typeid(EndSquare)){ // Is there a better way?
        return true;
    }

    // marking as wall upon successful visitation
    top_casilla.setColor(SQ_Color::EMPTY);


    // PUSH THE NEIGHBOURS
    // Evualate at Square?
    for(auto& neighbor: top_casilla.getNeighbors()){
      queue.push(neighbor);
    }

    // Evaluate at Board?
    /*
    for (int k = -1; k <= 1; k += 2) {
        q.push(BFSElement(i + k, j));
        q.push(BFSElement(i, j + k));
    }
    */
  }

  // BFS algorithm terminated without returning true
  // then there was no element M[i][j] which is 2, then
  // return false
  return false;
}

bool Board::setSquare(unsigned int squareX, unsigned int squareY, SQ_Color turnColor){
  return tablero[squareX][squareY].setColor(turnColor);
}

void Board::updateBoard(){
}
