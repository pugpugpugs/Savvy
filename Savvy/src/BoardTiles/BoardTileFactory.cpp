#include "BoardTiles/BoardTileFactory.h"
#include "BoardTiles/NormalTile.h"
#include <iostream>

//BoardTile* BoardTileFactory::CreateBoardTile(Enums::BoardTileType type)
std::unique_ptr<BoardTile> BoardTileFactory::CreateBoardTile(Enums::BoardTileType type)
{
	//NormalTile* tile;
	std::unique_ptr<BoardTile> ptr;

	switch (type)
	{
	case Enums::StartTile:
	case Enums::NormalTile:
	case Enums::DWTile:
	case Enums::TWTile:
	case Enums::DLTile:
	case Enums::TLTile:
	default:
		std::unique_ptr<BoardTile> test = std::make_unique<NormalTile>();
		return test;
		//return ptr.reset(new NormalTile());
		//return new NormalTile();
		break;
	}
}

BoardTileFactory::BoardTileFactory() 
{
	//std::cout << "Factory created" << std::endl;
}

BoardTileFactory::~BoardTileFactory()
{
	//std::cout << "Factory destroyed" << std::endl;
}

