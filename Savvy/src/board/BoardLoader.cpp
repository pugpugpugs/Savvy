#include "BoardLoader.h"
#include <iostream>

#define START_TILE_FILEPATH "assets\\start.png"
#define NORMAL_TILE_FILEPATH "assets\\brown.png"
#define DW_TILE_FILEPATH "assets\\red.png"
#define TW_TILE_FILEPATH "assets\\silver.png"
#define DL_TILE_FILEPATH "assets\\green.png"
#define TL_TILE_FILEPATH "assets\\darkgreen.png"

BoardLoader::BoardLoader() : textureSize(10, 10), ratio(64, 64), worldUnits(1, 1),
						 pixelSize(ratio.x* worldUnits.x, ratio.y* worldUnits.y),
						 scale((pixelSize.x / textureSize.x) * textureSize.x, (pixelSize.y / textureSize.y)* textureSize.y)
{
}

BoardLoader::~BoardLoader()
{
}

void BoardLoader::Initialize()
{
	Load(startTileTexture, startTileSprite, START_TILE_FILEPATH);
	Load(plainTileTexture, plainTileSprite, NORMAL_TILE_FILEPATH);
	Load(dwTileTexture, dwTileSprite, DW_TILE_FILEPATH);
	Load(twTileTexture, twTileSprite, TW_TILE_FILEPATH);
	Load(dlTileTexture, dlTileSprite, DL_TILE_FILEPATH);
	Load(tlTileTexture, tlTileSprite, TL_TILE_FILEPATH);
}

void BoardLoader::Load(sf::Texture& texture, sf::Sprite& sprite, std::string path)
{
	if (texture.loadFromFile(path))
	{
		std::cout << "Loaded " << path << std::endl;

		int height = 14;
		int width = 14;

		sprite.setTexture(texture);

		if (path == START_TILE_FILEPATH)
		{
			sprite.setTextureRect(sf::IntRect(145, 1, width, height));
		}
		else 
		{
			sprite.setTextureRect(sf::IntRect(1, 1, width, height));
		}

		sprite.setScale(pixelSize.x / textureSize.x, pixelSize.y / textureSize.y);

		//sprite.setPosition(positionX, positionY);

		//positionX += (pixelSize.x / textureSize.x) * width;
		//positionY += (pixelSize.y / textureSize.y) * height;

		sf::Sprite* spritePtr = &sprite;
		boardTileMap.push_back(spritePtr);
	}
	else
	{
		std::cout << "Failed to load " << path << std::endl;
	}
}

void BoardLoader::Draw(sf::RenderWindow& window)
{
	//window.draw(plainTileSprite);
	//window.draw(twTileSprite);
	//window.draw(tlTileSprite);
	//window.draw(dwTileSprite);
	//window.draw(dlTileSprite);
}
