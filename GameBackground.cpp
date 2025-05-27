#include "GameBackground.h"
#include "LandMowers.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

GameBackground::GameBackground() 
{
	
}

GameBackground::GameBackground(const Texture& woodTexture, const Sprite& LongWood,
	const Texture& myPeaShooterTexture, const Sprite& myPeaShooter,
	const Texture& mySunflowerTex, const Sprite& mySunflower, LandMowers myMower,
	const Texture& myWallnutTexture, const Sprite& myWallnut, const Texture& myTexture, const Sprite& mySprite)
	:Mower(myMower)
{
	WoodTexture = woodTexture;
	Wood = LongWood;
	PeaShooterTexture = myPeaShooterTexture;
	PeaShooter = myPeaShooter;
	SunfowerTexture = mySunflowerTex;
	Sunflower = mySunflower;
	WallnutTexture = myWallnutTexture;
	Wallnut = myWallnut;
	theTexture = myTexture;
	theSprite = mySprite;

}




void GameBackground::createBackGround(RenderWindow& window, const string& imagePath)
{
	//Drawing a map
	Image map_image;
	//map_image.loadFromFile("Images/maingamebackground_cleanup.jpeg"); // load the file for the map
	map_image.loadFromFile(imagePath);

	//map_image.loadFromFile("Images/Frontyard.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	
	Vector2u windowSize = window.getSize();

	float scaleX = static_cast<float>(windowSize.x) / map_image.getSize().x;// x-axis - width
	float scaleY = static_cast<float>(windowSize.y) / map_image.getSize().y;// y-axis - height
	
	float scaleFactor = max(scaleX, scaleY);


	s_map.setScale(scaleFactor, scaleFactor);
	float posX = (windowSize.x - map_image.getSize().x * scaleFactor) / 4.0f;
	float posY = (windowSize.y - map_image.getSize().y * scaleFactor) / 6.0f;//old y : 2.75 

	s_map.setPosition(posX, posY);
	
	window.draw(s_map);
}

void GameBackground::createWoodenBar(RenderWindow& window)
{

	if (!WoodTexture.loadFromFile("Images/wooden-board.png"))// loading file
	{
		return;//return if loading fails
	}

	Wood.setTexture(WoodTexture);
	//setting x and y axes
	//float scaleFactorX = 0.15f;//old x: 0.15f,y : 0.14f
	//float scaleFactorY = 0.13f;

	//setting x and y axes
	float scaleFactorX = 0.112f;//old x: 0.15f,y : 0.14f
	float scaleFactorY = 0.13f;

	Wood.setScale(Vector2f(scaleFactorX, scaleFactorY)); 

	window.draw(Wood);//drawing the sprite	
}

void GameBackground::createMenuButton(RenderWindow& window)
{
	Image pauseButtonRender;
	pauseButtonRender.loadFromFile("Images/MENU-r.png");
	Texture texture;
	texture.loadFromImage(pauseButtonRender);
	Sprite buttonPause;
	buttonPause.setTexture(texture);
	buttonPause.setPosition(1650, 50);
	window.draw(buttonPause);
}

//void GameBackground::createPeaShooterSeed(RenderWindow& window)
//{
//	//if (!PeaShooterTexture.loadFromFile("Images/peashooterseed.png"))// loading file
//	if (!PeaShooterTexture.loadFromFile("Images/PEASHOOTERSEEDS.png"))// loading file
//	{
//		return;//return if loading fails
//	}
//
//	PeaShooter.setTexture(PeaShooterTexture);
//	//setting position
//	float SetPositionX = 9.0f;// old x: 9.0
//	float SetPositionY = 23.25f;//old y; 18.0
//
//	PeaShooter.setPosition(SetPositionX, SetPositionY);
//
//	//setting x and y axes
//	float scaleFactorX = 1.75f;
//	float scaleFactorY = 1.6f;
//
//	PeaShooter.setScale(Vector2f(scaleFactorX, scaleFactorY));
//
//	window.draw(PeaShooter);//drawing the sprite
//}


void GameBackground::createPeaShooterSeed(RenderWindow& window)
{
	//if (!PeaShooterTexture.loadFromFile("Images/peashooterseed.png"))// loading file
	if (!PeaShooterTexture.loadFromFile("Images/Cards/PeaShooter.png"))// loading file
	{
		return;//return if loading fails
	}

	PeaShooter.setTexture(PeaShooterTexture);
	//setting position
	float SetPositionX = 20.0f;// old x: 9.0
	float SetPositionY = 25.0f;//old y; 18.0

	PeaShooter.setPosition(SetPositionX, SetPositionY);

	//setting x and y axes
	float scaleFactorX = 0.7f;
	float scaleFactorY = 0.6f;

	PeaShooter.setScale(Vector2f(scaleFactorX, scaleFactorY));

	window.draw(PeaShooter);//drawing the sprite
}

