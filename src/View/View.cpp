#include "View.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <stdexcept>
#include <utility>

#define GET_VARIABLE_NAME(Variable) (#Variable)

using sf::Drawable;
using std::initializer_list;
using std::reference_wrapper;
using std::string;

const std::string TEXTURE_PATH = "../src/assets/textures";

View::View() {
  // Initialize windows
  this->window = std::make_unique<sf::RenderWindow>(

      sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Hex Game");
  // sf::VideoMode::getDesktopMode(), "Hex Game");
}

void LoadTexture(sf::Texture &texture, const std::string &textureName) {
  if (!texture.loadFromFile(TEXTURE_PATH + "/" + textureName)) {
    throw std::runtime_error("Could not load texture: " + textureName);
  }
}

void View::startScreen() {

  sf::Texture background;
  LoadTexture(background, "background.png");
  sf::Sprite background_sprite;
  background_sprite.setTexture(background);

  sf::Texture title;
  LoadTexture(title, "title.png");
  sf::Sprite title_sprite;
  title_sprite.setTexture(title);

  Button play_button = Button("PLAY");

  // Position sprites on the middle of the screen
  unsigned int middle = window->getSize().x / 2;

  title_sprite.setPosition(middle - title_sprite.getGlobalBounds().width / 2,
                           window->getSize().y / 2 -
                               title_sprite.getGlobalBounds().height / 2);
  // Position play_button bellow the title
  play_button.setPosition(middle - play_button.getGlobalBounds().width / 2,
                          title_sprite.getPosition().y +
                              title_sprite.getGlobalBounds().height +
                              play_button.getGlobalBounds().height / 4);

  sf::Event event;
  bool has_game_started = false;

  // Render startScreen
  while (window->isOpen() && !has_game_started) {

    drawOnWindow({background_sprite, title_sprite, play_button});

    // Capture title clicked event
    while (window->pollEvent(event)) {
      switch (event.type) {

      case sf::Event::MouseButtonPressed:

        // If the left mouse button clicked play_button sprite Do something
        if (event.mouseButton.button == sf::Mouse::Left &&
            play_button.getGlobalBounds().contains(event.mouseButton.x,
                                                   event.mouseButton.y)) {
          has_game_started = true;
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

  moveObjects({Movement<Button>(play_button, {SPRITE_INITIAL_SPEED, 0},
                                {-SPRITE_INITIAL_ACCEL, 0}, {distance, 0}),
               Movement(title_sprite, {-SPRITE_INITIAL_SPEED, 0},
                        {SPRITE_INITIAL_ACCEL, 0}, {distance, 0})});

  // Remove title and play_button sprites from screen
}

char View::newGameOrPlayer() {

  // unload create_player sprite if exists in sprites

  loadSprites("new_player", '1');
  loadSprites("new_game", '1');

  sf::Texture new_player;
  LoadTexture(new_player, "new_player.png");
  sf::Sprite new_player_sprite;
  new_player_sprite.setTexture(new_player);

  sf::Texture new_game;
  LoadTexture(new_game, "new_game.png");
  sf::Sprite new_game_sprite;
  new_game_sprite.setTexture(new_game);

  // Position sprites
  new_game_sprite.setPosition(window->getSize().x -
                                  new_game_sprite.getGlobalBounds().width,
                              window->getSize().y);
  new_player_sprite.setPosition(window->getSize().x -
                                    new_player_sprite.getGlobalBounds().width,
                                window->getSize().y);

  const float LEAVE_SCREEN_SPEED = -15;
  const float NEW_GAME_LEAVE_D = 500;
  const float NEW_PLAYER_LEAVE_D = 350;

  // Move sprites to position
  moveObjects({Movement(new_game, {0, 0}, {0, LEAVE_SCREEN_SPEED},
                        {0, NEW_GAME_LEAVE_D}),
               Movement(new_player_sprite, {0, 0}, {0, LEAVE_SCREEN_SPEED},
                        {0, NEW_PLAYER_LEAVE_D})});

  sf::Event event;

  // Render gameScreen
  while (window->isOpen()) {

    drawOnWindow({new_game_sprite, new_player_sprite});

    // Capture title clicked event
    while (window->pollEvent(event)) {
      switch (event.type) {

      case sf::Event::MouseButtonPressed:

        if (event.mouseButton.button == sf::Mouse::Left) {

          if (new_game_sprite.getGlobalBounds().contains(event.mouseButton.x,
                                                         event.mouseButton.y)) {
            return 'g';
          }
          if (new_player_sprite.getGlobalBounds().contains(
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

  window->clear();

  TextField tfs(20);
  tfs.setPosition({350, 100});

  Button create_player_button = Button("CREATE PLAYER");
  create_player_button.setPosition(-100, 300);

  moveSprites({Movement("1create_player", {10, 0}, {8, 0}, {400, 0})});

  sf::Event event;
  while (window->isOpen()) {

    while (window->pollEvent(event)) {

      switch (event.type) {
      case sf::Event::Closed:
        window->close();
        break;
      case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button != sf::Mouse::Left) {
          break;
        }
        if (create_player_button.getGlobalBounds().contains(
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
    drawOnWindow({tfs, create_player_button});
    window->display();
  }
  throw std::invalid_argument("no name provided");
}

game_sett View::createGame(const std::vector<std::string> &names) {
  // print names
  for (const auto &name : names) {
    std::cout << name << std::endl;
  }
  return {};
}

// DIsplay message on screen until user clicks it
void View::showMsg(const std::string &message) {
  std::cout << message << std::endl;
}

void View::moveObjects(std::vector<movement> &movements) {
  // Excesive cognity complexity.. crap

  auto last = std::chrono::steady_clock::now();
  std::chrono::steady_clock::time_point now;
  Vector2f distance(0, 0);

  while (window->isOpen()) { // Total distance

    now = std::chrono::steady_clock::now();
    deltaTime =
        std::chrono::duration_cast<std::chrono::microseconds>(now - last);
    last = now;

    for (auto &move : movements) {

      auto movement = boost::apply_visitor(MovementVisitor(), move);

      for (unsigned int i = 0; i < 2; i++) {
      }

      // iterate x and y
      for (int i = 0; i < 2; i++) {
        if (movement.max_distance[i] > 0) {
          distance[i] = movement.speed[i] * deltaTime.count();
          movement.max_distance[i] -= std::abs(distance[i]);
          movement.speed[i] += movement.acceleration[i];
        } else {
          distance[i] = 0;
        }
      }

      if (movement.max_distance.x <= 0 && movement.max_distance.y <= 0) {
        movement = movements.erase(movement_it);
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

  // For each sprite int spriteNames, draw it on the window
  void View::drawOnWindow(
      initializer_list<reference_wrapper<Drawable>> drawables) {
    for (const auto &drawable : drawables) {
      window->draw(drawable);
    }
  }
