#include "Peashooter.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

Peashooter::Peashooter()
{
	scaleFactorX = 1.0f;
	scaleFactorY = 1.0f;

}

Peashooter::Peashooter(float scaleX, float scaleY) : Plant(scaleX, scaleY) {}



void Peashooter::loadTextures(const string& seedImagePath, const string& plantImagePath)
{
	Plant::loadTextures("Images/Cards/PeaShooter.png", "Images/Plants/Peashooter/Peashooter_0.png");
}

void Peashooter::handleEvents(RenderWindow& window, Event& event)
{
	Plant::handleEvents(window, event);
}

void Peashooter::update()
{
	Plant::update();
}

void Peashooter::draw(RenderWindow& window)
{
	Plant::draw(window);
}

