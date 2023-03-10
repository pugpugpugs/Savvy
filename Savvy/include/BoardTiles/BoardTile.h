#pragma once
#include <SFML/Graphics.hpp>
#include "../TileTemplate.h"

class BoardTile : public TileTemplate<BoardTile>
{
public:
	BoardTile();
	~BoardTile();
	void SetPosition(float x, float y);
	void Draw(sf::RenderWindow& window);
	void Init(const sf::Texture& texture);

	//int count = 0;
	//static size_t id;
	sf::Sprite sprite;

protected:
	//sf::Texture* texture = new sf::Texture();
	//int multiplier;
	sf::Vector2f scale;
};
