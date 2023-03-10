#include <iostream>
#include "BoardTiles/NormalTile.h"
#include "Constants.h"
#include "Game/GameRender.h"

NormalTile::NormalTile() //: BoardTile(NORMAL_TILE_MULTIPLIER) 
{
	//std::cout << "Normal constructor" << std::endl;
	//if (!(*texture).loadFromFile(NORMAL_TILE_FILEPATH))
	//{
	//	std::cout << "Could not load " << NORMAL_TILE_FILEPATH << std::endl;
	//}

	//sprite.setTexture(*texture);
	//sprite.setTextureRect(sf::IntRect(NORMAL_TILE_START_POS_X, NORMAL_TILE_START_POS_Y, BOARD_TILE_WIDTH, BOARD_TILE_HEIGHT));
	//sprite.setScale(scale);

	GameRender::RegisterSprite(sprite, id);
}

NormalTile::~NormalTile() 
{
	//std::cout << "Normal destructor" << std::endl;
}

void NormalTile::Initialize()
{
	id = GameRender::RegisterTexture(NORMAL_TILE_FILEPATH);
}