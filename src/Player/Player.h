#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
  Player() = default;
  Player(Player &&) = default;
  Player(const Player &) = default;
  Player &operator=(Player &&) = default;
  Player &operator=(const Player &) = default;
  ~Player() = default;

private:
  
};




#endif // !PLAYER_H
