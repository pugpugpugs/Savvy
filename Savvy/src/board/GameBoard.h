#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../shared/Enums.h"
#include "BoardTile.h"
#include "BoardTileSettings.h"
#include "NormalBoard.h"

class GameBoard
{
public: 
	std::vector<BoardTile> boardTiles;

private:
	const BoardTileSettings* tileSettings;

public:
	GameBoard(const BoardTileSettings& tileSettings);
	~GameBoard();

	void Initialize(std::vector<sf::Sprite*> boardTileMap, NormalBoard& board);
	void Draw(sf::RenderWindow& window);
};
