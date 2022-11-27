#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

const std::string BUTTON_FONT_PATH =
    "../src/Static/SauceCodeProBoldNerdFontCompleteMono.ttf";
const std::string BUTTON_TEXTURE_PATH = "../src/Static/button.png";

class Button : public sf::Drawable {
private:
  sf::Text m_text;
  sf::Sprite m_sprite;

  sf::Font m_font;
  sf::Texture m_box_texture;

public:
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  Button(const std::string &text, const sf::Vector2f &pos = {-100, -100});
  bool contains(const sf::Vector2f &point) const;
  void setPosition(const sf::Vector2f &pos);
  void setPosition(const float &x, const float &y);
  sf::FloatRect getGlobalBounds() const;
};

#endif // !#ifndef BUTTON_H
