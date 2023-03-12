#pragma once
#include <SFML/Graphics.hpp>

class BoardTile
{
public:
	virtual ~BoardTile() { }
	void SetPosition(float x, float y);
	void Draw(sf::RenderWindow& window);
	//void Init(const sf::Texture& texture);
	virtual const int GetId() = 0;
	sf::Sprite sprite;
	int startX = 0;
	int startY = 0;
protected:
	sf::Vector2f scale;
};
