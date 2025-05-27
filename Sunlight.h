#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;



class Sunlight
{
	/*Texture theTexture;
	Sprite theSprite;
	Texture sunTexture;	
	Sprite sunSprite;


	Clock clock;


public:
	Sunlight();
	void createSun(RenderWindow& window);*/
	//void Sun(RenderWindow& window);


    sf::Texture sunTexture;
    sf::Sprite sunSprite;
    sf::Clock clock;
    bool sunVisible;

public:
   
	Sunlight();
	void createSun(sf::RenderWindow& window);

};

