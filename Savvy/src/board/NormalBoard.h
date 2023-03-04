#pragma once
#include "../shared/Enums.h"

struct NormalBoard
{
	const int standardBoardMap[25] = {
		BoardTileType::TWTile,  BoardTileType::NormalTile, BoardTileType::DWTile, BoardTileType::NormalTile, BoardTileType::TWTile,
		BoardTileType::NormalTile,  BoardTileType::DLTile, BoardTileType::NormalTile, BoardTileType::DLTile, BoardTileType::NormalTile,
		BoardTileType::TLTile,  BoardTileType::NormalTile, BoardTileType::StartTile, BoardTileType::NormalTile, BoardTileType::TLTile,
		BoardTileType::NormalTile,  BoardTileType::DLTile, BoardTileType::NormalTile, BoardTileType::DLTile, BoardTileType::NormalTile,
		BoardTileType::TWTile,  BoardTileType::NormalTile, BoardTileType::DWTile, BoardTileType::NormalTile, BoardTileType::TWTile
	};

	const int width = 5;
	const int height = 5;
};