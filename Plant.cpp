//#include "Plant.h"
//#include <iostream>
//#include "Coordinate.h"
//#include <SFML/Graphics.hpp>
//using namespace sf;
//using namespace std;
//
//Plant::Plant(int r, int c, int f) : row(r), col(c), fireRate(f)
//{
//}
//
//int Plant::getRow() const
//{
//    return row;
//}
//
//int Plant::getCol() const
//{
//    return col;
//}
//
//void Plant::place(int r, int c)
//{
//    row = r;
//    col = c;
//}
//
//void Plant::drawPlant(RenderWindow& window, const string& imagePath, int i, int j)
//{
//    Coordinate temp;
//    //   int a1 = fblock[1]; int a2 = fblock[2];
//       // Draw the hero card at the calculated position
//    temp.x = 320 + j * 170;
//    temp.y = 170 + i * 320;
//
//    // Load the hero image
//    Texture texture;
//    if (!texture.loadFromFile(imagePath)) {
//        // If loading the image fails, print an error message and return
//        cerr << "Failed to load hero image from file: " << imagePath << std::endl;
//        return;
//    }
//
//    // Create sprite from the texture
//    Sprite plant;
//    plant.setTexture(texture);
//    plant.setTextureRect(IntRect(20, 135, 170, 320)); // Set texture rectangle
//    plant.setPosition(temp.x, temp.y); // Set position
//
//    // Draw the hero sprite
//    window.draw(plant);
//}
//
//
//
//
//

#include "Plant.h"
#include <iostream>
#include "Coordinate.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


Plant::Plant(float scaleX, float scaleY) : scaleFactorX(scaleX), scaleFactorY(scaleY) {}

void Plant::loadTextures(const string& seedImagePath, const string& plantImagePath)
{
    if (!plantSeedTexture.loadFromFile(seedImagePath) || !plantTexture.loadFromFile(plantImagePath))
    {
        cerr << "Failed to load textures." << endl;
        return;
    }

    plantSeedSprite.setTexture(plantSeedTexture);
    plantSeedSprite.setPosition(70, 170);
}

void Plant::handleEvents(RenderWindow& window, Event& event)
{
    if (event.type == Event::Closed)
        window.close();
    else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
    {
        if (plantSeedSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        {
            if (numPlants < maxPlants)//  matching the mouse and position of sprite 
            {
                plantSprites[numPlants].setTexture(plantTexture);
                plantSprites[numPlants].setPosition(event.mouseButton.x, event.mouseButton.y);
                plantSprites[numPlants].setScale(Vector2f(scaleFactorX, scaleFactorY));
                plantSprites[numPlants].setOrigin(plantSprites[numPlants].getLocalBounds().width / 2, plantSprites[numPlants].getLocalBounds().height / 2);
                numPlants++;
                isDragging = true;
                offset = plantSprites[numPlants - 1].getPosition() - Vector2f(event.mouseButton.x, event.mouseButton.y);
            }
        }
    }
    else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
    {
        isDragging = false;// ounf the target 

        // Check if the plantSprite is dropped on the plantSeedSprite
        for (int i = 0; i < numPlants; ++i)
        {
            if (plantSeedSprite.getGlobalBounds().intersects(plantSprites[i].getGlobalBounds()))
            {
                // If collided, remove the plantSprite
                for (int j = i; j < numPlants - 1; ++j)
                {
                    plantSprites[j] = plantSprites[j + 1];
                }
                numPlants--;
            }
        }
    }
    else if (event.type == Event::MouseMoved && isDragging)
    {
        plantSprites[numPlants - 1].setPosition(Vector2f(event.mouseMove.x, event.mouseMove.y) + offset);
    }
}

void Plant::update()
//setting the scale of sprites of plants
{
    for (int i = 0; i < numPlants; ++i)
    {
        plantSprites[i].setScale(Vector2f(scaleFactorX, scaleFactorY));
    }
}

void Plant::draw(RenderWindow& window)
{// for drawing the sprites of pea shooter after dropping
    window.draw(plantSeedSprite);
    for (int i = 0; i < numPlants; ++i)
    {
        window.draw(plantSprites[i]);
    }
}