void GameBackground::createScoreButton(RenderWindow& window)
{
	Image pauseButtonRender;
	pauseButtonRender.loadFromFile("Images/SunBack.png");
	Texture texture;
	texture.loadFromImage(pauseButtonRender);
	Sprite buttonPause;
	buttonPause.setTexture(texture);
	buttonPause.setPosition(700, 50);
	window.draw(buttonPause);
}
//void GameBackground::createSunflowerSeed(RenderWindow& window)
//{
//	//if (!SunfowerTexture.loadFromFile("Images/sunflowerseed.png"))// loading file
//	if (!SunfowerTexture.loadFromFile("Images/SUNFLOWERSEEDS.png"))// loading file
//	{
//		return;//return if loading fails
//	}
//	Sunflower.setTexture(SunfowerTexture);
//	//setting position
//	float SetPositionX = 150.0f;//old x: 150.0
//	float SetPositionY = 23.0f;//old y: 19.0
//
//	Sunflower.setPosition(SetPositionX, SetPositionY);
//
//	//setting x and y axes
//	float scaleFactorX = 1.6f;
//	float scaleFactorY = 1.5f;
//
//	Sunflower.setScale(Vector2f(scaleFactorX, scaleFactorY));
//
//	window.draw(Sunflower);//drawing the sprite
//
//}

void GameBackground::createSunflowerSeed(RenderWindow& window)
{
	//if (!SunfowerTexture.loadFromFile("Images/sunflowerseed.png"))// loading file
	if (!SunfowerTexture.loadFromFile("Images/Cards/sunflower.png"))// loading file
	{
		return;//return if loading fails
	}
	Sunflower.setTexture(SunfowerTexture);
	//setting position
	float SetPositionX = 150.0f;//old x: 150.0
	float SetPositionY = 25.0f;//old y: 19.0

	Sunflower.setPosition(SetPositionX, SetPositionY);

	//setting x and y axes
	float scaleFactorX = 0.7f;
	float scaleFactorY = 0.6f;

	Sunflower.setScale(Vector2f(scaleFactorX, scaleFactorY));

	window.draw(Sunflower);//drawing the sprite

}



void GameBackground::createLandMowers(RenderWindow& window,float delT)
{
	Mower.createLawnmower1(window, delT);
	Mower.createLawnmower2(window);
	Mower.createLawnmower3(window);
	Mower.createLawnmower4(window);
	Mower.createLawnmower5(window);
}

//void GameBackground::createLockedWallnut(RenderWindow& window)
//{
//	if (!WallnutTexture.loadFromFile("Images/lockedwallnut.png"))// loading file
//	{
//		return;//return if loading fails
//	}
//	Wallnut.setTexture(WallnutTexture);
//	//setting position
//	float SetPositionX = 291.0f;//old x: 150.0
//	float SetPositionY = 25.0f;//old y: 19.0
//
//	Wallnut.setPosition(SetPositionX, SetPositionY);
//
//	//setting x and y axes
//	float scaleFactorX = 1.6f;
//	float scaleFactorY = 1.425f;
//
//	Wallnut.setScale(Vector2f(scaleFactorX, scaleFactorY));
//
//	window.draw(Wallnut);//drawing the sprite
//}

void GameBackground::createLockedWallnut(RenderWindow& window)
{
	if (!WallnutTexture.loadFromFile("Images/Cards/Wallnut-l.png"))// loading file
	{
		return;//return if loading fails
	}
	Wallnut.setTexture(WallnutTexture);
	//setting position
	float SetPositionX = 280.0f;//old x: 150.0
	float SetPositionY = 25.0f;//old y: 19.0

	Wallnut.setPosition(SetPositionX, SetPositionY);

	//setting x and y axes
	float scaleFactorX = 0.7f;
	float scaleFactorY = 0.6f;

	Wallnut.setScale(Vector2f(scaleFactorX, scaleFactorY));

	window.draw(Wallnut);//drawing the sprite
}


