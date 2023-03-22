#pragma once
#include <SFML/Graphics.hpp>
#include "Engine.h"

namespace sve
{
	class SAVVY_API Drawable
	{
	public:
		int ZStack = 0;
		const int StartX();
		const int StartY();
		const sf::IntRect GetTextureRect();
		const sf::Vector2f GetScale();
		const float GetScaleRatio();
		const sf::Vector2f GetTileMapCoords();
		virtual const int TextureId();
		const sf::Vector2f GetSpriteSize();
		const sf::Vector2f GetPosition();

		void virtual Draw(sf::RenderWindow& window);

		void SetPosition(const sf::Vector2f position);
		sf::Sprite sprite;
		bool IsDraggable = false;
		bool CanDropOn = false;
		bool operator > (const Drawable& obj) const;
		bool operator < (const Drawable& obj) const;
	protected:
		float _startX = 0;
		float _startY = 0;
		float _spriteSize = 0;
		float _scaleRatio = 0;
		sf::Vector2f _scale;
		sf::Vector2f _tileMapCoords;
		int _textureId = -1;
	};

	struct PointerCompare {
		bool operator()(const sve::Drawable* obj1, const sve::Drawable* obj2) const
		{
			return *obj1 < *obj2;
		}
	};
}

