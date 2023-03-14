#include <iostream>
#include "Board/TwTile.h"
#include "Common/Constants.h"
#include "Game/GameRender.h"

TwTile::TwTile()
{
	startX = TW_TILE_START_POS_X;
	startY = TW_TILE_START_POS_Y;
}

TwTile::~TwTile()
{
}

void TwTile::Initialize()
{
	tileId = GameRender::RegisterTexture(TW_TILE_FILEPATH);
}

const int TwTile::GetId()
{
	return tileId;
}