#include "Game/Game.h"
#include <iostream>
#include <Game/GameRender.h>
#include <Board/NormalBoard.h>
#include <Board/BoardTileFactory.h>
#include <Board/Layout.h>
#include <Board/NormalTile.h>
#include <Board/DwTile.h>

Game::Game()
{
}

void Game::Start()
{
	CreateBoard();
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

			boardTiles.push_back(std::move(t));

			boardTiles[i]->SetPosition(Layout::OffsetX(x), Layout::OffsetY(y));

			GameRender::RegisterSprite(*boardTiles[i]);
			i++;
		}
	}
}

void Game::Initialize() 
{
	GameRender::Initialize();
	NormalTile::Initialize();
	DwTile::Initialize();
}

//void Game::HandleClickEvent(sf::Mouse& mouse, sf::RenderWindow& window)
//{
//	GameRender::HandleClickEvent(mouse, window);
//}
