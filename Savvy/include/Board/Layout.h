#pragma once
#include <Common/Constants.h>

class Layout 
{
public:
	static float OffsetX(int x) 
	{
		return  static_cast<float>(x * BOARD_TILE_WIDTH * (BOARD_TILE_SCALE_SIZE / BOARD_TILE_WIDTH));
	}

	static float OffsetY(int y)
	{
		return   static_cast<float>(y * BOARD_TILE_HEIGHT * (BOARD_TILE_SCALE_SIZE / BOARD_TILE_HEIGHT));
	}
private:
	Layout();
};
