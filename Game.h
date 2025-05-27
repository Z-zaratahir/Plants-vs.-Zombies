//#pragma once
//#include <iostream>
//#include "GameBackground.h"
//#include "../oopproject/Sunlight.h"
//#include "../oopproject/SimpleZombie.h"
//#include <SFML/Graphics.hpp>
//
//using namespace sf;
//using namespace std;

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameBackground.h"
//#include "Sunlight.h"
#include "SimpleZombie.h"
#include "Plant.h"
#include "PlantFactory.h"
#include "Menu.h"
#include "PlantFactory.h" 
using namespace sf;
using namespace std;


class Game
{
	
	GameBackground Background;
	//Sunlight sunlight;
	SimpleZombie* ArrayZombie;
	float* zombiePositionX;
	float* zombiePositionY;
	PlantFactory PF;

public:
	Game();
	int StartGame();
	~Game();

};

