#include "Game/GameRender.h"
#include <iostream>
#include <Board/Layout.h>
#include <Board/BoardTile.h>

GameRender* GameRender::_instance = nullptr;

GameRender::GameRender()
{
}

void GameRender::Initialize() 
{
	if (!GetInstance())
	{
		_instance = new GameRender();
	}
}

GameRender* GameRender::GetInstance()
{
	return _instance;
}

size_t GameRender::RegisterTexture(std::string filename)
{
	GameRender& instance = *GetInstance();

	instance._textures.push_back(sf::Texture());

	if (instance._textures.back().loadFromFile(filename))
	{
		std::cout << "Loaded texture from file " << filename << std::endl;
	}
	else
	{
		std::cout << "ERROR: Unable to load texture " << filename << std::endl;
	}

	return instance._textures.size() - 1;
}

void GameRender::RegisterSprite(BoardTile& tile)
{
	GameRender& instance = *GetInstance();

	tile.sprite.setTexture(instance._textures[tile.GetId()]);
	tile.sprite.setTextureRect(sf::IntRect(tile.startX, tile.startY, BOARD_TILE_WIDTH, BOARD_TILE_HEIGHT));
	tile.sprite.setScale(static_cast<float>(BOARD_TILE_SCALE_SIZE / BOARD_TILE_SPRITE_SIZE), static_cast<float>(BOARD_TILE_SCALE_SIZE / BOARD_TILE_SPRITE_SIZE));

	instance._sprites.push_back(tile.sprite);
	std::cout << "Sprite count: " << instance._sprites.size() << std::endl;
}


void GameRender::UpdateSprite(BoardTile& pTile)
{
	GameRender& instance = *GetInstance();

	pTile.sprite.setTexture(instance._textures[pTile.GetId()]);
	pTile.sprite.setTextureRect(sf::IntRect(pTile.startX, pTile.startY, BOARD_TILE_WIDTH, BOARD_TILE_HEIGHT));
	pTile.sprite.setScale(static_cast<float>(BOARD_TILE_SCALE_SIZE / BOARD_TILE_SPRITE_SIZE), static_cast<float>(BOARD_TILE_SCALE_SIZE / BOARD_TILE_SPRITE_SIZE));

	instance._sprites[0] = pTile.sprite;
	std::cout << "Sprite count: " << instance._sprites.size() << std::endl;
}

void GameRender::Draw(sf::RenderWindow& window) 
{
	GameRender& instance = *GetInstance();


	for (size_t i = 0; i < instance._sprites.size(); i++)
	{
		window.draw(instance._sprites[i]);
	}
}