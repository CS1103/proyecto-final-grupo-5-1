#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <cmath>
#include <initializer_list>
#include <iostream>
#include <map>
#include <memory>
#include <utility>

#include "../Config/Config.h"
#include "../PlayerController/PlayerController.h"
#include "../utils.h"

using game_sett =
    std::tuple<std::string, std::string, TipoJ, seconds, unsigned int>;

// Store sprite, speed, acceleration and distance
struct Movement {

  std::string sprite;
  sf::Vector2f speed;
  sf::Vector2f acceleration;
  sf::Vector2f max_distance;

  Movement(std::string sprite, sf::Vector2f speed, sf::Vector2f acceleration,
           sf::Vector2f distance);
};

class View {
public:
  View();
  void startScreen();
  char newGameOrPlayer();
  void showMsg(const std::string &message);
  std::string createPlayer();
  game_sett createGame(PlayerController);

private:
  std::map<std::string, std::pair<sf::Sprite, sf::Texture>> sprites;
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
