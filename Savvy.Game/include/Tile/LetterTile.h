#pragma once
#include "Savvy.h"
#include <string>
#include <memory>
#include <vector>

class LetterTile : public sve::Drawable
{
public:
	std::string Letter;
	int Points = 0;

	LetterTile();
	static void Initialize();
	const int TextureId() override;
protected:
	static int _tileTextureId;
};

