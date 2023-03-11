#include <iostream>
#include "Board/NormalTile.h"
#include "Common/Constants.h"
#include "Game/GameRender.h"

NormalTile::NormalTile()
{
	startX = NORMAL_TILE_START_POS_X;
	startY = NORMAL_TILE_START_POS_Y;
}

NormalTile::~NormalTile() 
{
}

void NormalTile::Initialize()
{
	tileId = GameRender::RegisterTexture(NORMAL_TILE_FILEPATH);
}

int NormalTile::GetId() 
{
	return tileId;
}