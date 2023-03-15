#pragma once
#include <Board/Tile.h>
#include <Common/Enums.h>

class BoardTileFactory
{
public:
	static std::unique_ptr<Drawable> CreateBoardTile(Enums::BoardTileType type);
	BoardTileFactory();
	~BoardTileFactory();
};
