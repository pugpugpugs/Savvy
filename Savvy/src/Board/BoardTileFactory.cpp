#include "Board/BoardTileFactory.h"
#include "Board/NormalTile.h"
#include "Common/Enums.h"
#include <iostream>
#include <Board/DwTile.h>
#include <Board/TwTile.h>

std::unique_ptr<BoardTile> BoardTileFactory::CreateBoardTile(Enums::BoardTileType type)
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
	case Enums::DLTile:
	case Enums::TLTile:
	default:
		std::unique_ptr<BoardTile> test = std::make_unique<NormalTile>();
		return test;
		break;
	}
}

BoardTileFactory::BoardTileFactory() 
{
}

BoardTileFactory::~BoardTileFactory()
{
}

