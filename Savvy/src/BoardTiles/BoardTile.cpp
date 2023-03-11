#include <iostream>
#include "Board/BoardTile.h"
#include "Common/Constants.h"

void BoardTile::SetPosition(float x, float y) 
{
	sprite.setPosition(x, y);
}

void BoardTile::Draw(sf::RenderWindow& window) 
{
	window.draw(sprite);
}


void BoardTile::Init(const sf::Texture& texture)
{
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(NORMAL_TILE_START_POS_X, NORMAL_TILE_START_POS_Y, BOARD_TILE_WIDTH, BOARD_TILE_HEIGHT));
	sprite.setScale(scale);
}