#pragma once
#include "grid.hpp"
#include <SFML/Graphics.hpp>

class Simulation
{
private:
    Grid grid;
    Grid tempGrid;
    bool run;

public:
    Simulation(int height, int width, int cellSize, int padding = 0)
        : grid(height, width, cellSize, padding),
          tempGrid(height, width, cellSize, padding), run(false) { }

    void Draw(sf::RenderWindow &window);

    int GetValue(int row, int column);
    int CountLiveNeighbors(int row, int column);
    void SetCellValue(int row, int column, int value);

    void Update();

    bool IsRunning() { return run; };
    void Start() { run = true; };
    void Stop() { run = false; };
};
