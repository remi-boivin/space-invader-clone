#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>

class Menu {
public:
  Menu(sf::RenderWindow &, sf::Sprite &, sf::Text (&text)[4]);
  void show();
  int set_select();

protected:
  sf::RenderWindow &window;
  sf::Sprite &background;
  sf::Text (&text)[4];
  int pos = 0;
};