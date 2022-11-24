#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>

#include <cmath>
#include <initializer_list>
#include <iostream>
#include <map>
#include <memory>
#include <utility>

#include "../utils.h"
#include "Movement.h"
#include "TextBox.h"

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
  std::map<std::pair<std::string, unsigned int>, std::shared_ptr<sf::Drawable>>
      sprites;
  std::unique_ptr<sf::RenderWindow> window;
  std::chrono::microseconds deltaTime;

  // Move mutiple sprites as tuples
  void moveSprites(std::vector<Movement> movements);
  void drawSprites(std::initializer_list<std::string> spriteNames);
  void drawSprites();
  void loadSprites(std::string name, const char &level,
                   const std::string &file);
  void loadSprites(const std::string &name, const char &level);
};

#endif // !VIEW_H
