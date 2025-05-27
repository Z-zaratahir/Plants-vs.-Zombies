#include "SimpleZombie.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;



SimpleZombie::SimpleZombie() {
    currentTextureIndex = 0;
    animationSpeed = 0.1f; //Sppeed of animation
    float allowedYPositions[] = { 160.0f, 330.0f, 510.0f, 680.0f, 860.0f };

    // Randomly select an index from the allowed Y Positions array
    int randomIndex = rand() % (sizeof(allowedYPositions) / sizeof(allowedYPositions[0]));

    // Set playerY using the selected allowed Y position
    playerY = allowedYPositions[randomIndex];


    playerX = static_cast<float>(rand() % 1500 + 2000);
    // Load all 22 player movement textures together
    for (int i = 0; i < 22; ++i) {
        string PNGname = "Images/Zombie_" + std::to_string(i) + ".png";
        if (!playerTextures[i].loadFromFile(PNGname)) {
            cout << "Failed to load texture: " << PNGname << endl;
            return;
        }
    }

    // Create player sprite using the first texture 
    playerSprite.setTexture(playerTextures[0]);
    playerSprite.setPosition(playerX, playerY);
}

void SimpleZombie::moveLeft(Time delT) {
    const float movementSpeed = 25.0f; // movement speed      //old 10.0f
    playerX -= movementSpeed * delT.asSeconds();
    playerSprite.setPosition(playerX, playerY);
}

void SimpleZombie::Animation(Time delT) {
    const float frameDuration = 0.01f; // Adjust frame duration as needed
    static float animationTimer = 0.0f;
    animationTimer += delT.asSeconds();

    if (animationTimer >= frameDuration) {
        currentTextureIndex = (currentTextureIndex + 1) % 22; // Assuming 22 frames in the spritesheet
        playerSprite.setTexture(playerTextures[currentTextureIndex]);
        animationTimer = 0.0f;
    }
}



void SimpleZombie::Draw(RenderWindow& window) const {
    window.draw(playerSprite);
}


void SimpleZombie::SetPosition(float x, float y)
{
    playerSprite.setPosition(x, y);
}

float SimpleZombie::GetPositionX()
{
    return playerSprite.getPosition().x;
}

float SimpleZombie::GetPositionY()
{
    return playerSprite.getPosition().y;
}






// zombies can only move on y axis = 100.0f,  270.0f, 450.0f, 620.0f, 800.0f





/////////////////////////////////////1st try///////////////////////

//
//SimpleZombie::SimpleZombie():Frame(0),FrameTime(0.1), Time(0.0)
//{
//	for (int i = 0; i < 21; i++)
//	{
//		theTexture[i].loadFromFile("Zombie_" + to_string(i) + ".png");
//	}
//	theSprite.setTexture(theTexture[Frame]);
//
//	theSprite.setPosition(900, 100);
//
//}



/////////////////////////////////2nd try////////////////////////////////////////



//SimpleZombie::SimpleZombie() {
//    currentTextureIndex = 0;
//    animationSpeed = 0.1f; // Change this to adjust animation speed
//    playerY = static_cast<float>(rand() % 600);  // Random position between 0 and 600
//    playerX = 1500.0f; // Start from the right edge
//
//    // Load all 21 player movement textures
//    for (int i = 0; i < 21; ++i) {
//        std::string filename = "Images/Zombie_" + std::to_string(i) + ".png";
//        if (!playerTextures[i].loadFromFile(filename)) {
//            std::cerr << "Failed to load texture: " << filename << std::endl;
//            return;
//        }
//    }
//
//    // Create player sprite using the first texture
//    playerSprite.setTexture(playerTextures[0]);
//    playerSprite.setPosition(playerX, playerY);
//}
//
//void SimpleZombie::moveLeft(float deltaTime) {
//    float movementSpeed = 1000.0f; // Adjust movement speed as needed   //old 100.0f
//    playerX -= movementSpeed * deltaTime;
//    playerSprite.setPosition(playerX, playerY);
//}
//
//void SimpleZombie::animate(float deltaTime) {
//   
//    static const float delay = 0.1f;
//    animationSpeed -= deltaTime;
//
//    
//    if (animationSpeed <= 0.0f) {// 0.0f
//        currentTextureIndex = (currentTextureIndex + 1) %21;
//
//        playerSprite.setTexture(playerTextures[currentTextureIndex]);
//        animationSpeed = delay; // Reset animation speed     //old 0.1f
//    }
//}
//
//void SimpleZombie::draw(sf::RenderWindow& window) {
//    window.draw(playerSprite);
//}
//