//void GameBackground::createWallnutSeed(RenderWindow& window)
//{
//
//	if (!theTexture.loadFromFile("Images/wallnutseed.png"))// loading file
//	{
//		return;//return if loading fails
//	}
//	theSprite.setTexture(theTexture);
//	//setting position
//	float SetPositionX = 291.0f;//old x: 150.0
//	float SetPositionY = 25.0f;//old y: 19.0
//
//	theSprite.setPosition(SetPositionX, SetPositionY);
//
//	//setting x and y axes
//	float scaleFactorX = 1.45f;
//	float scaleFactorY = 1.35f;
//
//	theSprite.setScale(Vector2f(scaleFactorX, scaleFactorY));
//
//	window.draw(theSprite);//drawing the sprite
//}

void GameBackground::createWallnutSeed(RenderWindow& window)
{

	if (!theTexture.loadFromFile("Images/Cards/Wallnut.png"))// loading file
	{
		return;//return if loading fails
	}
	theSprite.setTexture(theTexture);
	//setting position
	float SetPositionX = 280.0f;//old x: 150.0
	float SetPositionY = 25.0f;//old y: 19.0

	theSprite.setPosition(SetPositionX, SetPositionY);

	//setting x and y axes
	float scaleFactorX = 0.7f;
	float scaleFactorY = 0.6f;

	theSprite.setScale(Vector2f(scaleFactorX, scaleFactorY));

	window.draw(theSprite);//drawing the sprite
}


//void GameBackground::createLockedCherryBomb(RenderWindow& window)
//{
//	if (!theTexture.loadFromFile("Images/seedcherrybomb.png"))// loading file
//	{
//		return;//return if loading fails
//	}
//	theSprite.setTexture(theTexture);
//	//setting position
//	float SetPositionX = 433.5f;//old x: 150.0
//	float SetPositionY = 25.0f;//old y: 19.0
//
//	theSprite.setPosition(SetPositionX, SetPositionY);
//
//	//setting x and y axes
//	float scaleFactorX = 1.35f;
//	float scaleFactorY = 1.325f;
//
//	theSprite.setScale(Vector2f(scaleFactorX, scaleFactorY));
//
//	window.draw(theSprite);//drawing the sprite
//}


void GameBackground::createLockedCherryBomb(RenderWindow& window)
{
	if (!theTexture.loadFromFile("Images/Cards/cherrybomb-l.png"))// loading file
	{
		return;//return if loading fails
	}
	theSprite.setTexture(theTexture);
	//setting position
	float SetPositionX = 410.0f;//old x: 150.0
	float SetPositionY = 25.0f;//old y: 19.0

	theSprite.setPosition(SetPositionX, SetPositionY);

	//setting x and y axes
	float scaleFactorX = 0.7f;
	float scaleFactorY = 0.6f;

	theSprite.setScale(Vector2f(scaleFactorX, scaleFactorY));

	window.draw(theSprite);//drawing the sprite
}



//void GameBackground::createCherryBomb(RenderWindow& window)
//{
//	if (!theTexture.loadFromFile("Images/cherrybomb.png"))// loading file
//	{
//		return;//return if loading fails
//	}
//	theSprite.setTexture(theTexture);
//	//setting position
//	float SetPositionX = 433.5f;//old x: 150.0
//	float SetPositionY = 25.0f;//old y: 19.0
//
//	theSprite.setPosition(SetPositionX, SetPositionY);
//
//	//setting x and y axes
//	float scaleFactorX = 1.45f;
//	float scaleFactorY = 1.35f;
//
//	theSprite.setScale(Vector2f(scaleFactorX, scaleFactorY));
//
//	window.draw(theSprite);//drawing the sprite
//}

void GameBackground::createCherryBomb(RenderWindow& window)
{
	if (!theTexture.loadFromFile("Images/Cards/cherrybomb.png"))// loading file
	{
		return;//return if loading fails
	}
	theSprite.setTexture(theTexture);
	//setting position
	float SetPositionX = 410.0f;//old x: 150.0
	float SetPositionY = 25.0f;//old y: 19.0

	theSprite.setPosition(SetPositionX, SetPositionY);

	//setting x and y axes
	float scaleFactorX = 0.7f;
	float scaleFactorY = 0.6f;

	theSprite.setScale(Vector2f(scaleFactorX, scaleFactorY));

	window.draw(theSprite);//drawing the sprite
}





