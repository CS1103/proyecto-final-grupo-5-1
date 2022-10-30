#include "View.h"

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

const float SPEED_RATIO = 100000;
const float ACCEL_RATIO = 10000000;

Movement::Movement(std::string sprite, sf::Vector2f speed,
                   sf::Vector2f acceleration, sf::Vector2f distance)
    : sprite(std::move(sprite)), speed(speed / SPEED_RATIO),
      acceleration(acceleration / ACCEL_RATIO), max_distance(distance) {}

void View::moveSprites(std::vector<Movement> movements) {

  auto last = std::chrono::steady_clock::now();
  std::chrono::steady_clock::time_point now;

  sf::Vector2f distance(0, 0);

  while (window->isOpen()) { // Total distance

    now = std::chrono::steady_clock::now();
    deltaTime =
        std::chrono::duration_cast<std::chrono::microseconds>(now - last);
    last = now;

    for (auto &move : movements) {

      if (move.max_distance.x <= 0 && move.max_distance.y <= 0) {
        return;
      }

      if (move.max_distance.x > 0) {
        distance.x = move.speed.x * deltaTime.count();
        move.max_distance.x -= std::abs(distance.x);
        move.speed.x += move.acceleration.x;
      } else {
        distance.x = 0;
      }

      if (move.max_distance.y > 0) {
        distance.y = move.speed.y * deltaTime.count();
        move.max_distance.y -= std::abs(distance.y);
        move.speed.y += move.acceleration.y;
      } else {
        distance.y = 0;
      }

      sprites[move.sprite].first.move(distance.x, distance.y);
    }

    drawSprites();

    window->display();
  }
}

View::View() {

  // Initialize windows
  this->window = std::make_unique<sf::RenderWindow>(
      sf::VideoMode(WIDTH, HEIGHT), "Hex Game");
  // sf::VideoMode::getDesktopMode(), "Hex Game");

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
  unsigned int middle = window->getSize().x / 2 -
                        sprites["title"].first.getGlobalBounds().width / 2;

  sprites["title"].first.setPosition(
      middle, window->getSize().y / 2 -
                  sprites["title"].first.getGlobalBounds().height / 2);
  // Position play_button bellow the title
  sprites["play_button"].first.setPosition(
      middle, sprites["title"].first.getPosition().y +
                  sprites["title"].first.getGlobalBounds().height +
                  sprites["play_button"].first.getGlobalBounds().height / 4);
}

// For each sprite, draw it on the window
void View::drawSprites() {
  for (auto &sprite : sprites) {
    window->draw(sprite.second.first);
  }
}

void View::startScreen() {

  sf::Event event;
  bool has_game_started = false;

  // Render startScreen
  while (window->isOpen() && !has_game_started) {

    drawSprites();

    // Capture title clicked event
    while (window->pollEvent(event)) {
      switch (event.type) {

      case sf::Event::MouseButtonPressed:

        // If the left mouse button clicked play_button sprite Do something
        if (event.mouseButton.button == sf::Mouse::Left) {
          if (sprites["play_button"].first.getGlobalBounds().contains(
                  event.mouseButton.x, event.mouseButton.y)) {
            has_game_started = true;
          }
        }
        break;

      case sf::Event::Closed:
        window->close();
        break;

      default:
        break;
      }
    }
    window->display();
  }

  moveSprites({Movement("play_button", {40, 0}, {-10, 0}, {1000, 0}),
               Movement("title", {40, 0}, {-10, 0}, {1000, 0})});
}
