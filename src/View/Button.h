#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

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
  Button(std::string text, sf::Vector2f pos);
  bool contains(sf::Vector2f point) const;
  void setPosition(sf::Vector2f pos);
};

#endif // !#ifndef BUTTON_H
