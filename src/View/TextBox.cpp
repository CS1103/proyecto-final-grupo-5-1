#include "TextBox.h"

TextField::TextField(unsigned int maxChars, sf::Vector2f initialPosition)
    : m_size(maxChars), m_rect(sf::Vector2f(m_size * WIDTH_MULTIPLIER, HEIGHT)),
      m_is_focused(false) {

  m_font.loadFromFile(FONT_PATH);
  m_text.setFont(m_font);
  m_rect.setFillColor(sf::Color::White);
  m_rect.setOutlineColor(sf::Color::Black);
  m_rect.setOutlineThickness(2);
  m_rect.setPosition(initialPosition);
  m_text.setPosition(initialPosition);
  m_text.setFillColor(sf::Color::Black);
}

void TextField::setPosition(sf::Vector2f pos) {
  m_rect.setPosition(pos);
  m_text.setPosition(pos + sf::Vector2f(2, -2));
}

std::string TextField::getText() const { return m_text.getString(); }

bool TextField::contains(sf::Vector2f point) const {
  return m_rect.getGlobalBounds().contains(point);
}

void TextField::draw(std::unique_ptr<sf::RenderWindow> &window) const {
  window->draw(m_rect);
  window->draw(m_text);
}

void TextField::setFocus(bool focus) {
  if (focus == m_is_focused) {
    return;
  }
  if (focus) {
    m_rect.setOutlineColor(sf::Color::Red);
  } else {
    m_rect.setOutlineColor(sf::Color::Black);
  }
  m_is_focused = focus;
}

void TextField::handleInput(sf::Event event) {
  if (!m_is_focused || event.type != sf::Event::TextEntered) {
    return;
  }
  if (event.text.unicode == BACKSPACE) { // Delete key
    m_text.setString(
        m_text.getString().substring(0, m_text.getString().getSize() - 1));
  } else if (m_text.getString().getSize() < m_size) {
    m_text.setString(m_text.getString() +
                     static_cast<char>(event.text.unicode));
  }
}
