#pragma once
#include <iostream>
#include <memory>
#include "Tile/BoardTile.h"
#include "Board/BoardLayout.h"

class TileFactory
{
public:
	static std::unique_ptr<BoardTile> CreateBoardTile(TileType type);
};
