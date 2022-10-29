#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <cmath>
#include <memory>
#include <unordered_map>

#include "../utils.h"

// Store sprite, speed, acceleration and distance
struct Movement {
  std::string sprite;
  sf::Vector2f speed;
  sf::Vector2f acceleration;
  sf::Vector2f max_distance;
  Movement(std::string sprite, const sf::Vector2f &speed,
           const sf::Vector2f &acceleration, const sf::Vector2f &distance);
};

class View {
public:
  View();
  void startScreen();

private:
  std::unordered_map<std::string, std::pair<sf::Sprite, sf::Texture>> sprites;
  std::unique_ptr<sf::RenderWindow> window;
  std::chrono::milliseconds deltaTime;

  // Move mutiple sprites as tuples
  void moveSprites(std::vector<Movement> &movements);

  void drawSprites();
};

#endif // !VIEW_H
