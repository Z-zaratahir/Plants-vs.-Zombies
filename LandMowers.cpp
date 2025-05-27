#include "LandMowers.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


void LandMowers::createLawnmower1(RenderWindow& window,float delT)
{
	if (!LawnMowerTexture.loadFromFile("Images/lawnmowerIdle.png"))// loading file
	{
		return;//return if loading fails

	}
	lawnMower.setTexture(LawnMowerTexture);
	//setting position
	float SetPositionX = 177.0f;
	float SetPositionY = 182.0f;

	lawnMower.setPosition(SetPositionX, SetPositionY);

	//setting x and y axes
	float scaleFactorX = 1.5f;
	float scaleFactorY = 1.5f;

	lawnMower.setScale(Vector2f(scaleFactorX, scaleFactorY));

	float speed = 100.0f; // Adjust the speed as needed (pixels per second)
	float movement = speed * delT;
	lawnMower.move(movement, 0.0f);



	window.draw(lawnMower);//drawing the sprite

}

void LandMowers::createLawnmower2(RenderWindow& window)
{
	if (!LawnMowerTexture.loadFromFile("Images/lawnmowerIdle.png"))// loading file
	{
		return;//return if loading fails

	}
	lawnMower.setTexture(LawnMowerTexture);
	//setting position
	float SetPositionX = 185.0f;
	float SetPositionY = 353.0f;

	lawnMower.setPosition(SetPositionX, SetPositionY);

	//setting x and y axes
	float scaleFactorX = 1.5f;
	float scaleFactorY = 1.5f;

	lawnMower.setScale(Vector2f(scaleFactorX, scaleFactorY));

	window.draw(lawnMower);//drawing the sprite

}




void LandMowers::createLawnmower3(RenderWindow& window)
{
	if (!LawnMowerTexture.loadFromFile("Images/lawnmowerIdle.png"))// loading file
	{
		return;//return if loading fails

	}
	lawnMower.setTexture(LawnMowerTexture);
	//setting position
	float SetPositionX = 184.0f;
	float SetPositionY = 530.0f;//530

	lawnMower.setPosition(SetPositionX, SetPositionY);

	//setting x and y axes
	float scaleFactorX = 1.5f;
	float scaleFactorY = 1.5f;

	lawnMower.setScale(Vector2f(scaleFactorX, scaleFactorY));

	window.draw(lawnMower);//drawing the sprite
}

void LandMowers::createLawnmower4(RenderWindow& window)
{
	if (!LawnMowerTexture.loadFromFile("Images/lawnmowerIdle.png"))// loading file
	{
		return;//return if loading fails

	}
	lawnMower.setTexture(LawnMowerTexture);
	//setting position
	float SetPositionX = 177.0f;
	float SetPositionY = 710.0f;

	lawnMower.setPosition(SetPositionX, SetPositionY);

	//setting x and y axes
	float scaleFactorX = 1.5f;
	float scaleFactorY = 1.5f;

	lawnMower.setScale(Vector2f(scaleFactorX, scaleFactorY));

	window.draw(lawnMower);//drawing the sprite
}

void LandMowers::createLawnmower5(RenderWindow& window)
{
	if (!LawnMowerTexture.loadFromFile("Images/lawnmowerIdle.png"))// loading file
	{
		return;//return if loading fails
	}

	lawnMower.setTexture(LawnMowerTexture);
	//setting position
	float SetPositionX = 167.0f;
	float SetPositionY = 880.0f;

	lawnMower.setPosition(SetPositionX, SetPositionY);

	//setting x and y axes
	float scaleFactorX = 1.5f;
	float scaleFactorY = 1.5f;

	lawnMower.setScale(Vector2f(scaleFactorX, scaleFactorY));

	window.draw(lawnMower);//drawing the sprite
}