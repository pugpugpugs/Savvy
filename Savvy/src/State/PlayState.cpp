#include "State/PlayState.h"
#include <Game/GameRender.h>

PlayState::PlayState(Game* game)
{
	this->game = game;
}

void PlayState::Draw(const float elapsedSeconds)
{
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
		switch (event.type)
		{
		case sf::Event::Closed:
			game->window.close();
		default:
			_handler.HandleEvent(event, game->window);
			break;
		}
	}
}
