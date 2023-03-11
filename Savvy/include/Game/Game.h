#pragma once
#include <Board/BoardTile.h>

class Game
{
public:
	Game();
	void Start();
	void Initialize();

	std::vector<std::unique_ptr<BoardTile>> boardTiles;

private:
	void CreateBoard();
};

