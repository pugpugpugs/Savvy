#include "BoardTile.h"
#include <iostream>

#define NORMAL_TILE_FILEPATH "assets\\brown.png"
#define DW_TILE_FILEPATH "assets\\red.png"
#define TW_TILE_FILEPATH "assets\\silver.png"
#define DL_TILE_FILEPATH "assets\\green.png"
#define TL_TILE_FILEPATH "assets\\darkgreen.png"

BoardTile::BoardTile() : textureSize(10, 10), ratio(64, 64), worldUnits(1, 1),
						 pixelSize(ratio.x* worldUnits.x, ratio.y* worldUnits.y),
						 scale((pixelSize.x / textureSize.x) * textureSize.x, (pixelSize.y / textureSize.y)* textureSize.y)
{
	//sf::Vector2f textureSize(10, 10);
	//sf::Vector2f ratio(64, 64);
	//sf::Vector2f worldUnits(1, 1);
	//sf::Vector2f pixelSize(ratio.x * worldUnits.x, ratio.y * worldUnits.y);
}

BoardTile::~BoardTile()
{
}

void BoardTile::Initialize()
{
	Load(plainTileTexture, plainTileSprite, NORMAL_TILE_FILEPATH);
	Load(dwTileTexture, dwTileSprite, DW_TILE_FILEPATH);
	Load(twTileTexture, twTileSprite, TW_TILE_FILEPATH);
	Load(dlTileTexture, dlTileSprite, DL_TILE_FILEPATH);
	Load(tlTileTexture, tlTileSprite, TL_TILE_FILEPATH);
}

void BoardTile::Load(sf::Texture& texture, sf::Sprite& sprite, std::string path)
{
	if (texture.loadFromFile(path))
	{
		std::cout << "Loaded " << path << std::endl;

		int height = 14;
		int width = 14;

		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(1, 1, width, height));
		//sprite.setScale(pixelSize.x / textureSize.x, pixelSize.y / textureSize.y);
		sprite.setScale(pixelSize.x / textureSize.x, pixelSize.y / textureSize.y);
		sprite.setPosition(positionX, positionY);

		positionX += (pixelSize.x / textureSize.x) * width;
		//positionY += (pixelSize.y / textureSize.y) * height;
	}
	else
	{
		std::cout << "Failed to load " << path << std::endl;
	}
}

void BoardTile::Draw(sf::RenderWindow& window)
{
	window.draw(plainTileSprite);
	window.draw(twTileSprite);
	window.draw(tlTileSprite);
	window.draw(dwTileSprite);
	window.draw(dlTileSprite);
}
