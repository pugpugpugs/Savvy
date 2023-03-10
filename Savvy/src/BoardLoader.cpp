//#include <iostream>
//#include <SFML/Graphics.hpp>
//#include "BoardLoader.h"
//
//BoardLoader::BoardLoader(const BoardTileSettings& tileSettings) : _tileSettings(&tileSettings), textures()
//{
//	Initialize();
//}
//
//BoardLoader::~BoardLoader()
//{
//}
//
//void BoardLoader::Initialize()
//{
//	Load(textures.startTileTexture, startTileSprite, START_TILE_FILEPATH);
//	Load(textures.plainTileTexture, plainTileSprite, NORMAL_TILE_FILEPATH);
//	Load(textures.dwTileTexture, dwTileSprite, DW_TILE_FILEPATH);
//	Load(textures.twTileTexture, twTileSprite, TW_TILE_FILEPATH);
//	Load(textures.dlTileTexture, dlTileSprite, DL_TILE_FILEPATH);
//	Load(textures.tlTileTexture, tlTileSprite, TL_TILE_FILEPATH);
//}
//
//void BoardLoader::Load(sf::Texture& texture, sf::Sprite& sprite,const std::string& path)
//{
//	if (texture.loadFromFile(path))
//	{
//		std::cout << "Loaded " << path << std::endl;
//
//		sprite.setTexture(texture);
//
//		if (path == START_TILE_FILEPATH)
//		{
//			sprite.setTextureRect(sf::IntRect(145, 1, tileSettings->width, tileSettings->height));
//		}
//		else 
//		{
//			sprite.setTextureRect(sf::IntRect(1, 1, tileSettings->width, tileSettings->height));
//		}
//
//		sprite.setScale(tileSettings->boardTileScale);
//
//		sf::Sprite* spritePtr = &sprite;
//		boardTileMap.push_back(spritePtr);
//	}
//	else
//	{
//		std::cout << "Failed to load " << path << std::endl;
//	}
//}
//
//void BoardLoader::Draw(sf::RenderWindow& window) const
//{
//
//}
