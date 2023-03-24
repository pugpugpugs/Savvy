#pragma once

enum class TileType
{
	Start,
	Normal,
	TW,
	DW,
	DL,
	TL,
	Letter
};

struct NormalBoard
{
	const TileType standardBoardMap[25] = {
		TileType::TW,  TileType::Normal, TileType::DW, TileType::Normal, TileType::TW,
		TileType::Normal,  TileType::Normal, TileType::Normal, TileType::Normal, TileType::Normal,
		TileType::DW,  TileType::Normal, TileType::DW, TileType::Normal, TileType::DW,
		TileType::Normal,  TileType::Normal, TileType::Normal, TileType::Normal, TileType::Normal,
		TileType::TW,  TileType::Normal, TileType::DW, TileType::Normal, TileType::TW
	};

	const int width = 5;
	const int height = 5;
};