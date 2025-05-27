#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace sf;
using namespace std;


class Leaderboard {
private:
    RenderWindow& m_Window;
    Font m_Font;

public:
    Leaderboard(RenderWindow& window, Font& font) : m_Window(window), m_Font(font) {}

    void display() {
        ifstream leaderboardFile("Scores/highscores.txt");

        Texture backgroundTexture;
        backgroundTexture.loadFromFile("Images/score.png");
        Sprite backgroundSprite(backgroundTexture);

        Text titleText("Leaderboard", m_Font, 80);
        titleText.setFillColor(Color::White);
        titleText.setPosition(770, 70);

        Text leaderboardText("", m_Font, 60);
        leaderboardText.setFillColor(Color::Black);
        leaderboardText.setPosition(730, 290);

        string leaderboardContent;
        string line;
        int rank = 1;
        const int nameWidth = 20;
        const int scoreWidth = 8;

        while (getline(leaderboardFile, line)) {
            stringstream ss(line);
            string name;
            int score;
            if (!(ss >> name >> score)) {
                // Failed to read name and score, possibly an empty line
                break;
            }
            //ss >> name >> score;

            string paddedName = name + string(nameWidth - name.length(), ' ');
            string paddedScore = to_string(score) + string(scoreWidth - to_string(score).length(), ' ');

            leaderboardContent += paddedName + paddedScore + "\n";
            rank++;
        }

        leaderboardFile.close();

        leaderboardText.setString(leaderboardContent);

        m_Window.clear(Color::White);
        m_Window.draw(backgroundSprite);
        m_Window.draw(titleText);
        m_Window.draw(leaderboardText);
        m_Window.display();
    }
};















//class Leaderboard {
//private:
//    RenderWindow& m_Window;
//    Font m_Font;
//
//public:
//    Leaderboard(RenderWindow& window, Font& font) : m_Window(window), m_Font(font) {}
//
//    void display() {
//        ifstream leaderboardFile("Scores/highscores.txt");
//
//        Texture backgroundTexture;
//        backgroundTexture.loadFromFile("Images/scoreBG.png");
//        Sprite backgroundSprite(backgroundTexture);
//
//        Text titleText("Leaderboard", m_Font, 60);
//        titleText.setFillColor(Color::Black);
//        titleText.setPosition(350, 50);
//
//        Text leaderboardText("", m_Font, 30);
//        leaderboardText.setFillColor(Color::Black);
//        leaderboardText.setPosition(150, 150);
//
//        string leaderboardContent;
//        string line;
//        int rank = 1;
//
//        while (getline(leaderboardFile, line)) {
//            stringstream ss(line);
//            string name;
//            int level, lives, score;
//            ss >> name >> level >> lives >> score;
//            leaderboardContent += to_string(rank) + ". " + name + " - Level: " + to_string(level) + " - Lives: " + to_string(lives) + " - Score: " + to_string(score) + "\n";
//            rank++;
//        }
//
//        leaderboardFile.close();
//
//        leaderboardText.setString(leaderboardContent);
//
//        m_Window.clear(Color::White);
//        m_Window.draw(backgroundSprite);
//        m_Window.draw(titleText);
//        m_Window.draw(leaderboardText);
//        m_Window.display();
//    }
//
//
//    void renderHighScoreScreen() {
//        // Clear the window
//        m_Window.clear();
//
//        // Display your high score screen here
//        // You can draw text, images, buttons, etc. to represent your high score screen
//        // Example: Drawing text
//        sf::Text highScoreText("High Scores", m_Font, 48);
//        highScoreText.setPosition(100, 100);
//        m_Window.draw(highScoreText);
//
//        // Display the window contents
//        m_Window.display();
//    }
//};