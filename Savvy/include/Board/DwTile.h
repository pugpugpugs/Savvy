#pragma once
#include "Board/BoardTile.h"


class DwTile : public BoardTile
{
public:
	DwTile();
	~DwTile();
	static void Initialize();
	const int GetId();
private:
	inline static int tileId { -1 };
};

