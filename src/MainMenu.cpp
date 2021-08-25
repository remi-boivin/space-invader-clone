#include <MainMenu.hpp>
#include <SFML/Graphics/Sprite.hpp>

MainMenu::MainMenu(sf::RenderWindow& m_windows, sf::Sprite &m_background, sf::Text (&m_text)[4]) : Menu(m_windows, m_background, m_text) {}

void MainMenu::show() {
    Menu::show();
}

int MainMenu::set_select() {
    
    return (Menu::set_select());
}