#include "Menu.h"
#include "Leaderboard.h" 
#include <SFML/Graphics.hpp>
#include <fstream>
using namespace sf;
using namespace std;

Menu::Menu(RenderWindow& window, Font& font, const Texture& backgroundTexture) : m_Window(window), m_Font(font), m_Selection(0), m_IsHighlightVisible(true), m_ShowLeaderboard(false)
{
    // Load background texture
    m_BackgroundSprite.setTexture(backgroundTexture);
    /* m_BackgroundTexture.loadFromFile("Images/titlescreen1.jpg");
     m_BackgroundSprite.setTexture(m_BackgroundTexture);*/

     // Setup menu items
    setupMenuItems();
}

int Menu::display()
{
    while (m_Window.isOpen()) {
        Event event;
        while (m_Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_Window.close();
                return -1;
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == Keyboard::Up) {
                    m_Selection = (m_Selection + 3) % 4;
                }
                else if (event.key.code == Keyboard::Down) {
                    m_Selection = (m_Selection + 1) % 4;
                }
                else if (event.key.code == Keyboard::Enter) {
                    return m_Selection;
                }

            }
        }

        updateHighlight();

        m_Window.clear();
        renderMenu();


        m_Window.display();
    }

    return -1;
}

void Menu::setupMenuItems()
{

    string menuTexts[] = { "Play", "Instructions", "Leaderboard", "Quit" };

    for (int i = 0; i < 4; ++i) {
        m_MenuItems[i].setFont(m_Font);
        m_MenuItems[i].setCharacterSize(51);
        m_MenuItems[i].setFillColor(Color::Black);
        m_MenuItems[i].setString(menuTexts[i]);
        m_MenuItems[i].setPosition(430, 520 + i * 120); // Adjust position as needed
    }
}

void Menu::updateHighlight()
{
    if (m_HighlightTimer.getElapsedTime().asSeconds() > 0.5) {
        m_IsHighlightVisible = !m_IsHighlightVisible;
        m_HighlightTimer.restart();
    }
}

void Menu::renderMenu()
{
    m_Window.draw(m_BackgroundSprite);

    for (int i = 0; i < 4; ++i) {
        m_MenuItems[i].setFillColor((m_Selection == i ? Color::White : Color::Black));
        m_Window.draw(m_MenuItems[i]);
    }

    //if (m_IsHighlightVisible && m_Selection >= 0 && m_Selection < 4) {
        //RectangleShape highlight(Vector2f(400, 50)); // Adjust size as needed
        //highlight.setFillColor(Color::White);
        //highlight.setPosition(32, 462 + m_Selection * 73); // Adjust position as needed
        //m_Window.draw(highlight);
    //}
}

