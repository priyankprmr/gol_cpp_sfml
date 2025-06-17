#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <vector>
#include <iostream>

#include "simulation.hpp"

/**
 * John conway's game of life
 * Rules:
 *  A live cell dies if it has fewer than two live neighbors.
 *  A live cell with two or three live neighbors lives on to the next generation.
 *  A live cell with more than three live neighbors dies.
 *  A dead cell will be brought back to live if it has exactly three live neighbors.
 */

int main()
{
    const sf::Color Grey(29, 29, 29, 255);

    const int WINDOW_HEIGHT = 600;
    const int WINDOW_WIDTH = 800;
    const int FPS = 12;

    const int CELL_SIZE = 10;
    const int CELL_PADDING = 1;

    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Game Of Life");
    window.setFramerateLimit(FPS);

    Simulation simulation(WINDOW_HEIGHT, WINDOW_WIDTH, CELL_SIZE);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {

            if (event->is<sf::Event::Closed>())
                window.close();

            if (event->is<sf::Event::KeyPressed>())
            {
                // Event handling
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
                {
                    if (simulation.IsRunning())
                    {
                        simulation.Stop();
                    }
                    else
                    {
                        simulation.Start();
                    }
                }
            }
        }

        // Update
        simulation.Update();

        // Draw and show
        window.clear(Grey);
        simulation.Draw(window);
        window.display();
    }

    return 0;
}