//void GameBackground::createLockedRepeater(RenderWindow& window)
//{
//	if (!theTexture.loadFromFile("Images/lockedrepeater.png"))// loading file
//	{
//		return;//return if loading fails
//	}
//	theSprite.setTexture(theTexture);
//	//setting position
//	float SetPositionX = 578.0f;//old x: 150.0
//	float SetPositionY = 25.0f;//old y: 19.0
//
//	theSprite.setPosition(SetPositionX, SetPositionY);
//
//	//setting x and y axes
//	float scaleFactorX = 1.45f;
//	float scaleFactorY = 1.35f;
//
//	theSprite.setScale(Vector2f(scaleFactorX, scaleFactorY));
//
//	window.draw(theSprite);//drawing the sprite
//}

void GameBackground::createLockedRepeater(RenderWindow& window)
{
	if (!theTexture.loadFromFile("Images/Cards/Repeater-l.png"))// loading file
	{
		return;//return if loading fails
	}
	theSprite.setTexture(theTexture);
	//setting position
	float SetPositionX = 540.0f;//old x: 150.0
	float SetPositionY = 25.0f;//old y: 19.0

	theSprite.setPosition(SetPositionX, SetPositionY);

	//setting x and y axes
	float scaleFactorX = 0.7f;
	float scaleFactorY = 0.6f;

	theSprite.setScale(Vector2f(scaleFactorX, scaleFactorY));

	window.draw(theSprite);//drawing the sprite
}


//void GameBackground::createRepeater(RenderWindow& window)
//{
//	if (!theTexture.loadFromFile("Images/PEASHOOTERSEEDS.png"))// loading file
//	{
//		return;//return if loading fails
//	}
//	theSprite.setTexture(theTexture);
//	//setting position
//	float SetPositionX = 578.0f;//old x: 150.0
//	float SetPositionY = 25.0f;//old y: 19.0
//
//	theSprite.setPosition(SetPositionX, SetPositionY);
//
//	//setting x and y axes
//	float scaleFactorX = 1.45f;
//	float scaleFactorY = 1.35f;
//
//	theSprite.setScale(Vector2f(scaleFactorX, scaleFactorY));
//
//	window.draw(theSprite);//drawing the sprite
//}


void GameBackground::createRepeater(RenderWindow& window)
{
	if (!theTexture.loadFromFile("Images/Cards/Repeater.png"))// loading file
	{
		return;//return if loading fails
	}
	theSprite.setTexture(theTexture);
	//setting position
	float SetPositionX = 540.0f;//old x: 150.0
	float SetPositionY = 25.0f;//old y: 19.0

	theSprite.setPosition(SetPositionX, SetPositionY);

	//setting x and y axes
	float scaleFactorX = 0.7f;
	float scaleFactorY = 0.6f;

	theSprite.setScale(Vector2f(scaleFactorX, scaleFactorY));

	window.draw(theSprite);//drawing the sprite
}

void GameBackground::drawShapeOverGrid(RenderWindow& window)
{
	//float cellWidth = 15;
	//float cellHeight = 30; 
	////300 and 170 for the first position
	//float startX = 330;
	//float startY = 850;

	float cellWidth = (150);
	float cellHeight = (170);
	float startX = 320;
	float startY = 170;
	//topLeft            1530,850
	//topRight           1680,850
	//bottomLeft         1530,1020
	//bottomRight        1680,1020

	// Define the shape (e.g., a rectangle)
	RectangleShape shape(Vector2f(cellWidth, cellHeight)); // Assuming cellWidth and cellHeight are defined in your class

	// Set the color of the shape
	shape.setFillColor(Color::Red); // Example color (you can change it as needed)

	// Iterate over each cell in the grid
	for (int row = 0; row < 5; ++row) {
		for (int col = 0; col < 9; ++col) {
			// Calculate the position of the shape for the current cell
			float shapeX = startX + col * cellWidth;
			float shapeY = startY + row * cellHeight;

			// Set the position of the shape
			shape.setPosition(shapeX, shapeY);

			// Draw the shape
			window.draw(shape);


		}
	}
	/*Vector2f topLeft = shape.getPosition();
	Vector2f topRight = topLeft + Vector2f(cellWidth, 0);
	Vector2f bottomLeft = topLeft + Vector2f(0, cellHeight);
	Vector2f bottomRight = topLeft + Vector2f(cellWidth, cellHeight);

	cout << "Top Left: (" << topLeft.x << ", " << topLeft.y << ")" << endl;
	cout << "Top Right: (" << topRight.x << ", " << topRight.y << ")" << endl;
	cout << "Bottom Left: (" << bottomLeft.x << ", " << bottomLeft.y << ")" << endl;
	cout << "Bottom Right: (" << bottomRight.x << ", " << bottomRight.y << ")" << endl;*/
}




