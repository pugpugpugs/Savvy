#include <iostream>
#include "Game/Game.h"
#include "Game/GameRender.h"
#include "State/MainMenuState.h"
#include "State/PlayState.h"

namespace sve
{
	Game::Game()
	{
		CreateWindow();
		Initialize();
	}

	void Game::CreateWindow()
	{
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;
		window.create(sf::VideoMode(1600, 900), "Savvy", sf::Style::Default, settings);
		window.setFramerateLimit(60);
	}

	void Game::Start()
	{
		//while (window.isOpen())
		//{
		float elapsedSeconds = clock.restart().asSeconds();

		if (CurrentState() == nullptr)
		{
			throw std::invalid_argument("Current state cannot be null.");
		}

		CurrentState()->Handle();

		CurrentState()->Update(elapsedSeconds);

		window.clear(sf::Color::Black);

		CurrentState()->Draw(elapsedSeconds);

		window.display();
		//}
	}

	void Game::Initialize()
	{
		GameRender::Initialize();

		PushState(new PlayState(this));
	}

	void Game::PushState(GameState* state)
	{
		_states.push_back(state);
	}

	void Game::PopState()
	{
		delete _states.back();
		_states.pop_back();
	}

	GameState* Game::CurrentState()
	{
		if (_states.empty())
		{
			return nullptr;
		}
		return _states.back();
	}

	std::string Game::GetState()
	{
		return _states.back()->GetState();
	}
}
