#include "Board/LetterTile.h"

LetterTile::LetterTile() : Tile(sf::Vector2f(0, 128))
{
	ZStack = 10;
	IsDraggable = true;
}
