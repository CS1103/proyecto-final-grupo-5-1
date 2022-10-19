#include <string>

#ifndef PLAYER_H
#define PLAYER_H

class Player {

private:

std::string m_name;
bool m_is_winner;
char m_color;

public:

void ChangeName(std::string new_name);
void ChangeColor(char new_color);
bool IsWinner();

};

#endif // !PLAYER_H
