#include "Game/GameRender.h"
#include <iostream>
#include <Board/Layout.h>
#include <Board/BoardTile.h>

GameRender* GameRender::_instance = nullptr;
sf::Sprite* GameRender::activeSprite = nullptr;
sf::Vector2f GameRender::tileScale = sf::Vector2f(static_cast<float>(BOARD_TILE_SCALE_SIZE) / static_cast<float>(BOARD_TILE_SPRITE_SIZE),
	static_cast<float>(BOARD_TILE_SCALE_SIZE) / static_cast<float>(BOARD_TILE_SPRITE_SIZE));
//sf::Vector2f GameRender::letterTileScale = sf::Vector2f(static_cast<float>(BOARD_TILE_SCALE_SIZE) / static_cast<float>(ORIG_BOARD_TILE_WIDTH),
//														static_cast<float>(BOARD_TILE_SCALE_SIZE) / static_cast<float>(ORIG_BOARD_TILE_HEIGHT));
sf::Vector2f GameRender::scaledAmount = sf::Vector2f(BOARD_TILE_SPRITE_SIZE * tileScale.x, BOARD_TILE_SPRITE_SIZE * tileScale.y);
//sf::Vector2f GameRender::letterScaledAmount = sf::Vector2f(ORIG_BOARD_TILE_SPRITE_SIZE * letterTileScale.x, ORIG_BOARD_TILE_SPRITE_SIZE * letterTileScale.y);

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

void GameRender::RegisterLetterSprite(BoardTile& tile)
{
	GameRender& instance = *GetInstance();

	GameRender::SetLetterTileDisplay(tile, instance);

	instance._letterSprites.push_back(tile.sprite);
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

void GameRender::SetLetterTileDisplay(BoardTile& tile, GameRender& instance)
{
	tile.sprite.setTexture(instance._textures[tile.GetId()]);
	std::cout << tile.startX << tile.startY << std::endl;
	tile.sprite.setTextureRect(sf::IntRect(tile.startX, tile.startY, BOARD_TILE_WIDTH, BOARD_TILE_HEIGHT));
	tile.sprite.setScale(tileScale.x, tileScale.y);
}

void GameRender::Draw(sf::RenderWindow& window)
{
	GameRender& instance = *GetInstance();

	window.draw(instance.rack.rack);

	for (size_t i = 0; i < instance.rack.rackPositionVectors.size(); i++)
	{
		window.draw(*instance.rack.rackPositionVectors[i]);

		//std::cout << "Rack " << i << ": " << (*instance.rack.rackPositionVectors[i]).getPosition().x << ", " << (*instance.rack.rackPositionVectors[i]).getPosition().y << std::endl;
	}

	for (size_t i = 0; i < instance._sprites.size(); i++)
	{
		window.draw(instance._sprites[i]);
	}

	for (size_t i = 0; i < instance._letterSprites.size(); i++)
	{
		window.draw(instance._letterSprites[i]);
	}
}

void GameRender::DragSprite(sf::Vector2f& initialMousePosition, const sf::RenderWindow& window)
{
	GameRender& instance = *GetInstance();

	if (GameRender::activeSprite != nullptr)
	{
		//std::cout << "initial position " << initialMousePosition.x << "," << initialMousePosition.y << std::endl;
		sf::Vector2f positionChange = sf::Vector2f(sf::Mouse::getPosition(window)) - initialMousePosition;
		initialMousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
		sf::Vector2f newPosition = activeSprite->getPosition() + positionChange;
		activeSprite->setPosition(newPosition);
		//std::cout << "active position " << activeSprite->getPosition().x << "," << activeSprite->getPosition().y << std::endl;
	}
	else
	{
		for (auto& sprite : instance._letterSprites)
		{
			const sf::Vector2f& spritePosition = sprite.getPosition();

			if (spritePosition.x <= initialMousePosition.x
				&& initialMousePosition.x <= spritePosition.x + scaledAmount.x
				&& spritePosition.y <= initialMousePosition.y
				&& initialMousePosition.y <= spritePosition.y + scaledAmount.y)
			{
				GameRender::activeSprite = &sprite;
				GameRender::initialLetterPosition = sprite.getPosition();
			}
		}
	}
}

void GameRender::DropSprite(sf::Vector2f& initialMousePosition, const sf::RenderWindow& window)
{
	if (GameRender::activeSprite == nullptr)
	{
		return;
	}

	GameRender& instance = *GetInstance();
	sf::Vector2f mouseReleasePosition = sf::Vector2f(sf::Mouse::getPosition());

	bool isValidMove = false;

	float centerX = activeSprite->getGlobalBounds().width / 2;
	float centerY = activeSprite->getGlobalBounds().height / 2;

	sf::Vector2f activeSpriteCenter(activeSprite->getPosition().x + centerX, activeSprite->getPosition().y + centerY);

	//std::cout << "Active center: (" << activeSpriteCenter.x << ", " << activeSpriteCenter.y << ")" << std::endl;

	for (auto& sprite : instance._sprites)
	{
		const sf::Vector2f& spritePosition = sprite.getPosition();

		//std::cout << "sprite pos: (" << sprite.getPosition().x << ", " << sprite.getPosition().y << ")" << std::endl;
		//std::cout << "scale amt : (" << letterScaledAmount.x << ", " << letterScaledAmount.y << ")" << std::endl;

		if (activeSpriteCenter.x >= sprite.getPosition().x
			&& sprite.getPosition().x + sprite.getGlobalBounds().width >= activeSpriteCenter.x
			&& activeSpriteCenter.y >= sprite.getPosition().y
			&& sprite.getPosition().y + sprite.getGlobalBounds().height >= activeSpriteCenter.y)
		{
			//std::cout << "valid sprite pos: (" << sprite.getPosition().x << ", " << sprite.getPosition().y << ")" << std::endl;
			//std::cout << "Active center: (" << activeSpriteCenter.x << ", " << activeSpriteCenter.y << ")" << std::endl;
			GameRender::activeSprite->setPosition(sprite.getPosition());
			isValidMove = true;
			break;
		}
	}

	if (!isValidMove)
	{
		for (size_t i = 0; i < instance.rack.rackPositionVectors.size(); i++)
		{
			auto rackPosition = (*instance.rack.rackPositionVectors[i]);

			if (activeSpriteCenter.x >= rackPosition.getPosition().x
				&& rackPosition.getPosition().x + rackPosition.getGlobalBounds().width >= activeSpriteCenter.x
				&& activeSpriteCenter.y >= rackPosition.getPosition().y
				&& rackPosition.getPosition().y + rackPosition.getGlobalBounds().height >= activeSpriteCenter.y)
			{
				std::cout << "Valid move: " << i << std::endl;
				GameRender::activeSprite->setPosition(rackPosition.getPosition());
				isValidMove = true;
				break;
			}
		}

		if (!isValidMove)
		{
			GameRender::activeSprite->setPosition((*instance.rack.rackPositionVectors.front()).getPosition());
		}

		GameRender::activeSprite = nullptr;
	}
}