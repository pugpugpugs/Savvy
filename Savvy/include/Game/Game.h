#pragma once
#include <BoardTiles/BoardTile.h>

class Game
{
public:
	Game();
	void Start();
	void Initialize();

	std::vector<BoardTile> boardTiles;

private:
	void CreateBoard();
};

