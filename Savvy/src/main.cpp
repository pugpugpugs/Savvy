#include <iostream>
#include <SFML/Graphics.hpp>
#include <Game/Game.h>
#include <Game/GameRender.h>
#include <Board/NormalTile.h>
#include <Board/BoardTileFactory.h>
#include <Common/Enums.h>
#include <Board/Layout.h>


int main() 
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Savvy", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	Game game;

	game.Initialize();

	game.Start();

	// Load

	sf::Event event;
	sf::Vector2f mousePosition;
	bool isMouseClick = false;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					game.boardTiles[0].release();
					game.boardTiles[0] = BoardTileFactory::CreateBoardTile(Enums::NormalTile);
					game.boardTiles[0]->SetPosition(Layout::OffsetX(0), Layout::OffsetY(0));
					GameRender::UpdateSprite(*game.boardTiles[0]);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					window.close();
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				isMouseClick = true;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				{
					std::cout << "Click " << std::endl;
					mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
					GameRender::HandleClickEvent(mousePosition, window);
				}
				break;
			case sf::Event::MouseButtonReleased:
				isMouseClick = false;
				GameRender::activeSprite = nullptr;
				std::cout << "Release " << std::endl;
				break;
			default:
				if (isMouseClick)
				{
					GameRender::HandleClickEvent(mousePosition, window);
				}
				break;
			}
		}

		window.clear(sf::Color::Black);

		GameRender::Draw(window);

		window.display();
	}

	return 0;

}

