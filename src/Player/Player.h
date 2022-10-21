#include <stdexcept>
#include <algorithm>

#ifndef PLAYER_H
#define PLAYER_H

const unsigned int MAX_NAME_LENGTH = 20;

class Player {

private:

std::string m_name;
bool m_is_winner;
char m_color;

public:

Player(const std::string &name, char &color);

bool changeName(const std::string &newName);
bool changeColor(char &newColor);

[[nodiscard]] bool isWinner() const;
[[nodiscard]] std::string getName() const;
[[nodiscard]] char getColor() const;

};

#endif // !PLAYER_H
