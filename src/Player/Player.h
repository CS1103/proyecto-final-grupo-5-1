#include <string>

#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:

std::string name;
bool is_winner;
char color;

public:

void ChangeName(std::string new_name);
void ChangeColor(char new_color);

};

#endif // !PLAYER_H
