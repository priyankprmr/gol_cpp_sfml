#include "grid.hpp"
#include <SFML/Graphics.hpp>

void Grid::Draw(sf::RenderWindow &window)
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            sf::Color color = cells[row][column] ? sf::Color(0, 255, 0, 255) : sf::Color(55, 55, 55, 255);
            sf::RectangleShape cell(sf::Vector2f((cellSize - padding), (cellSize - padding)));
            cell.setPosition(sf::Vector2f(column * cellSize, row * cellSize));
            cell.setFillColor(color);
            cell.setOutlineColor(sf::Color::White);
            window.draw(cell);
        }
    }
}

bool Grid::IsWithinBounds(int row, int column)
{
    if (row >= 0 && row < rows && column >= 0 && column < columns)
    {
        return true;
    }
    return false;
}

int Grid::GetValue(int row, int column)
{
    if (IsWithinBounds(row, column))
    {
        return cells[row][column];
    }
    return 0;
}

void Grid::SetValue(int row, int column, int value)
{
    if (IsWithinBounds(row, column))
    {
        cells[row][column] = value;
    }
}

void Grid::FillRandom()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            SetValue(row, column, (rand() % 2));
        }
    }
}
