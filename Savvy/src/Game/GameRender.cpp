#include "Game/GameRender.h"
#include <iostream>
#include <Board/Layout.h>
#include <Board/BoardTile.h>

GameRender* GameRender::_instance = nullptr;
sf::Sprite* GameRender::activeSprite = nullptr;
sf::Vector2f GameRender::tileScale = sf::Vector2f(static_cast<float>(BOARD_TILE_SCALE_SIZE / BOARD_TILE_SPRITE_SIZE), 
											      static_cast<float>(BOARD_TILE_SCALE_SIZE / BOARD_TILE_SPRITE_SIZE));
sf::Vector2f GameRender::scaledAmount = sf::Vector2f(BOARD_TILE_SPRITE_SIZE * tileScale.x, BOARD_TILE_SPRITE_SIZE * tileScale.y);

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

	GameRender::SetTileDisplay(tile, instance);

	instance._sprites.push_back(tile.sprite);
}


void GameRender::UpdateSprite(BoardTile& tile)
{
	GameRender& instance = *GetInstance();

	GameRender::SetTileDisplay(tile, instance);

	instance._sprites[0] = tile.sprite;
}

void GameRender::SetTileDisplay(BoardTile& tile, GameRender& instance)
{
	tile.sprite.setTexture(instance._textures[tile.GetId()]);
	tile.sprite.setTextureRect(sf::IntRect(tile.startX, tile.startY, BOARD_TILE_WIDTH, BOARD_TILE_HEIGHT));
	tile.sprite.setScale(tileScale.x, tileScale.y);
}

void GameRender::Draw(sf::RenderWindow& window) 
{
	GameRender& instance = *GetInstance();

	for (size_t i = 0; i < instance._sprites.size(); i++)
	{
		window.draw(instance._sprites[i]);
	}
}

void GameRender::HandleClickEvent(sf::Vector2f& initialMousePosition, sf::RenderWindow& window)
{
	GameRender& instance = *GetInstance();

	if (GameRender::activeSprite != nullptr)
	{
		sf::Vector2f positionChange = sf::Vector2f(sf::Mouse::getPosition(window)) - initialMousePosition;
		initialMousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
		sf::Vector2f newPosition = activeSprite->getPosition() + positionChange;
		activeSprite->setPosition(newPosition);
	}
	else
	{
		for (auto& sprite : instance._sprites)
		{
			const sf::Vector2f& spritePosition = sprite.getPosition();

			if (spritePosition.x <= initialMousePosition.x
				&& initialMousePosition.x <= spritePosition.x + scaledAmount.x
				&& spritePosition.y <= initialMousePosition.y
				&& initialMousePosition.y <= spritePosition.y + scaledAmount.y)
			{
				GameRender::activeSprite = &sprite;
			}
		}
	}
}