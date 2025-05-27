#include "Wallnut.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

Wallnut::Wallnut()
{
	scaleFactorX = 1.0f;
	scaleFactorY = 1.0f;
}

Wallnut::Wallnut(float scaleX, float scaleY) : Plant(scaleX, scaleY) {}



void Wallnut::loadTextures(const string& seedImagePath, const string& plantImagePath)
{
	Plant::loadTextures("Images/Cards/Wallnut.png", "Images/Plants/WallNut/WallNut_0.png");
}

void Wallnut::handleEvents(RenderWindow& window, Event& event)
{
	Plant::handleEvents(window, event);
}

void Wallnut::update()
{
	Plant::update();
}

void Wallnut::draw(RenderWindow& window)
{
	Plant::draw(window);
}
