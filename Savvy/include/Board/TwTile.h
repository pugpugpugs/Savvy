#pragma once
#include "Board/BoardTile.h"

class TwTile : public BoardTile
{
public:
	TwTile();
	~TwTile();
	static void Initialize();
	const int GetId();
private:
	inline static int tileId{ -1 };
};


