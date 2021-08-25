#include <menu.hpp>
#include <SFML/Graphics.hpp>

class MainMenu : public Menu {
    public:
        MainMenu(sf::RenderWindow& window, sf::Sprite &background, sf::Text (&text)[4]);
        void show();
        int set_select();
};