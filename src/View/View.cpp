#include "View.h"

using std::string;

const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

const float SPEED_RATIO = 100000;
const float ACCEL_RATIO = 10000000;

const float SPRITE_INITIAL_SPEED = 40;
const float SPRITE_INITIAL_ACCEL = 10;

const float SPRITE_MOVEMENT_LEWAY = 500;

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

    for (auto movement_it = movements.begin();
         movement_it != movements.end();) {

      // TODO Refactor
      if (movement_it->max_distance.x > 0) {
        distance.x = movement_it->speed.x * deltaTime.count();
        movement_it->max_distance.x -= std::abs(distance.x);
        movement_it->speed.x += movement_it->acceleration.x;
      } else {
        distance.x = 0;
      }

      if (movement_it->max_distance.y > 0) {
        distance.y = movement_it->speed.y * deltaTime.count();
        movement_it->max_distance.y -= std::abs(distance.y);
        movement_it->speed.y += movement_it->acceleration.y;
      } else {
        distance.y = 0;
      }

      sprites[movement_it->sprite].first.move(distance.x, distance.y);

      if (movement_it->max_distance.x <= 0 &&
          movement_it->max_distance.y <= 0) {
        movement_it = movements.erase(movement_it);
      } else {
        movement_it++;
      }
    }

    if (movements.empty()) {
      break;
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

  loadSprites("title", '1', "Title");
  loadSprites("play_button", '1', "PlayButton");
  loadSprites("background", '0', "Background");

  // Position sprites on the middle of the screen
  unsigned int middle = window->getSize().x / 2;

  sprites["1title"].first.setPosition(
      middle - sprites["1title"].first.getGlobalBounds().width / 2,
      window->getSize().y / 2 -
          sprites["1title"].first.getGlobalBounds().height / 2);
  // Position play_button bellow the title
  sprites["1play_button"].first.setPosition(
      middle - sprites["1play_button"].first.getGlobalBounds().width / 2,
      sprites["1title"].first.getPosition().y +
          sprites["1title"].first.getGlobalBounds().height +
          sprites["1play_button"].first.getGlobalBounds().height / 4);
}

// For each sprite int spriteNames, draw it on the window
void View::drawSprites(std::initializer_list<std::string> spriteNames) {
  for (const auto &sprite_name : spriteNames) {
    window->draw(sprites[sprite_name].first);
  }
}
void View::drawSprites() {
  for (const auto &sprite : sprites) {
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
          if (sprites["1play_button"].first.getGlobalBounds().contains(
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

  // Distance to leave screen
  float distance = (window->getSize().x / 2) + SPRITE_MOVEMENT_LEWAY;

  moveSprites({Movement("1play_button", {SPRITE_INITIAL_SPEED, 0},
                        {-SPRITE_INITIAL_ACCEL, 0}, {distance, 0}),
               Movement("1title", {-SPRITE_INITIAL_SPEED, 0},
                        {SPRITE_INITIAL_ACCEL, 0}, {distance, 0})});

  // Remove title and play_button sprites from screen
  sprites.erase("1title");
  sprites.erase("1play_button");
}

// show create players and start game options
void View::loadSprites(const string &name, const char &level) {
  loadSprites(name, level, name);
}

void View::loadSprites(std::string name, const char &level,
                       const std::string &file) {
  // Create sprites: create_players, start_game
  name = level + name;
  if (!sprites[name].second.loadFromFile("../Static/" + file + ".png")) {
    throw "Could not load" + file + ".png";
  }
  sprites[name].first.setTexture(sprites[name].second);
}

char View::newGameOrPlayer() {

  loadSprites("new_player", '1');
  loadSprites("new_game", '1');

  // Position sprites
  sprites["1new_game"].first.setPosition(
      window->getSize().x - sprites["1new_game"].first.getGlobalBounds().width,
      window->getSize().y);
  sprites["1new_player"].first.setPosition(
      window->getSize().x -
          sprites["1new_player"].first.getGlobalBounds().width,
      window->getSize().y);

  // Move sprites to position
  moveSprites({Movement("1new_game", {0, 0}, {0, -15}, {0, 500})});
  moveSprites({Movement("1new_player", {0, 0}, {0, -15}, {0, 350})});

  sf::Event event;

  // Render gameScreen
  while (window->isOpen()) {

    drawSprites();

    // Capture title clicked event
    while (window->pollEvent(event)) {
      switch (event.type) {

      case sf::Event::MouseButtonPressed:

        // If the left mouse button clicked play_button sprite Do something
        if (event.mouseButton.button == sf::Mouse::Left) {
          if (sprites["1start_game"].first.getGlobalBounds().contains(
                  event.mouseButton.x, event.mouseButton.y)) {
            return 'g';
            // return startGame();
          }
          if (sprites["create_players"].first.getGlobalBounds().contains(
                  event.mouseButton.x, event.mouseButton.y)) {
            return 'p';
            // return createPlayers();
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
  throw "window uclosed";
}

// DIsplay message on screen until user clicks it
void View::showMsg(const std::string &message) {
  std::cout << message << std::endl;
}
