#pragma once
#include "Board/BoardTile.h"

class LetterTile : public BoardTile
{
public:
	LetterTile();
	~LetterTile();
	static void Initialize();
	const int GetId();

protected:
	inline static int tileId{ -1 };
};

