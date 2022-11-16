#ifndef PLAYER_H
#define PLAYER_H

#include "../utils.h"
#include <algorithm>
#include <compare>
#include <memory>
#include <stdexcept>

class Player {

private:
  std::string m_name;
  bool m_is_winner;
  P_Color m_color;

public:
  Player(const std::string &name, const P_Color &color = P_Color::NONE);

  bool changeName(const std::string &newName);
  void changeColor(P_Color &newColor);

  [[nodiscard]] std::string getName() const;
  [[nodiscard]] P_Color getColor() const;

  // overload operator == for shared pointers of Player
  friend bool operator==(const std::shared_ptr<Player> &pPointer,
                         const std::string &pName);
};

#endif // !PLAYER_H
