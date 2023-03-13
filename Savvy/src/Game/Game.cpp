#include <iostream>
#include "Game/Game.h"
#include "Game/GameRender.h"
#include "Board/NormalBoard.h"
#include "Board/BoardTileFactory.h"
#include "Board/Layout.h"
#include "Board/NormalTile.h"
#include "Board/DwTile.h"

Game::Game()
{
}

void Game::Start()
{
	CreateBoard();
	CreateLetters();
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

void Game::CreateLetters()
{
	auto letter = std::make_unique<LetterTile>();

	letter->SetPosition(Layout::LetterOffsetX(0), Layout::LetterOffsetY(0));

	letterTiles.push_back(std::move(letter));

	GameRender::RegisterLetterSprite(*letterTiles.back());
}

void Game::Initialize() 
{
	GameRender::Initialize();
	NormalTile::Initialize();
	DwTile::Initialize();
	LetterTile::Initialize();
}

//void Game::HandleClickEvent(sf::Mouse& mouse, sf::RenderWindow& window)
//{
//	GameRender::HandleClickEvent(mouse, window);
//}
