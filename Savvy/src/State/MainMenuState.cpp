#include "State/MainMenuState.h"
#include "State/PlayState.h"
#include <iostream>

namespace sve
{
	MainMenuState::MainMenuState(Game* game)
	{
		this->game = game;
	}

	void MainMenuState::Draw(const float elapsedSeconds)
	{
		sf::RectangleShape rect;
		rect.setPosition(sf::Vector2f(100, 100));
		rect.setSize(sf::Vector2f(100, 100));
		rect.setFillColor(sf::Color::Green);

		game->window.draw(rect);
	}

	void MainMenuState::Update(const float elapsedSeconds)
	{
	}

	void MainMenuState::Handle()
	{
		sf::Event event;

		while (game->window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				game->window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					game->window.close();
				}
				else if (event.key.code == sf::Keyboard::Return)
				{
					LoadGame();
				}
				break;
			default:
				break;
			}
		}
	}

	void MainMenuState::LoadGame()
	{
		game->PushState(new PlayState(game));
	}
}
