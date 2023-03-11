#pragma once
#include <Board/BoardTile.h>
#include <Common/Enums.h>

class BoardTileFactory
{
public:
	static std::unique_ptr<BoardTile> CreateBoardTile(Enums::BoardTileType type);
	BoardTileFactory();
	~BoardTileFactory();
};
