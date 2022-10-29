#include "View.h"
#include <iostream>

const unsigned int RIGHT_DISPLACEMENT = 600;

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

View::View() {

  // Initialize windows
  this->window = std::make_unique<sf::RenderWindow>(
      sf::VideoMode(WIDTH, HEIGHT), "Hex Game");

  // Initialize textures
  if (!sprites["background"].second.loadFromFile("../Static/Background.png")) {
    throw "Could not load background.png";
  }

  if (!sprites["title"].second.loadFromFile("../Static/Title.png")) {
    throw "Could not load Title.png";
  }

  if (!sprites["play_button"].second.loadFromFile("../Static/PlayButton.png")) {
    throw "Could not load PlayButton.png";
  }

  // Initialize sprites
  sprites["background"].first.setTexture(sprites["background"].second);
  sprites["title"].first.setTexture(sprites["title"].second);
  sprites["play_button"].first.setTexture(sprites["play_button"].second);

  // Position sprites on the middle of the screen
  sprites["title"].first.setPosition(
      WIDTH / 2 - sprites["title"].first.getGlobalBounds().width / 2,
      HEIGHT / 2 - sprites["title"].first.getGlobalBounds().height / 2);

  // Position play_button bellow the title
  sprites["play_button"].first.setPosition(
      WIDTH / 2 - sprites["play_button"].first.getGlobalBounds().width / 2,

      sprites["title"].first.getPosition().y +
          sprites["title"].first.getGlobalBounds().height +
          sprites["play_button"].first.getGlobalBounds().height / 4);
}

// Smooth animation for sprite: x change, y change, duration
void ComputeSpeed(sf::Sprite &sprite, const int &xChange, const int &yChange,
                  const seconds &duration) {
  unsigned int distance = sqrt(pow(xChange, 1) + pow(yChange, 2));
}

void View::startScreen() {

  sf::Event event;
  bool has_game_started = false;

  while (window->isOpen() && !has_game_started) {

    // Display Initial screen
    window->draw(sprites["background"].first);
    window->draw(sprites["title"].first);
    window->draw(sprites["play_button"].first);

    // Capture title clicked event
    while (window->pollEvent(event)) {
      switch (event.type) {

      case sf::Event::MouseButtonPressed:

        // If the left mouse button clicked play_button sprite Do something
        if (event.mouseButton.button == sf::Mouse::Left) {
          if (sprites["play_button"].first.getGlobalBounds().contains(
                  event.mouseButton.x, event.mouseButton.y)) {
            std::cout << "start\n";
            has_game_started = true;
          }
        }
        break;

      case sf::Event::Closed:
        window->close();
        break;

      default:
        continue;
      }
    }
    window->display();
  }

  auto last = std::chrono::steady_clock::now();

  float small_move_right_speed = 0.06;
  float total_move = 0;

  while (window->isOpen() && total_move <= 3500) {

    auto now = std::chrono::steady_clock::now();

    auto delta_time =
        std::chrono::duration_cast<std::chrono::milliseconds>(now - last);

    last = now;

    std::cout << "dt:\t" << delta_time.count() << std::endl;

    // Move title sprite SMALL_MOVE_RIGHT_DISTANCE
    float move_r = small_move_right_speed * delta_time.count();
    total_move += std::abs(move_r);

    small_move_right_speed +=
        (total_move < RIGHT_DISPLACEMENT / 2) ? 0.005 : -0.02;

    sprites["play_button"].first.move(move_r, 0);
    sprites["title"].first.move(move_r, 0);

    window->draw(sprites["background"].first);
    window->draw(sprites["title"].first);
    window->draw(sprites["play_button"].first);

    window->display();
  }
}
