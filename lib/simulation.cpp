#include "simulation.hpp"
#include <SFML/Graphics.hpp>

void Simulation::Draw(sf::RenderWindow &window)
{
    grid.Draw(window);
}

int Simulation::GetValue(int row, int column)
{
    return grid.GetValue(row, column);
}

void Simulation::SetCellValue(int row, int column, int value)
{
    grid.SetValue(row, column, value);
}

int Simulation::CountLiveNeighbors(int row, int column)
{
    int sum = 0;

    std::vector<std::pair<int, int>> neighborOffest =
        {
            {-1, 0},  // Above
            {1, 0},   // Below
            {0, -1},  // Left
            {0, 1},   // Right
            {-1, -1}, // Up-Left
            {-1, 1},  // Up-Right
            {1, -1},  // Down-Left
            {1, 1},   // Down-Right
        };

    for (const auto &offset : neighborOffest)
    {
        int neighborRow = (row + offset.first + grid.GetRows()) % grid.GetRows();
        int neighborColumn = (column + offset.second + grid.GetColumns()) % grid.GetColumns();
        sum += grid.GetValue(neighborRow, neighborColumn);
    }

    return sum;
}

void Simulation::Update()
{
    for (int row = 0; row < grid.GetRows(); row++)
    {
        for (int column = 0; column < grid.GetColumns(); column++)
        {
            int liveNeighbors = CountLiveNeighbors(row, column);
            int cellValue = grid.GetValue(row, column);

            if (cellValue == 0 && liveNeighbors == 3)
            {
                tempGrid.SetValue(row, column, 1);
            }
            else if (cellValue == 1 && (liveNeighbors < 2 || liveNeighbors > 3))
            {
                tempGrid.SetValue(row, column, 0);
            }
            else
            {
                tempGrid.SetValue(row, column, cellValue);
            }
        }
    }

    grid = tempGrid;
}
