#include "Repeater.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

Repeater::Repeater()
{
	scaleFactorX = 1.0f;
	scaleFactorY = 1.0f;
}

Repeater::Repeater(float scaleX, float scaleY) : Plant(scaleX, scaleY) {}



void Repeater::loadTextures(const string& seedImagePath, const string& plantImagePath)
{
	Plant::loadTextures("Images/Cards/Repeater.png", "Images/Plants/Repeater/Repeater_0.png");
}

void Repeater::handleEvents(RenderWindow& window, Event& event)
{
	Plant::handleEvents(window, event);
}

void Repeater::update()
{
	Plant::update();
}

void Repeater::draw(RenderWindow& window)
{
	Plant::draw(window);
}
