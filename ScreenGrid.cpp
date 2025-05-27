#include <iostream>
#include <SFML/Graphics.hpp>
#include "ScreenGrid.h"

using namespace sf;
using namespace std;


ScreenGrid::ScreenGrid()
{
    // Initialize block location array
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            block_location[i][j] = -1; // -1 represents empty
        }
    }

}

void ScreenGrid::setValue(int row, int col, int value)
{
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        block_location[row][col] = value;
    }
}

int ScreenGrid::getValue(int row, int col) const
{
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        return block_location[row][col];
    }
    return 0; // Default value if out of range
}
