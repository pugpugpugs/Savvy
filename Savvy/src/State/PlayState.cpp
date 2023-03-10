#include "State/PlayState.h"
#include <Game/GameRender.h>

PlayState::PlayState(Game* game)
{
	this->game = game;
}

void PlayState::Draw(const float elapsedSeconds)
{
	//while (game->window.pollEvent(event))
	//{
	//	switch (event.type)
	//	{
	//	case sf::Event::Closed:
	//		game->window.close();
	//		break;
	//	case sf::Event::KeyPressed:
	//		if (event.key.code == sf::Keyboard::Escape)
	//		{
	//			game->window.close();
	//		}
	//		else if (event.key.code == sf::Keyboard::Return)
	//		{
	//		}
	//		break;
	//	default:
	//		break;
	//	}
	//}
	GameRender::Draw(game->window);
}

void PlayState::Update(const float elapsedSeconds)
{
}

void PlayState::Handle()
{
	sf::Event event;

	while (game->window.pollEvent(event))
	{
		_handler.HandleEvent(event, game->window);
	}
}
