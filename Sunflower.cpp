#include "Sunflower.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

Sunflower::Sunflower()
{
	scaleFactorX = 1.0f;
	scaleFactorY = 1.0f;
}

Sunflower::Sunflower(float scaleX, float scaleY) : Plant(scaleX, scaleY) {}



void Sunflower::loadTextures(const string& seedImagePath, const string& plantImagePath)
{
	Plant::loadTextures("Images/Cards/sunflower.png", "Images/Plants/Sunflower/SunFlower_0.png");
}

void Sunflower::handleEvents(RenderWindow& window, Event& event)
{
	Plant::handleEvents(window, event);
}

void Sunflower::update()
{
	Plant::update();
}

void Sunflower::draw(RenderWindow& window)
{
	Plant::draw(window);
}
