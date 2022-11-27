#include "Bot.h"

// random code
std::string GetRandomName() {
  std::string code;
  const unsigned int CODE_LENGTH = 6;
  for (int i = 0; i < 3; i++) {
    code += std::to_string(rand() % CODE_LENGTH);
  }
  return "Bot " + code;
}

Bot::Bot(Difficulty difficulty,P_Color color)
    : Player(GetRandomName(),color), difficulty(difficulty) {}

unsigned int EvaluateMove(const movement &movement, const Board &board) {}

movement Bot::computeMove(const Board &board) const { return {2, 4}; }

//Implementando VerifyConnection:

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

