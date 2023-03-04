#include <iostream>
#include <SFML/Graphics.hpp>
#include "board/BoardLoader.h"
#include "board/GameBoard.h"
#include "board/BoardTileSettings.h"


int main() 
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Savvy", sf::Style::Default, settings);
	window.setFramerateLimit(250);

	// Init
	const BoardTileSettings tileSettings;
	BoardLoader boardLoader(tileSettings);
	boardLoader.Initialize();

	NormalBoard boardType;
	GameBoard board(tileSettings);
	board.Initialize(boardLoader.boardTileMap, boardType);

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

		//boardLoader.Draw(window);

		board.Draw(window);

		window.display();
	}

	return 0;
}