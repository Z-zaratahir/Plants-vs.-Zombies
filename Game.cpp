#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SimpleZombie.h"
#include "Leaderboard.h"
#include "Plant.h"
#include "Peashooter.h"
#include "Sunflower.h"
#include "Wallnut.h"
#include "Repeater.h"
#include "SnowPea.h"
#include "PlantFactory.h"
#include "CherryBomb.h"
#include "Coordinate.h"
#include "ScreenGrid.h"
#include "PlantFactory.h" 
#include "GameBackground.h" 
#include <SFML/Graphics.hpp>
#include "PlantFactory.h" 

using namespace sf;
using namespace std;

Game::Game() 
	: ArrayZombie(NULL),
	zombiePositionX(NULL),
	zombiePositionY(NULL){}
	//PlantFactory(new PlantFactory()) {}

//deallocating memory
Game::~Game()
{
	if (ArrayZombie != NULL) {
		delete[] ArrayZombie;
		ArrayZombie = NULL;
	}
	if (zombiePositionX != NULL) {
		delete[] zombiePositionX;
		zombiePositionX = NULL;
	}
	if (zombiePositionY != NULL) {
		delete[] zombiePositionY;
		zombiePositionY = NULL;
	}

	//delete plantFactory;
}


int Game::StartGame()
{
	//RenderWindow App;
	//Create a window, n*n
	//RenderWindow window(VideoMode(1900, 900), "Plants Vs Zombies");
	//App.Create(VideoMode(800, 600, 32), "Plants Vs Zombies", Style::Fullscreen);
	RenderWindow window (VideoMode(), "Plants Vs Zombies", Style::Fullscreen);
	
	
	//Game icon
	Image icon;
	if (!icon.loadFromFile("Images/icon.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());
	

	///////////////////////////////////////

	//Game field (5*9)
	//Point 137*79 - leftmost point
	//length 41; width 53
	const int ROWS = 5;
	const int COLS = 9;

	int score = 0;


	const int MAX_PLANTS = 50;  // Maximum number of plants
	Plant* Plants[MAX_PLANTS] = { nullptr }; // Array to store pointers to plants



	ScreenGrid screen;

	bool FIELD_GAME_STATUS[ROWS][COLS];

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			FIELD_GAME_STATUS[i][j] = true;
			screen.setValue(i, j, -1);
		}
	}



	// Allocate memory for placeCards outside the game loop
	Coordinate* placeCards = new Coordinate[6];
	Coordinate selectedCardPosition;

	// Initialize placeCards with default positions
	for (int i = 0; i < 6; ++i) {
		placeCards[i].x = 20 + i * 130; // Default x position with an initial offset
		placeCards[i].y = 25.0; // Default y position
	}
	// Initialize selectedCardPosition with default positions
	selectedCardPosition.x = 0; // Default x position
	selectedCardPosition.y = 0; //Default y position

	bool cardPlaced = false;
	int showPlants = 1;
	Coordinate newCardPosition;
	int selectedCardIndex = -1;
	string spriteImagePath = ""; // Set the path for the sprite image based on the card index
	string spriteSeedImagePath = ""; // Set the path for the sprite seed image based on the card index



	Texture titleTexture;
	if (!titleTexture.loadFromFile("Images/Titlerr.png"))
	{
		return 1;
	}
	Sprite titleSprite(titleTexture);

	// Load the play button image
	Texture playButtonTexture;
	if (!playButtonTexture.loadFromFile("Images/PLAY.png"))
	{
		return 1;
	}
	const float scaleFactor = 1.1f;
	Sprite playButtonSprite(playButtonTexture);

	playButtonSprite.setPosition((window.getSize().x - playButtonSprite.getGlobalBounds().width) / 2,
		(window.getSize().y - playButtonSprite.getGlobalBounds().height) / 2 + 400); // Adjust as needed

	bool gameStarted = false;
	srand(time(nullptr));


	//	Game myGame;
	Clock clock;
	Clock timeMoney;
	

	float elapsedTime = 0.0f;
	float spawnInterval = 5.0f; // Time interval after which zombies start appearing (in seconds)
	bool zombiesSpawned = false;


	srand(time(NULL));
	int maxZombies = rand() % 10 + 5;

	//allocating memory
	ArrayZombie = new SimpleZombie[maxZombies];
	zombiePositionX = new float[maxZombies];
	zombiePositionY = new float[maxZombies];

	for (int i = 0; i < maxZombies; i++)
	{
		//Setting zombies' positions
		zombiePositionX[i] = 1500.0f;
		zombiePositionY[i] = static_cast<float>(rand() % 700 + 100);
		ArrayZombie[i].SetPosition(zombiePositionX[i], zombiePositionY[i]);
	}

	//MAin functioning loop

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		float moneyTime = timeMoney.getElapsedTime().asSeconds();

		//For keeping track of time for Zombies
		Time deltaTime = clock.restart();
		float deltaTimeSeconds = deltaTime.asSeconds();

		//For keeping track of time to control game speed
		float delta = clock.restart().asSeconds();
			elapsedTime += delta;


		clock.restart();
		time = time / 800;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)// the cross button
				window.close();

			////if (event.type == Event::MouseButtonPressed && event.key.code == Mouse::Right)
			else if (event.KeyPressed && event.key.code == Keyboard::Escape)

			{
				window.close();
			}


			else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				////Inside mouse event
				int mouseX = event.mouseButton.x;
				int mouseY = event.mouseButton.y;
				cout << "Mouse clicked at: " << mouseX << ", " << mouseY << std::endl; // Debugging

				/// Check if the play button is clicked
				if (playButtonSprite.getGlobalBounds().contains(mouseX, mouseY)) {
					gameStarted = true;
					 ////Increase the button scale when clicked
					playButtonSprite.setScale(scaleFactor, scaleFactor);
				}//Play button end

				if (selectedCardIndex != -1 && cardPlaced == true && mouseX >= 320 && mouseY >= 170) {
					// If a card is already selected, place it at the clicked position
					selectedCardPosition.x = mouseX;
					selectedCardPosition.y = mouseY;
					// Calculate the position on the game field based on clicked coordinates
					int fieldX = (mouseX - 320) / 170; // Calculate column index
					int fieldY = (mouseY - 170) / 320;   // Calculate row index
					// Check if the calculated indices are within the valid range
					if (fieldX >= 0 && fieldX < 9 && fieldY >= 0 && fieldY < 5 && FIELD_GAME_STATUS[fieldY][fieldX] == false) {

						if (screen.getValue(fieldY, fieldX) == -1) {
							screen.setValue(fieldY, fieldX, selectedCardIndex);
						}
						cout << "column index" << (mouseX - 320) / 170; // Calculate column index
						cout << "row index" << (mouseY - 170) / 320;   // Calculate row index
						// Update the game field status to reflect that the block is occupied by a hero card
						FIELD_GAME_STATUS[fieldY][fieldX] = true;
					}
					cardPlaced = false;
					//  selectedCardIndex = -1; // Reset selected card index
				}//if end

				else {
					// Check if any card is clicked
					for (int i = 0; i < 6; i++) {
						if (mouseX >= placeCards[i].x && mouseX <= placeCards[i].x + 135 && mouseY >= placeCards[i].y && mouseY <= placeCards[i].y + 170) {
							
							selectedCardIndex = i;
							


							
							//PF.createPlants(selectedCardIndex, 1.0f, 1.0f, spriteSeedImagePath, spriteImagePath,window,event);
							cardPlaced = true;
							break;
						}
					}
				}//else end

			}//Mouse event end

		}

		// Check if the mouse is hovering over the play button
		if (playButtonSprite.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
			playButtonSprite.setScale(scaleFactor, scaleFactor);
		}
		else {
			playButtonSprite.setScale(1.0f, 1.0f);
		}

		//Movement for each Zombie
		for (int i = 0; i < maxZombies; i++)
		{
			ArrayZombie[i].moveLeft(deltaTime);
			ArrayZombie[i].Animation(deltaTime);
		}
		

		if (selectedCardIndex == 0)
		{
			spriteImagePath = "Images/Plants/Peashooter/Peashooter_0.png"; // Set the path for the sprite image based on the card index
			spriteSeedImagePath = "Images/Cards/PeaShooter.png"; // Set the path for the sprite seed image based on the card index


		}
		
		if (selectedCardIndex == 1)
		{
			spriteImagePath = "Images/Plants/Sunflower/SunFlower_0.png"; // Set the path for the sprite image based on the card index
			spriteSeedImagePath = "Images/Cards/sunflower.png"; // Set the path for the sprite seed image based on the card index


		}

		if (selectedCardIndex == 2)
		{
			spriteImagePath = "Images/Plants/WallNut/WallNut_0.png"; // Set the path for the sprite image based on the card index
			spriteSeedImagePath = "Images/Cards/Wallnut.png"; // Set the path for the sprite seed image based on the card index


		}

		if (selectedCardIndex == 3)
		{
			spriteImagePath = "Images/Plants/CherryBomb/CherryBomb_0.png"; // Set the path for the sprite image based on the card index
			spriteSeedImagePath = "Images/Cards/cherrybomb.png"; // Set the path for the sprite seed image based on the card index


		}

		if (selectedCardIndex == 4)
		{
			spriteImagePath = "Images/Plants/Repeater/Repeater_0.png"; // Set the path for the sprite image based on the card index
			spriteSeedImagePath = "Images/Cards/Repeater.png"; // Set the path for the sprite seed image based on the card index


		}

		if (selectedCardIndex == 5)
		{
			spriteImagePath = "Images/Plants/SnowPea/SnowPea_0.png"; // Set the path for the sprite image based on the card index
			spriteSeedImagePath = "Images/Cards/snowpea.png"; // Set the path for the sprite seed image based on the card index


		}


		window.clear();


		if (!gameStarted) {
			window.draw(titleSprite);
			window.draw(playButtonSprite); // Draw the play button         
		}

		
		

		else {
			Background.createBackGround(window, "Images/Frontyard.png");//display background
			Background.createWoodenBar(window);//display wooden selection bar
			Background.createMenuButton(window);
			Background.createLandMowers(window, deltaTimeSeconds);
			PF.createPlants(selectedCardIndex, 1.75f, 1.75f, spriteSeedImagePath, spriteImagePath, window, event);
			

			Background.createScoreButton(window);

			// Draw score
			Font font;
			if (font.loadFromFile("Fonts/Weoqiosvintage.ttf")) {
				Text text;
				text.setFont(font);
				text.setString(to_string(score));
				text.setCharacterSize(36);
				text.setFillColor(Color::Black);
				text.setPosition(785, 53);
				window.draw(text);
			}
			else {
				cout << "Failed to load font!" << endl;
			}




			if (elapsedTime >= spawnInterval && !zombiesSpawned)
			{
				zombiesSpawned = true; // Setting flag to true so that zombies don't spawn repeatedly
			}

			for (int i = 0; i < maxZombies; i++)
			{
				ArrayZombie[i].Draw(window);
			}

			
			Background.createPeaShooterSeed(window);
			Background.createSunflowerSeed(window);
			Background.createLockedWallnut(window);
			Background.createWallnutSeed(window);
			Background.createLockedCherryBomb(window);
			Background.createCherryBomb(window);
			Background.createLockedRepeater(window);
			Background.createRepeater(window);

		}
		window.display();
	}
	return 0;
}





