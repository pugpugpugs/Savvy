#include "Tile/LetterTile.h"
#include <stdlib.h>
#include "Constants.h"

int LetterTile::_tileTextureId = -1;

LetterTile::LetterTile()
{
	IsDraggable = true;
	_startX = 0;
	_startY = 128;
	_spriteSize = 64;
	_scaleRatio = GAME_TILE_SIZE / _spriteSize;
	_scale = sf::Vector2f(_scaleRatio, _scaleRatio);
	_tileMapCoords = sf::Vector2f(_startX, _startY);
	ZStack = 1;
}

void LetterTile::Initialize()
{
	_tileTextureId = sve::GameRender::RegisterTexture(TILEMAP_FILEPATH);
}

const int LetterTile::TextureId()
{
	return _tileTextureId;
}



