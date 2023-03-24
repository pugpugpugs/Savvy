#include "Tile/NormalTile.h"
#include "Constants.h"

NormalTile::NormalTile()
{
	_startX = 0;
	_startY = 0;
	_spriteSize = 64;
	_scaleRatio = GAME_TILE_SIZE / _spriteSize;
	_scale = sf::Vector2f(_scaleRatio, _scaleRatio);
	_tileMapCoords = sf::Vector2f(_startX, _startY);
}