//void SimpleZombie::createSimpleZombie(RenderWindow& window, float deltaTime)
//{
//    /////////try 0
//    /* player.setTextureRect(IntRect(0, 0, 141, 256));
//
//
//     int xDirection=0;
//     xDirection = (int)player.getPosition().x/10 % 13;
//     xDirection *= 141;
//     player.setTextureRect(IntRect(xDirection, 0, 141, 256));
//     player.move(-5, 0);*/
//
//}
//
//void SimpleZombie::createSimpleZombie(RenderWindow& window, float deltaTime)
//{
//
//    ////////////////////////////////////////try 1
//    float movementSpeed = 50.0f;
//    if (!theTexture.loadFromFile("Images/SimpleZombieSpritesheet-removebg.png"))// loading file
//    {
//        return;//return if loading fails
//    }
//
//    player.setTexture(theTexture);
//
//    //setting position
//    float SetPositionX = 1067.0f;
//    float SetPositionY = 580.0f;
//
//    player.setPosition(SetPositionX, SetPositionY);
//
//    animationTimer += deltaTime;
//    if (animationTimer >= animationSpeed)
//    {
//        currentTextureIndex = (currentTextureIndex + 1) % 13;
//        int xDirection = currentTextureIndex * 140;
//        player.setTextureRect(IntRect(xDirection, 0, 140, 256));
//
//        // Move the sprite based on deltaTime and movementSpeed
//        player.move(-movementSpeed * deltaTime, 0);
//
//        animationTimer = 0.0f; // Reset the timer
//    }
//    player.move(-5, 0);
//
//    window.draw(player);
//
//}



//
//SimpleZombie::SimpleZombie() :
//    currentTextureIndex(0), animationTimer(0.0f),  // Initialize animationTimer to zero
//    animationSpeed(0.1f)
//{
//
//}
//
//
//
//    //for (int i = 0; i < 21; i++)
//    //	{
//    //		theTexture[i].loadFromFile("Zombie_" + to_string(i) + ".png");
//    //	}
//    //	theSprite.setTexture(theTexture[Frame]);
//    //}
//
//void SimpleZombie::createSimpleZombie(RenderWindow& window, float deltaTime)
//{
//
//
//
//    ////////////////////////////////////////another try
//      // Update the animation timer
//    animationTimer += deltaTime;
//
//    if (!theTexture.loadFromFile("Images/SimpleZombieSpritesheet-removebg.png"))// loading file
//    {
//        return; // Return if loading fails
//    }
//
//    player.setTexture(theTexture);
//
//    // Set initial position
//    float SetPositionX = 1567.0f;
//    float SetPositionY = 800.0f;
//
//    // Move the sprite to the left based on animationTimer
//    float movementSpeed = 70.0f; // Adjust movement speed as needed
//    SetPositionX -= movementSpeed * deltaTime;
//    player.setPosition(SetPositionX, SetPositionY);
//
//    // Update the texture rect based on the animation frame
//    static const float frameDuration = 0.01f; // Adjust frame duration as needed
//    if (animationTimer >= frameDuration) {
//        currentTextureIndex = (currentTextureIndex + 1) % 13; // Assuming 13 frames in the spritesheet
//        animationTimer = 0.0f;
//    }
//
//    int xDirection = currentTextureIndex * 141; // Assuming each frame width is 141 pixels
//    player.setTextureRect(IntRect(xDirection, 0, 141, 256));
//
//    // Draw the sprite
//    window.draw(player);
//
//}
//
//
//
