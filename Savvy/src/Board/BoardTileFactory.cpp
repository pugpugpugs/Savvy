#include "Board/BoardTileFactory.h"
#include "Board/NormalTile.h"
#include "Common/Enums.h"
#include <iostream>
#include <Board/DwTile.h>
#include <Board/TwTile.h>
#include <Board/LetterTile.h>

std::unique_ptr<Drawable> BoardTileFactory::CreateBoardTile(Enums::BoardTileType type)
{
	switch (type)
	{
	case Enums::StartTile:
	case Enums::NormalTile:
		return std::make_unique<NormalTile>();
	case Enums::DWTile:
		return std::make_unique<DwTile>();
	case Enums::TWTile:
		return std::make_unique<TwTile>();
	case Enums::LetterTile:
		return std::make_unique<LetterTile>();
	case Enums::DLTile:
	case Enums::TLTile:
	default:
		return std::make_unique<NormalTile>();
		break;
	}
}

BoardTileFactory::BoardTileFactory() 
{
}

BoardTileFactory::~BoardTileFactory()
{
}

