#include "Board.h"
#include <queue>
#include <algorithm>


Board::Board(const unsigned int &size){
  tablero.resize(size);
  for (auto &vec: tablero) {
    vec.resize(size);
    for (auto &casilla: vec) {
      casilla = std::make_unique<Square>(Square(SQ_Color::EMPTY)); // Use Default Constructor
    }

  }
}

void Format(const P_Color &color, const std::vector<std::vector<std::shared_ptr<Square>>> &tablerobase, std::vector<std::vector<std::shared_ptr<Square>>> &returnTablero){


  for(const auto &vec: tablerobase){

    std::vector<std::shared_ptr<Square>> temp;
    temp.reserve(vec.size());

    for (const auto& elem: vec){
        temp.push_back(std::make_unique<Square>(*elem));
    }
    returnTablero.push_back(std::move(temp));
  }

  size_t size = returnTablero.size();




  switch (color) {
    case P_Color::BLUE:{

      std::vector<std::shared_ptr<Square>> tmp_vec;
      tmp_vec.resize(size - 1);
      for(auto &obj: tmp_vec){
          obj = std::make_unique<Square>(Square(SQ_Color::BLUE));
      }

      std::vector<std::shared_ptr<Square>> tmp_vec2;
      tmp_vec2.resize(size - 1);
      for(auto &obj: tmp_vec2){
          obj = std::make_unique<Square>(Square(SQ_Color::BLUE));
      }

      returnTablero.insert(returnTablero.begin(), std::move(tmp_vec));

      returnTablero[0].emplace_back(std::make_unique<StartSquare>(SQ_Color::BLUE));

      returnTablero.insert(returnTablero.end(), std::move(tmp_vec2));
      returnTablero[size + 1 ].emplace_back(std::make_unique<EndSquare>(SQ_Color::BLUE));

      break;

    }


    case P_Color::RED:{

      for(auto it = returnTablero.begin(); it != (returnTablero.end() - 1); ++it){
        it->insert(it->begin(), std::make_unique<Square>(SQ_Color::RED));
        it->insert(it->end(), std::make_unique<Square>(SQ_Color::RED));
      }

      returnTablero[size - 1].insert(returnTablero[size - 1].begin(), std::make_unique<StartSquare>(SQ_Color::RED));
      returnTablero[size - 1].insert(returnTablero[size-1].end(), std::make_unique<EndSquare>(SQ_Color::RED));
      break;
    }
  }
}


bool Board::verifyConnection(const P_Color &playerColor){

  std::queue<std::shared_ptr<Square>> queue;

  std::vector<std::vector<std::shared_ptr<Square>>> formated_tablero;
  Format(playerColor, tablero, formated_tablero);

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
    std::shared_ptr<Square> top_casilla = std::move(queue.front());
    queue.pop();

    // if they are invalid paths (empty or enemy)
    SQ_Color top_color = top_casilla->getColor();
    if (top_color == SQ_Color::EMPTY || top_color == static_cast<SQ_Color>(playerColor)) {
        continue;
    }

    if(typeid(top_casilla) == typeid(EndSquare)){ // Is there a better way?
        return true;
    }

    // marking as wall upon successful visitation
    top_casilla->setColor(SQ_Color::EMPTY);


    unsigned int x;
    unsigned int y = 0;

    // Find pos of top_casilla
    for(const auto &vec: formated_tablero){

      auto tmp_it = find(vec.begin(), vec.end(), top_casilla);
      if(tmp_it != vec.end()){
        x = tmp_it - vec.begin();

      }
      y++;

    }

    // PUSH THE NEIGHBOURS
    queue.push(formated_tablero[x][y-1]);
    queue.push(formated_tablero[x][y+1]);
    queue.push(formated_tablero[x-1][y]);
    queue.push(formated_tablero[x-1][y+1]);
    queue.push(formated_tablero[x+1][y]);
    queue.push(formated_tablero[x+1][y-1]);
  }

  // BFS algorithm terminated without returning true
  // then there was no element M[i][j] which is 2, then
  // return false
  return false;
}

bool Board::setSquare(unsigned int squareX, unsigned int squareY, SQ_Color turnColor){
  return tablero[squareX][squareY]->setColor(turnColor);
}

void Board::updateBoard(){
}
