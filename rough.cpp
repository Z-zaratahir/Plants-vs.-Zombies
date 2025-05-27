//
////#include <iostream>
////#include <SFML/Graphics.hpp>
////
////using namespace sf;
////using namespace std;
////
////int main()
////{
////    RenderWindow window(VideoMode(800, 600), "Drag and Drop");
////
////    // Load Pea Shooter seed image
////    Texture peaShooterSeedTexture;
////    if (!peaShooterSeedTexture.loadFromFile("Images/Cards/PeaShooter.png"))
////    {
////        cerr << "Failed to load Pea Shooter seed image." << endl;
////        return 1;
////    }
////    Sprite peaShooterSeedSprite(peaShooterSeedTexture);
////    peaShooterSeedSprite.setPosition(700, 50); // Position the seed sprite
////    
////
////
////    // Load Pea Shooter image
////    Texture peaShooterTexture;
////    if (!peaShooterTexture.loadFromFile("Images/Plants/Peashooter/Peashooter_0.png"))
////    {
////        cerr << "Failed to load Pea Shooter image." << endl;
////        return 1;
////    }
////    Sprite peaShooterSprite(peaShooterTexture);
////    peaShooterSprite.setPosition(700, 50); // Initially position the Pea Shooter sprite off-screen
////    //peaShooterSprite.setScale(Vector2f(550, 550));
////
////
////    //setting x and y axes
////    float scaleFactorX = 0.011f;
////    float scaleFactorY = 0.01f;
////
////    peaShooterSprite.setScale(Vector2f(scaleFactorX, scaleFactorY));
////    window.draw(peaShooterSprite);
////    bool isDragging = false;
////    Vector2f offset;
////
////    while (window.isOpen())
////    {
////        Event event;
////        while (window.pollEvent(event))
////        {
////            if (event.type == Event::Closed)
////                window.close();
////            else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
////            {
////                if (peaShooterSeedSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
////                {
////                    isDragging = true;
////                    offset = peaShooterSprite.getPosition() - Vector2f(event.mouseButton.x, event.mouseButton.y);
////                }
////            }
////            else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
////            {
////                if (isDragging)
////                {
////                    // Place Pea Shooter sprite at the dropped position
////                    Vector2i mousePosition = Mouse::getPosition(window);
////                    peaShooterSprite.setPosition(mousePosition.x, mousePosition.y);
////                    //setting x and y axes
////                    scaleFactorX = 1.8f;
////                     scaleFactorY = 2.0f;
////
////                    peaShooterSprite.setScale(Vector2f(scaleFactorX, scaleFactorY));
////                   // window.draw(peaShooterSprite);
////                    isDragging = false; // End dragging
////                }
////            }
////        }
////
////        window.clear();
////        window.draw(peaShooterSeedSprite);
////        window.draw(peaShooterSprite); // Draw the Pea Shooter sprite regardless of dragging state
////        window.display();
////    }
////
////    return 0;
////}
/////////////////////////////////////////////////////////////////////////////////////
////#include <iostream>
////#include <SFML/Graphics.hpp>
////
////using namespace sf;
////using namespace std;
////
////int main()
////{
////    RenderWindow window(VideoMode(800, 600), "Drag and Drop");
////
////    // Load Pea Shooter seed image
////    Texture peaShooterSeedTexture;
////    if (!peaShooterSeedTexture.loadFromFile("Images/Cards/PeaShooter.png"))
////    {
////        cerr << "Failed to load Pea Shooter seed image." << endl;
////        return 1;
////    }
////    Sprite peaShooterSeedSprite(peaShooterSeedTexture);
////    peaShooterSeedSprite.setPosition(70, 50); // Position the seed sprite
////
////    // Load Pea Shooter image
////    Texture peaShooterTexture;
////    if (!peaShooterTexture.loadFromFile("Images/Plants/Peashooter/Peashooter_0.png"))
////    {
////        cerr << "Failed to load Pea Shooter image." << endl;
////        return 1;
////    }
////
////    const int maxPeaShooters = 100;
////    Sprite peaShooterSprites[maxPeaShooters]; // Array to store peaShooterSprite instances
////    int numPeaShooters = 0; // Number of peaShooterSprite instances currently in use
////
////    float scaleFactorX = 1.011f;
////    float scaleFactorY = 1.01f;
////
////    bool isDragging = false;
////    Vector2f offset;
////
////    while (window.isOpen())
////    {
////        Event event;
////        while (window.pollEvent(event))
////        {
////            if (event.type == Event::Closed)
////                window.close();
////            else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
////            {
////                if (peaShooterSeedSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
////                {
////                    if (numPeaShooters < maxPeaShooters) // Check if array limit is not reached
////                    {
////                        // Load new peaShooterSprite instance
////                        peaShooterSprites[numPeaShooters].setTexture(peaShooterTexture);
////                        peaShooterSprites[numPeaShooters].setPosition(event.mouseButton.x, event.mouseButton.y);
////                        peaShooterSprites[numPeaShooters].setScale(Vector2f(scaleFactorX, scaleFactorY));
////                        numPeaShooters++; // Increment the count of peaShooterSprites
////                        isDragging = true;
////                        offset = peaShooterSprites[numPeaShooters - 1].getPosition() - Vector2f(event.mouseButton.x, event.mouseButton.y);
////                    }
////                }
////            }
////            else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
////            {
////                isDragging = false; // End dragging
////            }
////            else if (event.type == Event::MouseMoved && isDragging)
////            {
////                // Update pea shooter sprite position while dragging
////                peaShooterSprites[numPeaShooters - 1].setPosition(Vector2f(event.mouseMove.x, event.mouseMove.y) + offset);
////            }
////        }
////
////        window.clear();
////        window.draw(peaShooterSeedSprite);
////        for (int i = 0; i < numPeaShooters; ++i)
////        {
////            window.draw(peaShooterSprites[i]);
////        }
////        window.display();
////    }
////
////    return 0;
////}
///////////////////////////////////////////////////////////////////////////
////
////#include <iostream>
////
////#include <SFML/Graphics.hpp>
////using namespace sf;
////using namespace std;
////
////int main()
////{
////    RenderWindow window(VideoMode(800, 600), "Drag and Drop");
////
////    // Load Pea Shooter seed image
////    Texture peaShooterSeedTexture;
////    if (!peaShooterSeedTexture.loadFromFile("Images/Cards/PeaShooter.png"))
////    {
////        cerr << "Failed to load Pea Shooter seed image." << endl;
////        return 1;
////    }
////    Sprite peaShooterSeedSprite(peaShooterSeedTexture);
////    peaShooterSeedSprite.setPosition(70, 50); // Position the seed sprite
////
////    // Load Pea Shooter image
////    Texture peaShooterTexture;
////    if (!peaShooterTexture.loadFromFile("Images/Plants/Peashooter/Peashooter_0.png"))
////    {
////        cerr << "Failed to load Pea Shooter image." << endl;
////        return 1;
////    }
////
////    const int maxPeaShooters = 100;
////    Sprite peaShooterSprites[maxPeaShooters]; // Array to store peaShooterSprite instances
////    int numPeaShooters = 0; // Number of peaShooterSprite instances currently in use
////
////    float scaleFactorX = 1.011f;
////    float scaleFactorY = 1.01f;
////
////    bool isDragging = false;
////    Vector2f offset;
////
////    while (window.isOpen())
////    {
////        Event event;
////        while (window.pollEvent(event))
////        {
////            if (event.type == Event::Closed)
////                window.close();
////            else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
////            {
////                if (peaShooterSeedSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
////                {
////                    if (numPeaShooters < maxPeaShooters) // Check if array limit is not reached
////                    {
////                        // Load new peaShooterSprite instance
////                        peaShooterSprites[numPeaShooters].setTexture(peaShooterTexture);
////                        peaShooterSprites[numPeaShooters].setPosition(event.mouseButton.x, event.mouseButton.y);
////                        peaShooterSprites[numPeaShooters].setScale(Vector2f(scaleFactorX, scaleFactorY));
////                        peaShooterSprites[numPeaShooters].setOrigin(peaShooterSprites[numPeaShooters].getLocalBounds().width / 2, peaShooterSprites[numPeaShooters].getLocalBounds().height / 2); // Set origin to center
////                        numPeaShooters++; // Increment the count of peaShooterSprites
////                        isDragging = true;
////                        offset = peaShooterSprites[numPeaShooters - 1].getPosition() - Vector2f(event.mouseButton.x, event.mouseButton.y);
////                    }
////                }
////            }
////            else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
////            {
////                isDragging = false; // End dragging
////            }
////            else if (event.type == Event::MouseMoved && isDragging)
////            {
////                // Update pea shooter sprite position while dragging
////                peaShooterSprites[numPeaShooters - 1].setPosition(Vector2f(event.mouseMove.x, event.mouseMove.y) + offset);
////            }
////        }
////
////        window.clear();
////        window.draw(peaShooterSeedSprite);
////        for (int i = 0; i < numPeaShooters; ++i)
////        {
////            window.draw(peaShooterSprites[i]);
////        }
////        window.display();
////    }
////
////    return 0;
////}
//
//#include <iostream>
//#include <SFML/Graphics.hpp>
//using namespace sf;
//using namespace std;
//
//class Peashooter
//{
//private:
//
//
//    Texture PeaShooterSeedTexture;// setting a texture for the seed
//    Sprite peaShooterSeedSprite;// setting a sprite for the seed
//
//    Texture peaShooterTexture;// setting a texture for the pea shooter
//    const int maxPeaShooters = 100;
//    Sprite peaShooterSprites[100];// setting an array of sprites for the pea shooter
//    int numPeaShooters = 0;
//
//    float scaleFactorX;// width
//    float scaleFactorY;// width
//
//    bool isDragging = false;// check for mouse clicking
//    Vector2f offset;//used as a variable for mouse positioning
//
//public:
//    // Default constructor
//    Peashooter() : offset(0, 0), maxPeaShooters(100), numPeaShooters(0), scaleFactorX(2.0f), scaleFactorY(2.0f) {}
//
//    void loadTextures()//for loading loading textures
//    {
//        if (!PeaShooterSeedTexture.loadFromFile("Images/Cards/PeaShooter.png") ||
//            !peaShooterTexture.loadFromFile("Images/Plants/Peashooter/Peashooter_0.png"))
//        {
//            cerr << "Failed to load textures." << endl;
//            return;
//        }
//
//        peaShooterSeedSprite.setTexture(PeaShooterSeedTexture);
//        peaShooterSeedSprite.setPosition(70, 50);
//    }
//
//    void handleEvents(RenderWindow& window, Event& event)
//    {
//        if (event.type == Event::Closed)
//            window.close();
//        else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
//        {
//            if (peaShooterSeedSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
//            {
//                if (numPeaShooters < maxPeaShooters)//  matching the mouse and position of sprite 
//                {
//                    peaShooterSprites[numPeaShooters].setTexture(peaShooterTexture);
//                    peaShooterSprites[numPeaShooters].setPosition(event.mouseButton.x, event.mouseButton.y);
//                    peaShooterSprites[numPeaShooters].setScale(Vector2f(scaleFactorX, scaleFactorY));
//                    peaShooterSprites[numPeaShooters].setOrigin(peaShooterSprites[numPeaShooters].getLocalBounds().width / 2, peaShooterSprites[numPeaShooters].getLocalBounds().height / 2);
//                    numPeaShooters++;
//                    isDragging = true;
//                    offset = peaShooterSprites[numPeaShooters - 1].getPosition() - Vector2f(event.mouseButton.x, event.mouseButton.y);
//                }
//            }
//        }
//        else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
//        {
//            isDragging = false;// ounf the target 
//
//            // Check if the peaShooterSprite is dropped on the peaShooterSeedSprite
//            for (int i = 0; i < numPeaShooters; ++i)
//            {
//                if (peaShooterSeedSprite.getGlobalBounds().intersects(peaShooterSprites[i].getGlobalBounds()))
//                {
//                    // If collided, remove the peaShooterSprite
//                    for (int j = i; j < numPeaShooters - 1; ++j)
//                    {
//                        peaShooterSprites[j] = peaShooterSprites[j + 1];
//                    }
//                    numPeaShooters--;
//                }
//            }
//        }
//        else if (event.type == Event::MouseMoved && isDragging)//while the sprite is being dragged
//        {
//            peaShooterSprites[numPeaShooters - 1].setPosition(Vector2f(event.mouseMove.x, event.mouseMove.y) + offset);
//        }
//    }
//
//    void update()
//    {//setting the scale of sprites of pea shooters
//        for (int i = 0; i < numPeaShooters; ++i)
//        {
//            peaShooterSprites[i].setScale(Vector2f(scaleFactorX, scaleFactorY));
//        }
//    }
//
//    void draw(RenderWindow& window)
//    {// for drawing the sprites of pea shooter after dropping
//        window.draw(peaShooterSeedSprite);
//        for (int i = 0; i < numPeaShooters; ++i)
//        {
//            window.draw(peaShooterSprites[i]);
//        }
//    }
//};
//
//int main()
//{
//    RenderWindow window(VideoMode(800, 600), "Drag and Drop");
//
//    Peashooter manager;
//    manager.loadTextures();
//
//    while (window.isOpen())
//    {
//        Event event;
//        while (window.pollEvent(event))
//        {
//            manager.handleEvents(window, event);
//        }
//
//        manager.update();
//
//        window.clear();
//        manager.draw(window);
//        window.display();
//    }
//
//    return 0;
//}