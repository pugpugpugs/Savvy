#include <iostream>
#include "Game/Game.h"
#include "Game/GameRender.h"
#include "State/MainMenuState.h"
#include "State/PlayState.h"
//#include <Board/TileRack.h>

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
		sf::Clock clock;

		PushState(new PlayState(this));

		while (window.isOpen())
		{
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
		}
	}

	//void Game::CreateBoard()
	//{
	//	NormalBoard normalBoard;

	//	int i = 0;
	//	for (int y = 0; y < normalBoard.height; y++)
	//	{
	//		for (int x = 0; x < normalBoard.width; x++)
	//		{
	//			std::unique_ptr<Drawable> object = BoardTileFactory::CreateBoardTile(normalBoard.standardBoardMap[i]);

	//			object->SetPosition(Layout::Offset(x, y));

	//			GameRender::RegisterSprite(std::move(object));
	//			i++;
	//		}
	//	}
	//}

	//void Game::CreateLetters()
	//{
	//	TileRack rack;

	//	for (int i = 0; i < 4; i++)
	//	{
	//		auto letter = BoardTileFactory::CreateBoardTile(Enums::LetterTile);

	//		sf::Vector2f position = rack.rackPositions[i]->Rectangle.getPosition();

	//		letter->SetPosition(position);

	//		GameRender::RegisterSprite(std::move(letter));
	//		i++;
	//	}
	//}

	void Game::Initialize()
	{
		GameRender::Initialize();
		//Tile::Initialize();
		//TileRack::Initialize();

		//CreateBoard();
		//CreateLetters();
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
}
