#pragma once
#include <BoardTiles/BoardTile.h>
#include <Enums.h>

class BoardTileFactory
{
public:
	//BoardTile* CreateBoardTile(Enums::BoardTileType type);
	std::unique_ptr<BoardTile> CreateBoardTile(Enums::BoardTileType type);
	BoardTileFactory();
	~BoardTileFactory();
};
