#pragma once
#include <SFML/Graphics.hpp>

class BoardTile
{
public:
	sf::Sprite sprite;
	bool isEmpty;

public:
	BoardTile();
	~BoardTile();
};

