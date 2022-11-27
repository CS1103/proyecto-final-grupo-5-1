#include "Button.h"
#include <SFML/Graphics/Rect.hpp>

/*
const std::string FONT_PATH =
    "../src/Static/SauceCodeProBoldNerdFontCompleteMono.ttf";
const std::string TEXTURE_PATH = "../src/Static/button.png";

class Button : public sf::Drawable {
private:
  sf::Text m_text;
  sf::Sprite m_sprite;

  sf::Font m_font;
  sf::Texture m_box_texture;

public:
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  Button(const std::string &text, const sf::Vector2f &pos);
  bool contains(const sf::Vector2f &point) const;
  void setPosition(const sf::Vector2f &pos);
};

*/

// Constructor
Button::Button(const std::string &text, const sf::Vector2f &pos) {
  // Load the font
  if (!m_font.loadFromFile(BUTTON_FONT_PATH)) {
    throw std::runtime_error("Error loading font");
  }

  // Load the texture
  if (!m_box_texture.loadFromFile(BUTTON_TEXTURE_PATH)) {
    throw std::runtime_error("Error loading texture");
  }

  // Set the text
  m_text.setFont(m_font);
  m_text.setString(text);
  m_text.setCharacterSize(30);
  m_text.setFillColor(sf::Color::White);
  m_text.setStyle(sf::Text::Bold);

  // Set the sprite
  m_sprite.setTexture(m_box_texture);
  m_sprite.setPosition(pos);
  m_sprite.setScale(0.5, 0.5);

  // Set the position of the text
  m_text.setPosition(pos.x + 10, pos.y + 10);
}

// Draw
void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(m_sprite);
  target.draw(m_text);
}

bool Button::contains(const sf::Vector2f &point) const {
  return m_sprite.getGlobalBounds().contains(point);
}

sf::FloatRect Button::getGlobalBounds() const {
  return m_sprite.getGlobalBounds();
}

void Button::setPosition(const sf::Vector2f &pos) {
  m_sprite.setPosition(pos);
  m_text.setPosition(pos.x + 10, pos.y + 10);
}
void Button::setPosition(const float &x, const float &y) {
  this->setPosition(sf::Vector2f(x, y));
}
