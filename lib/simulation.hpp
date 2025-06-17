#pragma once
#include "grid.hpp"
#include <SFML/Graphics.hpp>

class Simulation
{
private:
    Grid grid;
    Grid tempGrid;

public:
    Simulation(int height, int width, int cellSize, int padding = 0)
        : grid(height, width, cellSize, padding),
          tempGrid(height, width, cellSize, padding) { grid.FillRandom(); }

    void Draw(sf::RenderWindow &window);

    int GetValue(int row, int column);
    int CountLiveNeighbors(int row, int column);
    void SetCellValue(int row, int column, int value);

    void Update();
};
