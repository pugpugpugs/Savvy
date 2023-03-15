#include "Board/TileRack.h"
#include <Common/Constants.h>
#include <iostream>

TileRack::TileRack()
{
	rack.setPosition(sf::Vector2f(0, 650));
	rack.setSize(sf::Vector2f(1000, 150));
	rack.setFillColor(sf::Color::White);

	SetRackPositions();
}

TileRack::~TileRack()
{
}

void TileRack::Initialize()
{
}

const int TileRack::GetId()
{
	return _textureId;
}

void TileRack::SetRackPositions()
{
	for (size_t i = 0; i < _rackPositions; i++)
	{

		sf::Vector2f position = sf::Vector2f(_offsetPixels + (i * (GAME_TILE_SIZE + _offsetPixels)), rack.getPosition().y + _offsetPixels);
		sf::RectangleShape rect;
		rect.setFillColor(sf::Color::Blue);
		rect.setOutlineColor(sf::Color::Red);
		rect.setOutlineThickness(5.0);
		rect.setSize(sf::Vector2f(GAME_TILE_SIZE, GAME_TILE_SIZE));
		rect.setPosition(position);

		TileRackPosition rackPos;
		rackPos.Rectangle = rect;

		auto pRect = std::make_unique<TileRackPosition>(rackPos);
		rackPositions.push_back(std::move(pRect));
	}
}
