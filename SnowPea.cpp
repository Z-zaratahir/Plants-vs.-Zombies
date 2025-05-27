#include "SnowPea.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

SnowPea::SnowPea()
{
	scaleFactorX = 1.0f;
	scaleFactorY = 1.0f;
}

SnowPea::SnowPea(float scaleX, float scaleY) : Plant(scaleX, scaleY) {}



void SnowPea::loadTextures(const string& seedImagePath, const string& plantImagePath)
{
	Plant::loadTextures("Images/Cards/snowpea.png", "Images/Plants/SnowPea/SnowPea_0.png");
}

void SnowPea::handleEvents(RenderWindow& window, Event& event)
{
	Plant::handleEvents(window, event);
}

void SnowPea::update()
{
	Plant::update();
}

void SnowPea::draw(RenderWindow& window)
{
	Plant::draw(window);
}



