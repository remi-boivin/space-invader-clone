#include <MainMenu.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
  sf::RenderWindow window(sf::VideoMode(), "Space Invaders",
                          sf::Style::Fullscreen);
  sf::Texture tex_background;
  tex_background.loadFromFile("assets/background.jpg");
  sf::Sprite background(tex_background, sf::IntRect(0, 0, window.getSize().x,
                                                    window.getSize().y));
  sf::Texture tex_cursor;
  tex_cursor.loadFromFile("assets/cursor.png");

  // sf::Sprite cursor(tex_cursor, sf::IntRect(window.getSize().x / 2 * -1 +
  // 250,
  //                                           window.getSize().y / 2 * -1,
  //                                           window.getSize().x, 10));
  sf::Text text[4];
  sf::Font font;
  const char *tex_menu[4] = {"New Game", "Continue", "Settings", "Quit"};

  if (!font.loadFromFile("./assets/EvilEmpire-4BBVK.ttf")) {
    std::cerr << ".Error while loading font" << std::endl;
    return -1;
  }

  for (int i = 0; i < 4; i++) {
    text[i].setFont(font); // font est un sf::Font
    text[i].setString(tex_menu[i]);
    text[i].setCharacterSize(60); // exprimée en pixels, pas en points !
    text[i].setFillColor(sf::Color::White);
    text[i].setOrigin(static_cast<float>(text[i].getLocalBounds().width) / 2,
                      static_cast<float>(text[i].getLocalBounds().height) / 2);
    text[i].setPosition(static_cast<float>(window.getSize().x / 2),
                        static_cast<float>(window.getSize().y / 3 + i * 100));
  }

  MainMenu menu(window, background, text);
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::KeyPressed)
        switch (menu.set_select()) {
        case 0:
          std::cout << "New Game" << std::endl;
          break;
        case 1:
          std::cout << "Resume Game" << std::endl;
          break;
        case 2:
          std::cout << "Settings" << std::endl;
          break;
        case 3:
          std::cout << "Quit" << std::endl;
          break;
          default:
          break;
        }
    }
    menu.show();
  }
  return 0;
}