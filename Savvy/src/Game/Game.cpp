#include "Game/Game.h"
#include <BoardTiles/BoardTileFactory.h>
#include <iostream>
#include <Constants.h>
#include <Layout.h>
#include <Game/GameRender.h>
#include <BoardTiles/NormalTile.h>
#include <NormalBoard.h>

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
	BoardTileFactory factory;

	int i = 0;
	for (int y = 0; y < normalBoard.height; y++) 
	{
		for (int x = 0; x < normalBoard.width; x++)
		{
			auto t = factory.CreateBoardTile(normalBoard.standardBoardMap[i]);

			boardTiles.push_back(*t);

			//boardTiles[i].count = i;

			boardTiles[i].SetPosition(Layout::OffsetX(x), Layout::OffsetY(y));

			GameRender::RegisterSprite(boardTiles[i].sprite, boardTiles[i].id);
			i++;

		}
	}
}

void Game::Initialize() 
{
	GameRender::Initialize();
	NormalTile::Initialize();
}
