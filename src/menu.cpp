#include <SFML/Window/Keyboard.hpp>
#include <menu.hpp>

Menu::Menu(sf::RenderWindow &m_windows, sf::Sprite &m_background,
           sf::Text (&m_text)[4])
    : window(m_windows), background(m_background), text(m_text) {}

void Menu::show() {
  window.clear();
  window.draw(background);
  for (int i = 0; i < 4; i++) {
    window.draw(text[i]);
  }
  window.display();
}

int Menu::set_select() {
  if (pos < 0 || pos > 4)
    pos = 0;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    pos += 1;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    pos -= 1;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
    return (pos);
  }
  return (42);
}