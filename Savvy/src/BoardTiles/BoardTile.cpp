#include <iostream>
#include "BoardTiles/BoardTile.h"
#include "Constants.h"

BoardTile::BoardTile()// : scale(BOARD_TILE_PIXEL_SIZE / BOARD_TILE_SPRITE_SIZE, BOARD_TILE_PIXEL_SIZE / BOARD_TILE_SPRITE_SIZE)
{
	//std::cout << "Board constructor" << std::endl;
	//this->multiplier = multiplier;
}

void BoardTile::SetPosition(float x, float y) 
{
	sprite.setPosition(x, y);
}

void BoardTile::Draw(sf::RenderWindow& window) 
{
	window.draw(sprite);
}

BoardTile::~BoardTile() 
{
	//std::cout << "Board destructor" << std::endl;
}

void BoardTile::Init(const sf::Texture& texture)
{
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(NORMAL_TILE_START_POS_X, NORMAL_TILE_START_POS_Y, BOARD_TILE_WIDTH, BOARD_TILE_HEIGHT));
	sprite.setScale(scale);
}
