#pragma once
#include "BoardTile.h"
#include "../TileTemplate.h"

class NormalTile : public BoardTile //: public TileTemplate<NormalTile>
{
public:
	NormalTile();
	~NormalTile();
	static void Initialize();
};