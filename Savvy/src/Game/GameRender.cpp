#include "Game/GameRender.h"
#include <iostream>
#include <Layout.h>

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

void GameRender::RegisterSprite(sf::Sprite sprite, size_t id)
{
	GameRender& instance = *GetInstance();

	sprite.setTexture(instance._textures[id]);
	sprite.setTextureRect(sf::IntRect(NORMAL_TILE_START_POS_X, NORMAL_TILE_START_POS_Y, BOARD_TILE_WIDTH, BOARD_TILE_HEIGHT));
	sprite.setScale(static_cast<float>(BOARD_TILE_PIXEL_SIZE / BOARD_TILE_SPRITE_SIZE), static_cast<float>(BOARD_TILE_PIXEL_SIZE / BOARD_TILE_SPRITE_SIZE));

	instance._sprites.push_back(sprite);
}

void GameRender::Draw(sf::RenderWindow& window, size_t id) 
{
	GameRender& instance = *GetInstance();

	//sf::Sprite renderSprite(instance._textures[id]);
	//renderSprite.setScale(5, 5);
	//window.draw(renderSprite);

	for (size_t i = 0; i < instance._sprites.size(); i++)
	{
		//instance._sprites[i].setPosition(Layout::OffsetX(i), Layout::OffsetY(i));
		window.draw(instance._sprites[i]);
	}
}