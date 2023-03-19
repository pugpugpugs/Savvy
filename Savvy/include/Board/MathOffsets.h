#pragma once
#include <Common/Constants.h>
#include <SFML/System.hpp>

namespace sve
{
	class MathOffsets
	{
	public:
		static float OffsetX(int x)
		{
			return  static_cast<float>(x * TILEMAP_SPRITE_SIZE * (GAME_TILE_SIZE / TILEMAP_SPRITE_SIZE));
		}

		static float OffsetY(int y)
		{
			return   static_cast<float>(y * TILEMAP_SPRITE_SIZE * (GAME_TILE_SIZE / TILEMAP_SPRITE_SIZE));
		}

		static sf::Vector2f Offset(float x, float y)
		{
			return sf::Vector2f(OffsetX(x), OffsetY(y));
		}
	private:
		MathOffsets();
	};
}
