#include "Tile/BoardTile.h"
#include "Constants.h"
#include "Savvy.h"

int BoardTile::_tileTextureId = -1;

BoardTile::BoardTile() : letterTile(nullptr)
{
	CanDropOn = true;
}

int BoardTile::CalculateScore()
{
	return _multiplier;
}

bool BoardTile::IsEmpty()
{
	return letterTile == nullptr;
}

void BoardTile::Initialize()
{
	_tileTextureId = sve::GameRender::RegisterTexture(TILEMAP_FILEPATH);
}

const int BoardTile::TextureId()
{
	return _tileTextureId;
}