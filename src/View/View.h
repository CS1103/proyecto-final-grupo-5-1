#ifndef VIEW_H
#define VIEW_H

#include "boost/variant.hpp"
#include <SFML/Graphics.hpp>

#include "Button.h"
#include "TextField.h"
#include <cmath>
#include <initializer_list>
#include <iostream>
#include <map>
#include <memory>
#include <utility>

#include "../utils.h"
#include "Movement.h"

using movement =
    boost::variant<Movement<sf::Sprite>, Movement<Button>, Movement<TextField>>;

[[maybe_unused]] const unsigned int VIEW_WIDTH = 800;
[[maybe_unused]] const unsigned int VIEW_HEIGHT = 600;

[[maybe_unused]] const float SPRITE_INITIAL_SPEED = 40;
[[maybe_unused]] const float SPRITE_INITIAL_ACCEL = 10;

[[maybe_unused]] const float SPRITE_MOVEMENT_LEWAY = 500;

class View {
public:
  View();
  void startScreen();
  char newGameOrPlayer();
  void showMsg(const std::string &message);
  std::string createPlayer();
  game_sett createGame(const std::vector<std::string> &names);

private:
  std::unique_ptr<sf::RenderWindow> window;
  std::chrono::microseconds deltaTime;

  // Move mutiple sprites as tuples
  void moveObjects(std::vector<movement> &movements);
  void drawOnWindow(
      std::initializer_list<std::reference_wrapper<sf::Drawable>> drawables);
  void loadSprites(std::string name, const char &level,
                   const std::string &file);
  void loadSprites(const std::string &name, const char &level);
};

class MovementVisitor : public boost::static_visitor<> {
  template <typename T> void operator()(Movement<T> &m) const { m.move(); }
  void operator()(Movement<T> &textField) const {}
};

#endif // !VIEW_H
