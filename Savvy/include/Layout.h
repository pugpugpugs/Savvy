#pragma once
#include "Constants.h"

static struct Layout 
{
	static float OffsetX(int x) 
	{
		return  static_cast<float>(x * BOARD_TILE_WIDTH * (BOARD_TILE_PIXEL_SIZE / BOARD_TILE_WIDTH));
	}

	static float OffsetY(int y)
	{
		return   static_cast<float>(y * BOARD_TILE_HEIGHT * (BOARD_TILE_PIXEL_SIZE / BOARD_TILE_HEIGHT));
	}
};
