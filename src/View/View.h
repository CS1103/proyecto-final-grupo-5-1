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

#include "../utils.h"

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

private:
  std::map<std::string, std::pair<sf::Sprite, sf::Texture>> sprites;
  std::unique_ptr<sf::RenderWindow> window;
  std::chrono::microseconds deltaTime;

  // Move mutiple sprites as tuples
  void moveSprites(std::vector<Movement> movements);
  void drawSprites(std::initializer_list<std::string> spriteNames);
  void drawSprites();
  void gameScreen();
};

#endif // !VIEW_H
