#include <iostream>
#include "Game/Game.h"
#include "Game/GameRender.h"
#include "Board/NormalBoard.h"
#include "Board/BoardTileFactory.h"
#include "Board/Layout.h"
#include "Board/NormalTile.h"
#include "Board/DwTile.h"
#include "Event/EventHandler.h"
#include "State/MainMenuState.h"
#include "State/PlayState.h"

Game::Game()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	window.create(sf::VideoMode(1600, 900), "Savvy", sf::Style::Default, settings);
	window.setFramerateLimit(60);
	PushState(new PlayState(this));
}

void Game::Start()
{
	sf::Clock clock;

	sf::Event event;
	EventHandler handler;

	while (window.isOpen())
	{
		float elapsedSeconds = clock.restart().asSeconds();

		if (CurrentState() == nullptr)
		{
			std::cout << "Null ptr state" << std::endl;
			continue;
		}

		CurrentState()->Handle();

		CurrentState()->Update(elapsedSeconds);


		//while (window.pollEvent(event))
		//{
		//	handler.HandleEvent(event, window);
		//}

		//window.clear(sf::Color::Black);

		//GameRender::Draw(window);

		//window.display();

		window.clear(sf::Color::Black);

		CurrentState()->Draw(elapsedSeconds);

		window.display();
	}
}

void Game::CreateBoard()
{
	NormalBoard normalBoard;

	int i = 0;
	for (int y = 0; y < normalBoard.height; y++) 
	{
		for (int x = 0; x < normalBoard.width; x++)
		{
			auto t = BoardTileFactory::CreateBoardTile(normalBoard.standardBoardMap[i]);

			BoardTiles.push_back(std::move(t));

			BoardTiles[i]->SetPosition(Layout::OffsetX(x), Layout::OffsetY(y));

			GameRender::RegisterSprite(*BoardTiles[i]);
			i++;
		}
	}
}

void Game::CreateLetters()
{
	auto letter = std::make_unique<LetterTile>();

	letter->SetPosition(Layout::LetterOffsetX(0), Layout::LetterOffsetY(0));

	LetterTiles.push_back(std::move(letter));

	GameRender::RegisterLetterSprite(*LetterTiles.back());
}

void Game::Initialize() 
{
	GameRender::Initialize();
	NormalTile::Initialize();
	DwTile::Initialize();
	LetterTile::Initialize();

	CreateBoard();
	CreateLetters();
}

void Game::PushState(GameState* state)
{
	_states.push_back(state);
}

void Game::PopState()
{
	_states.back();
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

//void Game::HandleClickEvent(sf::Mouse& mouse, sf::RenderWindow& window)
//{
//	GameRender::HandleClickEvent(mouse, window);
//}
