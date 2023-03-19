#include "Game/Drawable.h"

namespace sve
{
	const int Drawable::StartX()
	{
		return _startX;
	}

	const int Drawable::StartY()
	{
		return _startY;
	}

	const sf::IntRect Drawable::GetTextureRect()
	{
		return sf::IntRect(_startX, _startY, _spriteSize, _spriteSize);
	}

	const sf::Vector2f Drawable::GetScale()
	{
		return _scale;
	}

	const float Drawable::GetScaleRatio()
	{
		return _scaleRatio;
	}

	const sf::Vector2f Drawable::GetTileMapCoords()
	{
		return _tileMapCoords;
	}

	const sf::Vector2f Drawable::GetPosition()
	{
		return sprite.getPosition();
	}

	void Drawable::SetPosition(const sf::Vector2f position)
	{
		sprite.setPosition(position);
	}

	const int Drawable::TextureId()
	{
		return _textureId;
	}

	const sf::Vector2f Drawable::GetSpriteSize() 
	{
		return sf::Vector2f(_spriteSize, _spriteSize);
	}
}