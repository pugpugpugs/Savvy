#include <iostream>
#include <SFML/Graphics.hpp>
#include "BoardTile.h"


int main() 
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Game", sf::Style::Default, settings);
	window.setFramerateLimit(250);

	// Init
	BoardTile tile;
	tile.Initialize();

	// Load

	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					window.close();
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		// Update


		// Draw

		window.clear(sf::Color::Red);

		tile.Draw(window);

		window.display();
	}

	return 0;
}