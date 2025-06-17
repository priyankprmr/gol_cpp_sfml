#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Grid
{
private:
    int rows;
    int columns;
    int cellSize;
    int padding;
    std::vector<std::vector<int>> cells;

public:
    Grid(int height, int width, int cellSize, int padding)
        : rows(height / cellSize),
          columns(width / cellSize),
          cellSize(cellSize),
          padding(padding),
          cells(rows, std::vector(columns, 0)) {}

    int GetRows() { return rows; };
    int GetColumns() { return columns; };

    void Draw(sf::RenderWindow &window);

    bool IsWithinBounds(int row, int column);
    int GetValue(int row, int column);
    void SetValue(int row, int column, int value);

    void FillRandom();
};
