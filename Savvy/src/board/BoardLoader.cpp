#include "BoardLoader.h"
#include <iostream>
#include "../shared/Constants.h"

BoardLoader::BoardLoader(const BoardTileSettings& tileSettings)
{
	this->tileSettings = &tileSettings;
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

void BoardLoader::Load(sf::Texture& texture, sf::Sprite& sprite,const std::string& path)
{
	if (texture.loadFromFile(path))
	{
		std::cout << "Loaded " << path << std::endl;

		sprite.setTexture(texture);

		if (path == START_TILE_FILEPATH)
		{
			sprite.setTextureRect(sf::IntRect(145, 1, tileSettings->width, tileSettings->height));
		}
		else 
		{
			sprite.setTextureRect(sf::IntRect(1, 1, tileSettings->width, tileSettings->height));
		}

		sprite.setScale(tileSettings->boardTileScale);

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
}
