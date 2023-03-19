#pragma once
#include <vector>
#include <memory>
#include "Tile/LetterTile.h"

class TileRack
{
public:
	TileRack();
	std::vector<std::unique_ptr<LetterTile>> RackTiles;
};

