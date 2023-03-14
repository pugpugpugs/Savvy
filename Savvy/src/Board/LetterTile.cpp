#include "Board/LetterTile.h"
#include <Common/Constants.h>
#include <Game/GameRender.h>

LetterTile::LetterTile()
{
	startX = LETTER_TILE_START_POS_X;
	startY = LETTER_TILE_START_POS_Y;
}

LetterTile::~LetterTile()
{
}

void LetterTile::Initialize()
{
	tileId = GameRender::RegisterTexture(LETTER_TILE_FILEPATH);
}

const int LetterTile::GetId()
{
	return tileId;
}