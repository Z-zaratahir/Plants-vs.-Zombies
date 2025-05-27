#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class SimpleZombie
{
    Texture playerTextures[22];
    Sprite playerSprite;
    int currentTextureIndex;
    float animationSpeed;
    float playerY;
    float playerX;

public:
    SimpleZombie();

    void moveLeft(Time delT);

    void Animation(Time delT);

    void Draw(RenderWindow& window) const;

    void SetPosition(float x, float y);

    float GetPositionX();
    float GetPositionY();


    
    
    
    
    
    
    
    
    
    
    
    
    /*


 1st try////////////////////////////////


	Texture theTexture[21];
	Sprite theSprite;
	unsigned int Frame;
	float FrameTime;
	float Time;

public:
	SimpleZombie();
	void createSimpleZombie(RenderWindow& window);*/









    //////////////2nd try
//
//   Texture playerTextures[21];
//    sf::Sprite playerSprite;
//    int currentTextureIndex;
//    float animationSpeed;
//    float playerY;
//    float playerX;
//
//public:
//    SimpleZombie();
//
//    void moveLeft(float deltaTime);
//
//    void animate(float deltaTime);
//
//    void draw(sf::RenderWindow& window);











    /////3rd try////////////////////////////


   /*Sprite player;

    Texture theTexture;
    float animationTimer;
    float animationSpeed;
    int currentTextureIndex;
public:
    SimpleZombie();
    void createSimpleZombie(RenderWindow& window, float deltaTime);*/



};

