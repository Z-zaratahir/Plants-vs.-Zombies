//#include "PlantFactory.h"
//#include <SFML/Graphics.hpp>
//#include <iostream>
//using namespace sf;
//using namespace std;
//
//
////PlantFactory::PlantFactory()
////{
////}
//
////PlantFactory* PlantFactory::connector()
////{
////	const int MAX_PLANTS = 50;  // Maximum number of plants
////	Plants[MAX_PLANTS] = { nullptr }; // Array to store pointers to plants
////
////
////
////
////	return nullptr;
////}
//
//
////class ConcretePlantFactory : public PlantFactory {
////public:
////    Plant* createPlant(int x, int y, int index) override {
////        Plant* plant = nullptr;
////        switch (index) {
////        case 0:
////            plant = new Peashooter(x, y, 0);
////            break;
////        case 1:
////            plant = new Sunflower(x, y, 0);
////            break;
////        case 2:
////            plant = new Wallnut(x, y, 0);
////            break;
////        case 3:
////            plant = new CherryBomb(x, y, 0);
////            break;
////        case 4:
////            plant = new Repeater(x, y, 0);
////            break;
////        default:
////            plant = nullptr;
////            break;
////        }
////        return plant;
////    }
////
////    std::string getPlantType(int index) override {
////        switch (index) {
////        case 0:
////            return "Peashooter";
////        case 1:
////            return "Sunflower";
////        case 2:
////            return "Wallnut";
////        case 3:
////            return "CherryBomb";
////        case 4:
////            return "Repeater";
////        default:
////            return "Unknown";
////        }
////    }
////};
//
//
//
//
//    PlantFactory::PlantFactory()
//    {
//        thePeashooter = NULL;
//        theCherryBomb = NULL;
//        theSunflower = NULL;
//        theRepeater = NULL;
//        theWallnut = NULL;
//        theSnowPea = NULL;
//    }
//    PlantFactory::~PlantFactory()
//    {
//        delete thePeashooter;
//        delete theCherryBomb;
//        delete theSunflower;
//        delete theRepeater;
//        delete theWallnut;
//        delete theSnowPea;
//        
//    }
//    void PlantFactory::createPlants(int plantType, float scaleX, float scaleY,
//        const string& seedImagePath, const string& plantImagePath,
//        RenderWindow& window, Event& event) 
//    
//    {
//        switch (plantType) {
//        case 0:
//            dipslayPeashooter(scaleX, scaleY, seedImagePath, plantImagePath, window, event);
//        case 1:
//            dipslaySunflower(scaleX, scaleY, seedImagePath, plantImagePath, window, event);
//        case 2:
//            dipslayWallnut(scaleX, scaleY, seedImagePath, plantImagePath, window, event);
//        case 3:
//            dipslayCherryBomb(scaleX, scaleY, seedImagePath, plantImagePath, window, event);
//        case 4:
//            dipslayRepeater(scaleX, scaleY, seedImagePath, plantImagePath, window, event);
//        case 5:
//            dipslaySnowPea(scaleX, scaleY, seedImagePath, plantImagePath, window, event);
//        default:
//            break;
//        }
//    }
//
//    void PlantFactory::dipslayPeashooter(float scaleX, float scaleY, const string& seedImagePath, const string& plantImagePath, RenderWindow& window, Event& event)
//    {
//        // Calling functions of thePeashooter
//        if (!thePeashooter) {
//            // Creates a new instance of Peashooter only if it doesn't exist
//            thePeashooter = new Peashooter(scaleX, scaleY);
//        }
//
//        // Call functions of thePeashooter
//        thePeashooter->loadTextures(seedImagePath, plantImagePath);
//        thePeashooter->handleEvents(window, event);
//        thePeashooter->update();
//        thePeashooter->draw(window);
//
//    }
//
//    void PlantFactory::dipslayCherryBomb(float scaleX, float scaleY, const string& seedImagePath, const string& plantImagePath, RenderWindow& window, Event& event)
//    {
//
//        // Calling functions of thePeashooter
//        if (!theCherryBomb) {
//            // Creates a new instance of Peashooter only if it doesn't exist
//            theCherryBomb = new CherryBomb(scaleX, scaleY);
//        }
//
//        // Call functions of thePeashooter
//        theCherryBomb->loadTextures(seedImagePath, plantImagePath);
//        theCherryBomb->handleEvents(window, event);
//        theCherryBomb->update();
//        theCherryBomb->draw(window);
//
//    }
//
//    void PlantFactory::dipslaySunflower(float scaleX, float scaleY, const string& seedImagePath, const string& plantImagePath, RenderWindow& window, Event& event)
//    {
//        // Calling functions of thePeashooter
//        if (!theSunflower) {
//            // Creates a new instance of Peashooter only if it doesn't exist
//            theSunflower = new Sunflower(scaleX, scaleY);
//        }
//
//        // Call functions of thePeashooter
//        theSunflower->loadTextures(seedImagePath, plantImagePath);
//        theSunflower->handleEvents(window, event);
//        theSunflower->update();
//        theSunflower->draw(window);
//    }
//
//    void PlantFactory::dipslayRepeater(float scaleX, float scaleY, const string& seedImagePath, const string& plantImagePath, RenderWindow& window, Event& event)
//    {
//        // Calling functions of thePeashooter
//        if (!theRepeater) {
//            // Creates a new instance of Peashooter only if it doesn't exist
//            theRepeater = new  Repeater(scaleX, scaleY);
//        }
//
//        // Call functions of thePeashooter
//        theRepeater->loadTextures(seedImagePath, plantImagePath);
//        theRepeater->handleEvents(window, event);
//        theRepeater->update();
//        theRepeater->draw(window);
//    }
//
//    void PlantFactory::dipslayWallnut(float scaleX, float scaleY, const string& seedImagePath, const string& plantImagePath, RenderWindow& window, Event& event)
//    {
//        // Calling functions of thePeashooter
//        if (!theWallnut) {
//            // Creates a new instance of Peashooter only if it doesn't exist
//            theWallnut = new Wallnut(scaleX, scaleY);
//        }
//
//        // Call functions of thePeashooter
//        theWallnut->loadTextures(seedImagePath, plantImagePath);
//        theWallnut->handleEvents(window, event);
//        theWallnut->update();
//        theWallnut->draw(window);
//    }
//
//    void PlantFactory::dipslaySnowPea(float scaleX, float scaleY, const string& seedImagePath, const string& plantImagePath, RenderWindow& window, Event& event)
//    {
//        // Calling functions of thePeashooter
//        if (!theSnowPea) {
//            // Creates a new instance of Peashooter only if it doesn't exist
//            theSnowPea = new  SnowPea(scaleX, scaleY);
//        }
//
//        // Call functions of thePeashooter
//        theSnowPea->loadTextures(seedImagePath, plantImagePath);
//        theSnowPea->handleEvents(window, event);
//        theSnowPea->update();
//        theSnowPea->draw(window);
//    }
//
//
//


