#include "CherryBomb.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

CherryBomb::CherryBomb()
{
	scaleFactorX = 1.0f;
	scaleFactorY = 1.0f;
}

CherryBomb::CherryBomb(float scaleX, float scaleY) : Plant(scaleX, scaleY) {}



void CherryBomb::loadTextures(const string& seedImagePath, const string& plantImagePath)
{
	Plant::loadTextures("Images/Cards/cherrybomb.png", "Images/Plants/CherryBomb/CherryBomb_0.png");
}

void CherryBomb::handleEvents(RenderWindow& window, Event& event)
{
	Plant::handleEvents(window, event);
}

void CherryBomb::update()
{
	Plant::update();
}

void CherryBomb::draw(RenderWindow& window)
{
	Plant::draw(window);
}
