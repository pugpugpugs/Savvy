#include "Tile/DwTile.h"
#include "Constants.h"

DwTile::DwTile()
{
	_multiplier = 2;
	_startX = 64;
	_startY = 0;
	_spriteSize = 64;
	_scaleRatio = GAME_TILE_SIZE / _spriteSize;
	_scale = sf::Vector2f(_scaleRatio, _scaleRatio);
	_tileMapCoords = sf::Vector2f(_startX, _startY);
}
