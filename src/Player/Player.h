#ifndef PLAYER_H
#define PLAYER_H

#include <stdexcept>
#include <algorithm>

enum class P_Color: char { BLUE = 'b', RED = 'r' };

const unsigned int MAX_NAME_LENGTH = 20;

class Player {

private:
    std::string m_name;
    bool m_is_winner;
    P_Color m_color;

public:
    Player(const std::string &name,const P_Color &color);

    bool changeName(const std::string &newName);
    void changeColor(P_Color &newColor);

    [[nodiscard]] bool isWinner() const;
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] P_Color getColor() const;

};

#endif // !PLAYER_H
