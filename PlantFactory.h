#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "../oopproject/Peashooter.h"
#include "../oopproject/Sunflower.h"
#include "../oopproject/Repeater.h"
#include "../oopproject/Wallnut.h"
#include "../oopproject/SnowPea.h"
#include "../oopproject/CherryBomb.h"
#include "../oopproject/Coordinate.h"
#include "../oopproject/Plant.h"
using namespace sf;
using namespace std;



//class PlantFactory
//{
//	Peashooter thePeashooter;
//	CherryBomb theCherryBomb;
//	Sunflower theSunflower;
//	Repeater theRepeater;
//	Wallnut theWallnut;
//	SnowPea theSnowPea;
//	PlantFactory* ptr;
//	Plant *Plants;
//	const int MAX_PLANTS;
//
//
//public:
//	PlantFactory();
//
//	PlantFactory* connector();
//
//
//};

//class PlantFactory {
//public:
//    PlantFactory();
//    virtual Plant* createPlant(float scaleX, float scaleY) = 0;
//    virtual void handlePlantSelectionArray(int mouseX, int mouseY) = 0;
//};


//class PlantFactory {
//public:
//    virtual Plant* createPlant(int x, int y, int index) = 0;
//    virtual std::string getPlantType(int index) = 0;
//};
//


//
//class PlantFactory
//{
//
//        Peashooter *thePeashooter;
//    	CherryBomb *theCherryBomb;
//    	Sunflower *theSunflower;
//    	Repeater* theRepeater;
//    	Wallnut *theWallnut;
//    	SnowPea *theSnowPea;
//
//
//public:
//    PlantFactory(); // Constructor
//    ~PlantFactory(); // Destructor
//    void createPlants(int plantType, float scaleX, float scaleY,
//        const string& seedImagePath, const string& plantImagePath,
//        RenderWindow& window, Event& event);
//
//    void dipslayPeashooter(float scaleX, float scaleY,
//        const string& seedImagePath, const string& plantImagePath,
//        RenderWindow& window, Event& event);
//
//    void dipslayCherryBomb(float scaleX, float scaleY,
//        const string& seedImagePath, const string& plantImagePath,
//        RenderWindow& window, Event& event);
//
//    void dipslaySunflower(float scaleX, float scaleY,
//        const string& seedImagePath, const string& plantImagePath,
//        RenderWindow& window, Event& event);
//
//    void dipslayRepeater(float scaleX, float scaleY,
//        const string& seedImagePath, const string& plantImagePath,
//        RenderWindow& window, Event& event);
//
//    void dipslayWallnut(float scaleX, float scaleY,
//        const string& seedImagePath, const string& plantImagePath,
//        RenderWindow& window, Event& event);
//
//    void dipslaySnowPea(float scaleX, float scaleY,
//        const string& seedImagePath, const string& plantImagePath,
//        RenderWindow& window, Event& event);
//
//};



#include "Peashooter.h"
#include "Sunflower.h"
#include "Wallnut.h"
#include "CherryBomb.h"
#include "Repeater.h"
#include "SnowPea.h"
#include <SFML/Graphics.hpp>

class PlantFactory {
private:
    Peashooter* thePeashooter;
    Sunflower* theSunflower;
    Wallnut* theWallnut;
    CherryBomb* theCherryBomb;
    Repeater* theRepeater;
    SnowPea* theSnowPea;

public:
    PlantFactory();
    ~PlantFactory();

    void createPlants(int plantType, float scaleX, float scaleY,
        const std::string& seedImagePath, const std::string& plantImagePath,
        sf::RenderWindow& window, sf::Event& event);

private:
    void displayPeashooter(float scaleX, float scaleY,
        const std::string& seedImagePath, const std::string& plantImagePath,
        sf::RenderWindow& window, sf::Event& event);

    void displayCherryBomb(float scaleX, float scaleY,
        const std::string& seedImagePath, const std::string& plantImagePath,
        sf::RenderWindow& window, sf::Event& event);

    void displaySunflower(float scaleX, float scaleY,
        const std::string& seedImagePath, const std::string& plantImagePath,
        sf::RenderWindow& window, sf::Event& event);

    void displayRepeater(float scaleX, float scaleY,
        const std::string& seedImagePath, const std::string& plantImagePath,
        sf::RenderWindow& window, sf::Event& event);

    void displayWallnut(float scaleX, float scaleY,
        const std::string& seedImagePath, const std::string& plantImagePath,
        sf::RenderWindow& window, sf::Event& event);

    void displaySnowPea(float scaleX, float scaleY,
        const std::string& seedImagePath, const std::string& plantImagePath,
        sf::RenderWindow& window, sf::Event& event);
};
