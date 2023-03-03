#include "GameBoard.h"


GameBoard::GameBoard()
{
}

GameBoard::~GameBoard()
{
}

void GameBoard::Initialize(std::vector<sf::Sprite*> boardTileMap)
{
	int positionX = 0;
	int positionY = 0;

	for (size_t y = 0; y < 5; y++)
	{
		for (size_t x = 0; x < 5; x++)
		{
			int index = x + y * 5;

			BoardTile boardTile;
			boardTiles.push_back(boardTile);
			boardTiles[index].sprite = *boardTileMap[standardBoardMap[index]];

			boardTiles[index].sprite.setPosition(positionX, positionY);

			// world unit / pixel size * width - need to change later to variables 
			positionX += (64 / 10) * 14;
		}
		positionX = 0;
		positionY += (64 / 10) * 14;
	}
}

void GameBoard::Draw(sf::RenderWindow& window)
{
	for (auto &element : boardTiles) 
	{
		window.draw(element.sprite);
	}
}
