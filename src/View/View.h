#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <cmath>
#include <memory>
#include <unordered_map>

#include "../utils.h"

class View {
public:
  View();
  void startScreen();

private:
  std::unordered_map<std::string, std::pair<sf::Sprite, sf::Texture>> sprites;
  std::unique_ptr<sf::RenderWindow> window;
  std::chrono::milliseconds deltaTime;
};

#endif // !VIEW_H
