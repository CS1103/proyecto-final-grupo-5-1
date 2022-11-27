#include "Board.h"

#include <iomanip>
#include <memory>
#include <stack>

const unsigned int INF = std::numeric_limits<unsigned int>::max();
const unsigned int INT_TO_CHAR = 65;

using UTILS::P_Color;
using UTILS::SQ_Color;

void PrintMatrix(const std::vector<std::vector<std::shared_ptr<Square>>> &mat) {
  for (const auto &vec : mat) {
    for (const auto &obj : vec) {
      std::cout << obj->getColor() << " ";
    }
    std::cout << std::endl;
  }
}

void PrintQueue(std::queue<std::shared_ptr<Square>> que) {
  while (!que.empty()) {
    std::cout << que.front()->getColor() << ", ";
    que.pop();
  }
  std::cout << std::endl;
}

Board::Board(const unsigned int &size) {
  tablero.resize(size);
  for (auto &vec : tablero) {
    vec.resize(size);
    for (auto &casilla : vec) {
      casilla = std::make_shared<Square>(
          Square(UTILS::SQ_Color::EMPTY)); // Use Default Constructor
    }
  }
}

UTILS::matrix<UTILS::ptr_square> Board::format(const P_Color &color) const {

  UTILS::matrix<UTILS::ptr_square> return_tablero;

  for (const auto &vec : tablero) {

    std::vector<UTILS::ptr_square> temp;

    for (const auto &elem : vec) {
      temp.emplace_back(std::make_shared<Square>(Square(elem->getColor())));
    }
    return_tablero.push_back(temp);
  }

  size_t size = return_tablero.size();

  switch (color) {
  case P_Color::BLUE: {

    std::vector<std::shared_ptr<Square>> tmp_vec;
    tmp_vec.resize(size - 1);
    for (auto &obj : tmp_vec) {
      obj = std::make_shared<Square>(Square(SQ_Color::BLUE));
    }

    std::vector<std::shared_ptr<Square>> tmp_vec2;
    tmp_vec2.resize(size - 1);
    for (auto &obj : tmp_vec2) {
      obj = std::make_shared<Square>(Square(SQ_Color::BLUE));
    }

    return_tablero.insert(return_tablero.begin(), move(tmp_vec));

    return_tablero[0].emplace_back(
        std::make_shared<StartSquare>(SQ_Color::BLUE));

    return_tablero.insert(return_tablero.end(), move(tmp_vec2));
    return_tablero[size + 1].emplace_back(
        std::make_shared<EndSquare>(SQ_Color::BLUE));

    break;
  }

  case P_Color::RED: {

    for (auto it = return_tablero.begin(); it != (return_tablero.end() - 1);
         ++it) {
      it->insert(it->begin(), std::make_shared<Square>(SQ_Color::RED));
      it->insert(it->end(), std::make_shared<Square>(SQ_Color::RED));
    }

    return_tablero[size - 1].insert(
        return_tablero[size - 1].begin(),
        std::make_shared<StartSquare>(SQ_Color::RED));
    return_tablero[size - 1].insert(return_tablero[size - 1].end(),
                                    std::make_shared<EndSquare>(SQ_Color::RED));
    break;
  }
  case P_Color::NONE: {
    throw std::runtime_error("Invalid color for active player");
  }
  }
  return return_tablero;
}

