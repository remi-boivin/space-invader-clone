#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(), "Space Invaders", sf::Style::Fullscreen);
    sf::Texture tex_background;
    sf::Texture tex_menu;
    tex_background.loadFromFile("assets/background.jpg");
    tex_menu.loadFromFile("assets/menu.png");
    sf::Sprite background(tex_background,sf::IntRect(0, 0, window.getSize().x, window.getSize().y));
    sf::Sprite menu(tex_menu,sf::IntRect(window.getSize().x / 2 * - 1 + 250, window.getSize().y / 2 * - 1 + 250, window.getSize().x, window.getSize().y));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(background);
        window.draw(menu);
        window.display();
    }
    return 0;
}