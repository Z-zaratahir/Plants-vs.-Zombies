//#pragma once
//#include <iostream>
//#include <SFML/Graphics.hpp>
//#include "Coordinate.h"
//#include "Plant.h"
//using namespace sf;
//using namespace std;
//class CherryBomb :public Plant
//{
//public:
//	using Plant::Plant; // Inherit constructor from Plant class
//	void update(int frameCount) {};
//};
//

#pragma once
#include "Plant.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class CherryBomb : public Plant
{
public:

    CherryBomb();

    CherryBomb(float scaleX, float scaleY);
    virtual void loadTextures(const string& seedImagePath, const string& plantImagePath)override;
    void handleEvents(RenderWindow& window, Event& event) override;
    void update() override;
    void draw(RenderWindow& window) override;

};
