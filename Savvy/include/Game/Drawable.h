#pragma once
#include <SFML/Graphics.hpp>

class Drawable
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
	const sf::Vector2f GetPosition();
	void SetPosition(const sf::Vector2f position);
	sf::Sprite sprite;
	bool IsDraggable = false;
	bool CanDropOn = false;
protected:
	float _startX = 0;
	float _startY = 0;
	float _spriteSize = 0;
	float _scaleRatio = 0;
	sf::Vector2f _scale;
	sf::Vector2f _tileMapCoords;
	int _textureId = -1;
};

