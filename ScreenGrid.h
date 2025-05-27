#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

const int ROWS = 5;
const int COLS = 9;

class ScreenGrid
{
private:
    int block_location[ROWS][COLS];

public:
    ScreenGrid();
    void setValue(int row, int col, int value);// Set value at specific row and column
    int getValue(int row, int col) const; // Get value at specific row and column

};

