//#pragma once
//#include <iostream>
//#include <SFML/Graphics.hpp>
//#include "Coordinate.h"
//#include "Plant.h"
//using namespace sf;
//using namespace std;
//
//class Peashooter :public Plant
//{
//public:
//    using Plant::Plant; // Inherit constructor from Plant class
//
//    void update(int frameCount) {};
//
//    void drawPlant(RenderWindow& window, const string& imagePath, int i, int j) override
//    {
//        Coordinate temp;
//        // Draw the plant at the calculated position
//        temp.x = 320 + j * 170;
//        temp.y = 170 + i * 320;
//
//        // Load the plant image
//        Texture texture;
//        if (!texture.loadFromFile(imagePath)) {
//            // If loading the image fails, print an error message and return
//            cerr << "Failed to load plant image from file: " << imagePath << std::endl;
//            return;
//        }
//
//        // Create sprite from the texture
//        Sprite plant;
//        plant.setTexture(texture);
//        plant.setTextureRect(IntRect(20, 135, 170, 320)); // Set texture rectangle
//        plant.setPosition(temp.x, temp.y); // Set position
//
//        // Draw the plant sprite
//        window.draw(plant);
//    }
//
//};



#pragma once
#include "Plant.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Peashooter : public Plant
{
public:
    Peashooter();
    Peashooter(float scaleX, float scaleY);
    virtual void loadTextures(const string& seedImagePath, const string& plantImagePath)override;
    void handleEvents(RenderWindow& window, Event& event) override;
    void update() override;
    void draw(RenderWindow& window) override;

};