bool Board::verifyConnection(const P_Color &playerColor) const {

  std::queue<std::shared_ptr<Square>> queue;

  std::vector<std::vector<std::shared_ptr<Square>>> formated_tablero =
      format(playerColor);

  // push starting point
  queue.push(formated_tablero[0][0]);

  // BFS
  while (!queue.empty()) {

    // Store as top_casilla and pop
    UTILS::ptr_square top_casilla = move(queue.front());
    queue.pop();

    // if they are invalid paths (empty or enemy)
    SQ_Color top_color = top_casilla->getColor();
    if (top_color != static_cast<SQ_Color>(playerColor)) {
      continue;
    }

    unsigned int x;     // NOLINT: short variable name
    unsigned int y = 0; // NOLINT short variable name

    // Find pos of top_casilla
    for (const auto &vec : formated_tablero) {

      auto tmp_it = find(vec.begin(), vec.end(), top_casilla);
      if (tmp_it != vec.end()) {
        x = tmp_it - vec.begin();
        break;
      }
      y++;
    }

    // if top_casilla == formated_tablero[last][last]
    if (formated_tablero[y][x] == formated_tablero.back().back()) {
      std::cout << "\nture\n\true\n\nteue\ntrue\n\n";
      return true;
    }

    // marking as wall upon successful visitation
    top_casilla->setColor(SQ_Color::EMPTY);

    // PUSH THE NEIGHBOURS
    std::vector<std::pair<int, int>> neighbours = {{y, x - 1}, {y, x + 1},
                                                   {y - 1, x}, {y - 1, x + 1},
                                                   {y + 1, x}, {y + 1, x - 1}};

    for (const auto &neighbour : neighbours) {
      if (neighbour.first >= 0 && neighbour.first < formated_tablero.size() &&
          neighbour.second >= 0 &&
          neighbour.second < formated_tablero[0].size()) {
        queue.push(formated_tablero[neighbour.first][neighbour.second]);
      }
    }
  }

  // BFS algorithm terminated without returning true
  // then there was no element M[i][j] which is 2, then
  // return false
  return false;
}

void Board::setSquare(const unsigned int &squareX, const unsigned int &squareY,
                      const UTILS::SQ_Color &turnColor) const {
  tablero[squareX][squareY]->setColor(turnColor);
}

bool Board::setSquareValidation(const unsigned int &squareX,
                                const unsigned int &squareY,
                                const UTILS::SQ_Color &turnColor) const {
  std::cout << "squareX: " << squareX << " squareY: " << squareY << std::endl;
  return tablero[squareY][squareX]->setColorValidation(turnColor);
}

// Mostrar en consola

void Board::show() const {

  // char stack = 'D' 'E' 'R';
  std::stack<char> stack;
  stack.push('D');
  stack.push('E');
  stack.push('R');

  // print board with coordinates and colors
  unsigned int size = tablero.size();

  std::cout << std::setw(3 * size / 2) << "BLUE";

  std::cout << "\n     |";
  for (unsigned int i = 1; i < size + 1; i++) {
    std::cout << std::setw(2) << i << "|";
  }

  for (unsigned int i = 0; i < size; i++) {
    std::cout << std::endl;
    if (i == 2 || i == 4 || i == 6) {
      std::cout << std::left << std::setw(2) << stack.top() << "|"
                << std::right;
      stack.pop();
    } else {
      std::cout << "  |";
    }
    std::cout << std::setw(2) << char(i + INT_TO_CHAR) << "|";
    for (unsigned int j = 0; j < size; j++) {
      std::cout << std::setw(2) << tablero[i][j]->getColor() << "|";
    }
  }
  std::cout << std::endl;
}

UTILS::matrix<unsigned int> Board::createCircuit(UTILS::P_Color color) const {

  UTILS::matrix<unsigned int> circuit;

  // populate circuit from tablero
  for (const auto &vec : format(color)) {
    std::vector<unsigned int> tmp_vec;
    for (const auto &casilla : vec) {
      if (casilla->getColor() == color) {
        tmp_vec.push_back(0);
      } else if (casilla->getColor() == SQ_Color::EMPTY) {
        tmp_vec.push_back(1);
      }
      // if oposite color
      else {
        tmp_vec.push_back(INF);
      }
    }
    circuit.push_back(tmp_vec);
  }
  return circuit;
}

float Board::evaluateBoard() const {
  // evaluate the board using electric circuits and resistances
  // https://www.aaai.org/Papers/AAAI/2000/AAAI00-029.pdf
  UTILS::matrix<unsigned int> red_circuit = createCircuit(P_Color::RED);
  UTILS::matrix<unsigned int> blue_circuit = createCircuit(P_Color::BLUE);
  return 1;
}

bool Board::erifyConnection(const P_Color &playerColor) const {

  std::queue<std::shared_ptr<Square>> queue;

  UTILS::matrix<unsigned int> circuit = createCircuit(playerColor);

  // push the start square
  // BFS algorithm terminated without returning true
  // then there was no element M[i][j] which is 2, then
  // return false
  return false;
}
