#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameBackground.h"
#include "Coordinate.h"
#include "LandMowers.h"
using namespace sf;
using namespace std;


class GameBackground
{

	Texture  WoodTexture;
	Sprite Wood;
	Texture PeaShooterTexture;
	Sprite PeaShooter;
	Texture SunfowerTexture;
	Sprite Sunflower;
    LandMowers Mower;
	Texture WallnutTexture;
	Sprite Wallnut;
	Texture theTexture;
	Sprite theSprite;




public:
	GameBackground();

	GameBackground(const Texture& woodTexture, const Sprite& LongWood, 
		const Texture& myPeaShooterTexture, const Sprite& myPeaShooter, 
		const Texture& mySunflowerTex,const Sprite& mySunflower,
		LandMowers myMower, 
		const Texture& myWallnutTexture, const Sprite& myWallnut, const Texture& myTexture, const Sprite& mySprite);

	


	void createBackGround(RenderWindow& window, const string& imagePath);
	void createWoodenBar(RenderWindow& window);
	void createMenuButton(RenderWindow& window);
	void createPeaShooterSeed(RenderWindow& window);
	void createSunflowerSeed(RenderWindow& window);
	void createLandMowers(RenderWindow& window,float delT);
	void createLockedWallnut(RenderWindow& window);
	void createWallnutSeed(RenderWindow& window);
	void createLockedCherryBomb(RenderWindow& window);
	void createCherryBomb(RenderWindow& window);
	void createLockedRepeater(RenderWindow& window);
	void createRepeater(RenderWindow& window);
	void createScoreButton(RenderWindow& window);
void createCard(RenderWindow& window, float iteration, const string& path, const Coordinate& position) {
	Image cardImage;
	cardImage.loadFromFile(path);
	Texture texture;
	texture.loadFromImage(cardImage);
	Sprite cardSprite;
	cardSprite.setTexture(texture);
	float posx = iteration * 130;
	//setting position
	float SetPositionX = 20 + posx;//old x: 150.0
	float SetPositionY = 25.0f;//old y: 19.0

	cardSprite.setPosition(SetPositionX, SetPositionY);

	//setting x and y axes
	float scaleFactorX = 0.7f;
	float scaleFactorY = 0.6f;

	cardSprite.setScale(Vector2f(scaleFactorX, scaleFactorY));

	window.draw(cardSprite);
}

void drawShapeOverGrid(RenderWindow& window);
	};




