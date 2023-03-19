#include "Tile/TileFactory.h"
#include "Tile/NormalTile.h"
#include "Tile/DwTile.h"

std::unique_ptr<BoardTile> TileFactory::CreateBoardTile(TileType type)
{
	switch (type)
	{
	case TileType::Start:
	case TileType::Normal:
		return std::make_unique<NormalTile>();
	case TileType::DW:
		return std::make_unique<DwTile>();
	case TileType::TW:
		//return std::make_unique<TwTile>();
	case TileType::Letter:
		//return std::make_unique<LetterTile>();
	case TileType::DL:
	case TileType::TL:
	default:
		return std::make_unique<NormalTile>();
		break;
	}
}
