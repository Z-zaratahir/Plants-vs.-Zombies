//#pragma once
//#include <SFML/Graphics.hpp>
//using namespace sf;
//using namespace std;
//
//class Plant
//{
//protected:
//    int row;
//    int col;
//    int fireRate;
//
//public:
//    Plant(int r, int c, int f);
//
//    int getRow() const;
//
//    int getCol() const;
//
//    virtual void update(int frameCount) = 0;
//
//    virtual void place(int r, int c);
//
//    virtual void drawPlant(RenderWindow& window, const string& imagePath, int i, int j);
//
//
//
//
//};

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;




class Plant
{
protected:
    Texture plantSeedTexture;// setting a texture for the seed
    Sprite plantSeedSprite;// setting a sprite for the seed
    Texture plantTexture;// setting a texture for the plant
    const int maxPlants = 100;
    Sprite plantSprites[100];// setting an array of sprites for the plants
    int numPlants = 0;
    float scaleFactorX;// width
    float scaleFactorY;// width
    bool isDragging = false;// check for mouse clicking
    Vector2f offset;//used as a variable for mouse positioning

public:
    Plant(float scaleX = 1.0f, float scaleY = 1.0f);//parameterised constructor
    virtual void loadTextures(const string& seedImagePath, const string& plantImagePath);//for loading loading textures
    virtual void handleEvents(RenderWindow& window, Event& event);//movement checking
    virtual void update();//setting the scale of sprites of plants
    virtual void draw(RenderWindow& window);// for drawing the sprites of plants after dropping
    virtual ~Plant() {}
};