#include "PlantFactory.h"
#include "Peashooter.h"
#include "Sunflower.h"
#include "Wallnut.h"
#include "CherryBomb.h"
#include "Repeater.h"
#include "SnowPea.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

PlantFactory::PlantFactory() : thePeashooter(nullptr), theCherryBomb(nullptr), theSunflower(nullptr),
theRepeater(nullptr), theWallnut(nullptr), theSnowPea(nullptr) {}

PlantFactory::~PlantFactory() {
    delete thePeashooter;
    delete theCherryBomb;
    delete theSunflower;
    delete theRepeater;
    delete theWallnut;
    delete theSnowPea;
}

void PlantFactory::createPlants(int plantType, float scaleX, float scaleY,
    const string& seedImagePath, const string& plantImagePath,
    RenderWindow& window, Event& event)
{
    switch (plantType) {
    case 0:
        displayPeashooter(scaleX, scaleY, seedImagePath, plantImagePath, window, event);
        break;
    case 1:
        displaySunflower(scaleX, scaleY, seedImagePath, plantImagePath, window, event);
        break;
    case 2:
        displayWallnut(scaleX, scaleY, seedImagePath, plantImagePath, window, event);
        break;
    case 3:
        displayCherryBomb(scaleX, scaleY, seedImagePath, plantImagePath, window, event);
        break;
    case 4:
        displayRepeater(scaleX, scaleY, seedImagePath, plantImagePath, window, event);
        break;
    case 5:
        displaySnowPea(scaleX, scaleY, seedImagePath, plantImagePath, window, event);
        break;
    default:
        break;
    }
}

void PlantFactory::displayPeashooter(float scaleX, float scaleY,
    const string& seedImagePath, const string& plantImagePath,
    RenderWindow& window, Event& event)
{
    if (!thePeashooter) {
        thePeashooter = new Peashooter(scaleX, scaleY);
    }

    thePeashooter->loadTextures(seedImagePath, plantImagePath);
    thePeashooter->handleEvents(window, event);
    thePeashooter->update();
    thePeashooter->draw(window);
}

void PlantFactory::displayCherryBomb(float scaleX, float scaleY,
    const string& seedImagePath, const string& plantImagePath,
    RenderWindow& window, Event& event)
{
    if (!theCherryBomb) {
        theCherryBomb = new CherryBomb(scaleX, scaleY);
    }

    theCherryBomb->loadTextures(seedImagePath, plantImagePath);
    theCherryBomb->handleEvents(window, event);
    theCherryBomb->update();
    theCherryBomb->draw(window);
}

void PlantFactory::displaySunflower(float scaleX, float scaleY,
    const string& seedImagePath, const string& plantImagePath,
    RenderWindow& window, Event& event)
{
    if (!theSunflower) {
        theSunflower = new Sunflower(scaleX, scaleY);
    }

    theSunflower->loadTextures(seedImagePath, plantImagePath);
    theSunflower->handleEvents(window, event);
    theSunflower->update();
    theSunflower->draw(window);
}

void PlantFactory::displayRepeater(float scaleX, float scaleY,
    const string& seedImagePath, const string& plantImagePath,
    RenderWindow& window, Event& event)
{
    if (!theRepeater) {
        theRepeater = new Repeater(scaleX, scaleY);
    }

    theRepeater->loadTextures(seedImagePath, plantImagePath);
    theRepeater->handleEvents(window, event);
    theRepeater->update();
    theRepeater->draw(window);
}

void PlantFactory::displayWallnut(float scaleX, float scaleY,
    const string& seedImagePath, const string& plantImagePath,
    RenderWindow& window, Event& event)
{
    if (!theWallnut) {
        theWallnut = new Wallnut(scaleX, scaleY);
    }

    theWallnut->loadTextures(seedImagePath, plantImagePath);
    theWallnut->handleEvents(window, event);
    theWallnut->update();
    theWallnut->draw(window);
}

void PlantFactory::displaySnowPea(float scaleX, float scaleY,
    const string& seedImagePath, const string& plantImagePath,
    RenderWindow& window, Event& event)
{
    if (!theSnowPea) {
        theSnowPea = new SnowPea(scaleX, scaleY);
    }

    theSnowPea->loadTextures(seedImagePath, plantImagePath);
    theSnowPea->handleEvents(window, event);
    theSnowPea->update();
    theSnowPea->draw(window);
}