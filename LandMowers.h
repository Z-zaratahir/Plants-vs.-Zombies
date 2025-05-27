#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class LandMowers
{
	Texture LawnMowerTexture;
	Sprite lawnMower;


public:

	void createLawnmower1(RenderWindow& window, float);
	void createLawnmower2(RenderWindow& window);
	void createLawnmower3(RenderWindow& window);
	void createLawnmower4(RenderWindow& window);
	void createLawnmower5(RenderWindow& window);

};

