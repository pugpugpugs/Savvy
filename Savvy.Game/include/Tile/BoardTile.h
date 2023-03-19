#pragma once
#include "Tile/LetterTile.h"
#include "Savvy.h"

class BoardTile : public sve::Drawable
{
public:
	BoardTile();
	int CalculateScore();
	LetterTile* letterTile;
	bool IsEmpty();
	static void Initialize();
	const int TextureId() override;
protected:
	int _multiplier = 1;
	static int _tileTextureId;
};

