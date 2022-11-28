#include "Bot.h"
// FUNCIONES EXTERNAS -------------
// random code
std::string GetRandomName() {
  std::string code;
  const unsigned int CODE_LENGTH = 6;
  for (int i = 0; i < 3; i++) {
    code += std::to_string(rand() % CODE_LENGTH);
  }
  return "Bot " + code;
}

unsigned int EvaluateMove(const movement &movement, const Board &board) {}

//CONSTRUCTOR -------------
// Constructor de asignacion
Bot::Bot(Difficulty difficulty,P_Color color)
    : Player(GetRandomName(),color), difficulty(difficulty) {}
// METODOS -------------
movement Bot::computeMove(const Board &board) const {return {2,4};}

// Funcion format
UTILS::matrix<UTILS::ptr_square> Bot::formatBot(const P_Color &color,  Board board) const {

    UTILS::matrix<UTILS::ptr_square> return_tablero;

    for (const auto &vec :  board.get_tablero()) {

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


//Implementando VerifyConnection
bool Bot::automatizarBot(const P_Color &playerColor, const Board &board) const {

    std::queue<std::shared_ptr<Square>> queue;

    std::vector<std::vector<std::shared_ptr<Square>>> formated_tablero = formatBot(playerColor,board);

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

double Bot::getWins(Board &board,SQ_Color color)
{
    auto blank = board.getEmpty();
    int winCount = 0;
    std::vector<int> perm(blank.size());
    for (int i=0; i<perm.size(); i++)
        perm[i] = i;
    for (int n=0; n<1000; n++)
    {
        int turn = (color == UTILS::SQ_Color::BLUE ? 0 : 1);
        for (int i=perm.size(); i>1; i--)
        {
            int swap = rand() % i;
            int temp = perm[i-1];
            perm[i-1] = perm[swap];
            perm[swap] = temp; // prand the permutation
        }
        for (int i=0; i<perm.size(); i++)
        {
            turn = !turn; //easy bool turn tracking
            int x = blank[perm[i]].first;
            int y = blank[perm[i]].second;
            if (turn)
            {
                board.place(x, y, UTILS::SQ_Color::BLUE);
            }
            else
            {
                board.place(x, y, UTILS::SQ_Color::RED);
            }
        }
        if (board.winner() == color)
            winCount++;

        for (auto itr = blank.begin(); itr != blank.end(); ++itr)
            board.badMove(itr->first, itr->second); // take back rand moves
    }
    return static_cast<double>(winCount) / 1000;
}

// montecarlo simulation, with getWins() it finds the
// value of moves by making random permutations and doing simulation moves
// on each and tracks no. wins. The moves are given the no.wins as a move
// value, the best value is the best move.
std::pair<int, int> Bot::next(Board &board, SQ_Color color)
{
    auto blank = board.getEmpty();
    double bestMove = 0;
    std::pair<int, int> move = blank[0];

    for (int i=0; i<blank.size(); i++)
    {
        int x = blank[i].first;
        int y = blank[i].second;
        board.place(x, y, color);

        double moveValue = getWins(board, color);
        if (moveValue > bestMove)
        {
            move = blank[i];
            bestMove = moveValue;
        }

        board.badMove(x, y);
    }
    return move;
}
