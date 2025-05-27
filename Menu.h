#pragma once
#include <SFML/Graphics.hpp>
#include "GameBackground.h"
using namespace sf;
using namespace std;


class Menu
{
protected:
    RenderWindow& m_Window;
    Font m_Font;
    Texture m_BackgroundTexture;
    Sprite m_BackgroundSprite;
    Text m_MenuItems[4]; // Assuming 4 menu items
    int m_Selection;
    bool m_ShowLeaderboard;
    Clock m_HighlightTimer;
    bool m_IsHighlightVisible;

public:
    Menu(RenderWindow& window, Font& font, const Texture& backgroundTexture);
    int display();
    void setupMenuItems();
    void updateHighlight();
    void renderMenu();
};

