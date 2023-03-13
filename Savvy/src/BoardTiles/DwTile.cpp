#include <iostream>
#include "Board/DwTile.h"
#include "Common/Constants.h"
#include "Game/GameRender.h"

DwTile::DwTile()
{
	startX = DW_TILE_START_POS_X;
	startY = DW_TILE_START_POS_Y;
}

DwTile::~DwTile()
{
}

void DwTile::Initialize()
{
	tileId = GameRender::RegisterTexture(DW_TILE_FILEPATH);
}

const int DwTile::GetId() 
{
	return tileId;
}