#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameBoard.h"
#include "BoardLoader.h"
#include "BoardTiles/NormalTile.h"
#include "BoardTiles/DwTile.h"
#include <BoardTiles/BoardTileFactory.h>
#include <Game/Game.h>
#include <Game/GameRender.h>


int main() 
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Savvy", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	Game game;

	game.Initialize();

	game.Start();

	NormalTile tile;
	NormalTile tile2;

	// add method to get texture by id from render
	

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

		window.clear(sf::Color::Red);

		//for (auto& tile : game.boardTiles)
		//{
		//	tile.Draw(window);
		//}

		//tile.Draw(window);

		GameRender::Draw(window, tile.id);


		window.display();
	}

	return 0;

}

