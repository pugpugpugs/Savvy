#include <iostream>
#include "Board/Tile.h"
#include "Common/Constants.h"
#include <Game/GameRender.h>

Tile::Tile(sf::Vector2f(tileMapCoords))
{
	_spriteSize = TILEMAP_SPRITE_SIZE;
	_scaleRatio = GAME_TILE_SIZE / _spriteSize;
	_scale = sf::Vector2f(_scaleRatio, _scaleRatio);
	_tileMapCoords = tileMapCoords;
	_startX = tileMapCoords.x;
	_startY = tileMapCoords.y;
}

void Tile::Initialize()
{
	_tileTextureId = GameRender::RegisterTexture(TILEMAP_FILEPATH);
}

const int Tile::TextureId()
{
	return _tileTextureId;
}
