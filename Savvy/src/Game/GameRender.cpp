#include <iostream>
#include "Game/GameRender.h"
#include <Board/Tile.h>

namespace sve
{
	GameRender* GameRender::_instance = nullptr;
	sf::Sprite* GameRender::activeSprite = nullptr;

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

		if (!instance._textures.back().loadFromFile(filename))
		{
			throw std::invalid_argument("Could not load texture from file " + filename);
		}

		return instance._textures.size() - 1;
	}

	void GameRender::RegisterSfmlShape(sve::Drawable& object)
	{
		GameRender& instance = *GetInstance();

		instance._drawables.push_back(&object);
	}

	void GameRender::RegisterSprite(Drawable& object)
	{
		GameRender& instance = *GetInstance();

		object.sprite.setTexture(instance._textures[object.TextureId()]);
		object.sprite.setTextureRect(object.GetTextureRect());
		object.sprite.setScale(object.GetScale());

		instance._drawables.push_back(&object);
	}

	void GameRender::Draw(sf::RenderWindow& window)
	{
		GameRender& instance = *GetInstance();

		for (size_t i = 0; i < instance._drawables.size(); i++)
		{
			std::sort(instance._drawables.begin(), instance._drawables.end(), PointerCompare());
		}

		for (size_t i = 0; i < instance._drawables.size(); i++)
		{
			//std::cout << instance._drawables[i]->ZStack << std::endl;
			instance._drawables[i]->Draw(window);
		}
	}

	void GameRender::DragSprite(sf::Vector2f& initialMousePosition, const sf::RenderWindow& window)
	{
		GameRender& instance = *GetInstance();

		if (GameRender::activeSprite != nullptr)
		{
			//std::cout << "active sprite" << std::endl;
			sf::Vector2f positionChange = sf::Vector2f(sf::Mouse::getPosition(window)) - initialMousePosition;
			initialMousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
			sf::Vector2f newPosition = activeSprite->getPosition() + positionChange;
			activeSprite->setPosition(newPosition);
		}
		else
		{
			for (auto& drawable : instance._drawables)
			{
				if (!drawable->IsDraggable)
				{
					continue;
				}
				const sf::Vector2f& spritePosition = drawable->sprite.getPosition();

				if (spritePosition.x <= initialMousePosition.x
					&& initialMousePosition.x <= spritePosition.x + drawable->sprite.getGlobalBounds().width
					&& spritePosition.y <= initialMousePosition.y
					&& initialMousePosition.y <= spritePosition.y + drawable->sprite.getGlobalBounds().height)
				{
					GameRender::activeSprite = &drawable->sprite;
					GameRender::initialLetterPosition = drawable->sprite.getPosition();
				}
			}
		}
	}

	void GameRender::DropSprite()
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

		for (auto& drawable : instance._drawables)
		{
			if (!drawable->CanDropOn)
			{
				continue;
			}

			const sf::Vector2f& spritePosition = drawable->sprite.getPosition();

			if (activeSpriteCenter.x >= drawable->sprite.getPosition().x
				&& drawable->sprite.getPosition().x + drawable->sprite.getGlobalBounds().width >= activeSpriteCenter.x
				&& activeSpriteCenter.y >= drawable->sprite.getPosition().y
				&& drawable->sprite.getPosition().y + drawable->sprite.getGlobalBounds().height >= activeSpriteCenter.y)
			{
				GameRender::activeSprite->setPosition(drawable->sprite.getPosition());
				isValidMove = true;
				break;
			}
		}

		if (!isValidMove)
		{
			//for (size_t i = 0; i < instance.rack.rackPositions.size(); i++)
			//{
			//	auto rackPosition = instance.rack.rackPositions[i]->Rectangle;

			//	if (activeSpriteCenter.x >= rackPosition.getPosition().x
			//		&& rackPosition.getPosition().x + rackPosition.getGlobalBounds().width >= activeSpriteCenter.x
			//		&& activeSpriteCenter.y >= rackPosition.getPosition().y
			//		&& rackPosition.getPosition().y + rackPosition.getGlobalBounds().height >= activeSpriteCenter.y)
			//	{
			//		GameRender::activeSprite->setPosition(rackPosition.getPosition());
			//		isValidMove = true;
			//		break;
			//	}
			//}

			//if (!isValidMove)
			//{
			//	for (size_t i = 0; i < instance.rack.rackPositions.size(); i++)
			//	{
			//		if (!instance.rack.rackPositions[i]->IsEmpty)
			//		{
			//			continue;
			//		}
			//		auto rackPosition = instance.rack.rackPositions[i]->Rectangle;
			//		GameRender::activeSprite->setPosition(instance.rack.rackPositions.front()->Rectangle.getPosition());
			//		break;
			//	}
			//}
		}

		GameRender::activeSprite = nullptr;
	}
}