#include "Sunlight.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

//if (!theTexture.loadFromFile("Images/sun.png"))// loading file
//{
//    return;//return if loading fails
//}
//theSprite.setTexture(theTexture);
////setting position
//float SetPositionX = 878.0f;//old x: 150.0
//float SetPositionY = 75.0f;//old y: 19.0
//
//theSprite.setPosition(SetPositionX, SetPositionY);
//window.draw(theSprite);//drawing the sprite
Sunlight::Sunlight() : sunVisible(false) {
    sunTexture.loadFromFile("Images/sun.png");
    sunSprite.setTexture(sunTexture);
    sunSprite.setOrigin(sunSprite.getGlobalBounds().width / 2, sunSprite.getGlobalBounds().height / 2);
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Sunlight::createSun(RenderWindow& window)
{
    if (!sunVisible && clock.getElapsedTime().asSeconds() > 5) {
        float randX = static_cast<float>(rand() % window.getSize().x);
        sunSprite.setPosition(randX, -sunSprite.getGlobalBounds().height / 2);
        sunVisible = true;
        clock.restart();
    }

    if (sunVisible) {
        sunSprite.move(0, 2);
        window.draw(sunSprite);

        if (sunSprite.getPosition().y > window.getSize().y + sunSprite.getGlobalBounds().height / 2) {
            sunVisible = false;
        }
    }
}

