#include "View.h"

View::View() {
  // Initialize windows
  this->window = std::make_unique<sf::RenderWindow>(

      sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Hex Game");
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

char View::newGameOrPlayer() {

  loadSprites("new_player", '1');
  loadSprites("new_game", '1');

  window->clear();

  // Position sprites
  sprites["1new_game"].first.setPosition(
      window->getSize().x - sprites["1new_game"].first.getGlobalBounds().width,
      window->getSize().y);
  sprites["1new_player"].first.setPosition(
      window->getSize().x -
          sprites["1new_player"].first.getGlobalBounds().width,
      window->getSize().y);

  // Move sprites to position
  moveSprites({Movement("1new_game", {0, 0}, {0, -15}, {0, 500}),
               Movement("1new_player", {0, 0}, {0, -15}, {0, 350})});

  sf::Event event;

  // Render gameScreen
  while (window->isOpen()) {

    drawSprites();

    // Capture title clicked event
    while (window->pollEvent(event)) {
      switch (event.type) {

      case sf::Event::MouseButtonPressed:

        if (event.mouseButton.button == sf::Mouse::Left) {

          if (sprites["1new_game"].first.getGlobalBounds().contains(
                  event.mouseButton.x, event.mouseButton.y)) {
            return 'g';
          }
          if (sprites["1new_player"].first.getGlobalBounds().contains(
                  event.mouseButton.x, event.mouseButton.y)) {
            return 'p';
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

std::string View::createPlayer() {

  std::cout << "here\n";
  sprites.erase("1new_game");
  sprites.erase("1new_player");

  window->clear();
  TextField tfs(20);
  tfs.setPosition({350, 100});

  loadSprites("create_player", '1');

  sprites["1create_player"].first.setPosition({-100, 300});
  moveSprites({Movement("1create_player", {10, 0}, {8, 0}, {400, 0})});

  sf::Event event;
  while (window->isOpen()) {

    while (window->pollEvent(event)) {

      switch (event.type) {
      case sf::Event::Closed:
        window->close();
        break;
      case sf::Event::MouseButtonPressed:
        std::cout << "mouse released\n";
        if (event.mouseButton.button != sf::Mouse::Left) {
          break;
        }
        if (sprites["1create_player"].first.getGlobalBounds().contains(
                event.mouseButton.x, event.mouseButton.y)) {
          return tfs.getText();
        }

        tfs.setFocus(tfs.contains(
            sf::Vector2f(event.mouseButton.x, event.mouseButton.y)));
        break;
      default:
        tfs.handleInput(event);
        break;
      }
    }
    drawSprites();
    tfs.draw(window);
    window->display();
  }
}

game_sett View::createGame(const PlayerController &players) {
  // return tuple
  return game_sett("p1", "p2", TipoJ::HUMANO_HUMANO, 120, 9);
}

// DIsplay message on screen until user clicks it
void View::showMsg(const std::string &message) {
  std::cout << message << std::endl;
}

void View::moveSprites(std::vector<Movement> movements) {
  // Excesive cognity complexity.. crap

  auto last = std::chrono::steady_clock::now();
  std::chrono::steady_clock::time_point now;
  Vector2f distance(0, 0);

  while (window->isOpen()) { // Total distance

    now = std::chrono::steady_clock::now();
    deltaTime =
        std::chrono::duration_cast<std::chrono::microseconds>(now - last);
    last = now;

    for (auto movement_it = movements.begin();
         movement_it != movements.end();) {

      // iterate x and y
      for (int i = 0; i < 2; i++) {
        if (movement_it->max_distance[i] > 0) {
          distance[i] = movement_it->speed[i] * deltaTime.count();
          movement_it->max_distance[i] -= std::abs(distance[i]);
          movement_it->speed[i] += movement_it->acceleration[i];
        } else {
          distance[i] = 0;
        }
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

// show create players and start game options
void View::loadSprites(const std::string &name, const char &level) {
  loadSprites(name, level, name);
}

void View::loadSprites(std::string name, const char &level,
                       const std::string &file) {
  // Create sprites: create_players, start_game
  name = level + name;
  if (!sprites[name].second.loadFromFile("../src/Static/" + file + ".png")) {
    throw "Could not load" + file + ".png";
  }
  sprites[name].first.setTexture(sprites[name].second);
}
