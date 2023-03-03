#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../Enums.h"
#include "BoardTile.h"

class GameBoard
{
public: 
	int standardBoardMap[25] = { 
		BoardTileType::TWTile,  BoardTileType::NormalTile, BoardTileType::DWTile, BoardTileType::NormalTile, BoardTileType::TWTile,
		BoardTileType::NormalTile,  BoardTileType::DLTile, BoardTileType::NormalTile, BoardTileType::DLTile, BoardTileType::NormalTile,
		BoardTileType::TLTile,  BoardTileType::NormalTile, BoardTileType::StartTile, BoardTileType::NormalTile, BoardTileType::TLTile,
		BoardTileType::NormalTile,  BoardTileType::DLTile, BoardTileType::NormalTile, BoardTileType::DLTile, BoardTileType::NormalTile,
		BoardTileType::TWTile,  BoardTileType::NormalTile, BoardTileType::DWTile, BoardTileType::NormalTile, BoardTileType::TWTile
	};

	std::vector<BoardTile> boardTiles;

public:
	GameBoard();
	~GameBoard();

	void Initialize(std::vector<sf::Sprite*> boardTileMap);
	void Draw(sf::RenderWindow& window);
};

