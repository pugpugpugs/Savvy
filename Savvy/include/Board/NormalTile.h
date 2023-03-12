#pragma once
#include "BoardTile.h"

class NormalTile : public BoardTile
{
public:
	NormalTile();
	~NormalTile();
	static void Initialize();
	const int GetId();
private:
	inline static int tileId{ -1 };
};