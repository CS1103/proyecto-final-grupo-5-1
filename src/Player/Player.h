#include <stdexcept>

#ifndef PLAYER_H
#define PLAYER_H

class Player {

private:

std::string m_name;
bool m_is_winner;
char m_color;

public:

Player(const std::string &name, char &color);

bool ChangeName(const std::string &new_name);
bool ChangeColor(char &new_color);
bool IsWinner();

std::string GetName() const;
char GetColor() const;

};

#endif // !PLAYER_H
