//#include "GameBoard.h"
//
//GameBoard::GameBoard(const BoardTileSettings& tileSettings)
//{
//	this->tileSettings = &tileSettings;
//}
//
//void GameBoard::Initialize(std::vector<sf::Sprite*> boardTileMap, NormalBoard& board)
//{
//	int positionX = 0;
//	int positionY = 0;
//
//	for (size_t y = 0; y < 5; y++)
//	{
//		for (size_t x = 0; x < 5; x++)
//		{
//			int index = x + y * 5;
//
//			BoardTile boardTile;
//			boardTiles.push_back(boardTile);
//			boardTiles[index].sprite = *boardTileMap[board.standardBoardMap[index]];
//
//			boardTiles[index].sprite.setPosition(positionX, positionY);
//
//			positionX += tileSettings->offset.x;
//		}
//		positionX = 0;
//		positionY += (tileSettings->worldUnitPixelAmount / tileSettings->texturePixelSize) * tileSettings->height;
//	}
//}
//
//void GameBoard::Draw(sf::RenderWindow& window)
//{
//	for (auto &element : boardTiles) 
//	{
//		window.draw(element.sprite);
//	}
//}
