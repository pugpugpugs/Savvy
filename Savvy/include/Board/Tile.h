#pragma once
#include <SFML/Graphics.hpp>
#include "Game/Drawable.h"

class Tile : public Drawable
{
public:
	Tile(sf::Vector2f(tileMapCoords));
	static void Initialize();
	const int TextureId() override;

private:
	inline static int _tileTextureId { -1 };
};
