#ifndef TEXTBOX_H
#define TEXTBOX_H

// Extracted from:
// https://stackoverflow.com/questions/53734084/write-text-input-on-the-screen-in-sfml#comment94322472_53734084

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <memory>

const std::string FONT_PATH =
    "../src/Static/SauceCodeProBoldNerdFontCompleteMono.ttf";
[[maybe_unused]] const unsigned int HEIGHT = 30;
[[maybe_unused]] const unsigned int WIDTH_MULTIPLIER = 18;
[[maybe_unused]] const unsigned int BACKSPACE = 8;

class TextField {
private:
  unsigned int m_size;
  sf::Text m_text;
  sf::RectangleShape m_rect;
  bool m_is_focused;

  sf::Font m_font;
  sf::Texture m_box_texture;

public:
  void draw(std::unique_ptr<sf::RenderWindow> &window) const;
  TextField(unsigned int maxChars, sf::Vector2f = {-10, -10});
  std::string getText() const;
  bool contains(sf::Vector2f point) const;
  void setFocus(bool focus);
  void handleInput(sf::Event event);
  void setPosition(sf::Vector2f pos);
};

#endif // !#ifndef TEXTBOX_H
