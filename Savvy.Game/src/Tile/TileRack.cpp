#include "Tile/TileRack.h"
#include "Constants.h"
#include <iostream>

TileRackPosition::TileRackPosition()
{
	ZStack = 5;
}

void TileRackPosition::Draw(sf::RenderWindow& window)
{
	window.draw(Rectangle);
}


TileRack::TileRack()
{
	RackTiles.reserve(7);

	Rack.setPosition(sf::Vector2f(0, 650));
	Rack.setSize(sf::Vector2f(1000, 150));
	Rack.setFillColor(sf::Color::White);

	SetRackPositions();
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
		sf::Vector2f position = sf::Vector2f(_offsetPixels + (i * (GAME_TILE_SIZE + _offsetPixels)), Rack.getPosition().y + _offsetPixels);
		sf::RectangleShape rect;
		rect.setFillColor(sf::Color::Blue);
		rect.setOutlineColor(sf::Color::Red);
		rect.setOutlineThickness(5.0);
		rect.setSize(sf::Vector2f(GAME_TILE_SIZE, GAME_TILE_SIZE));
		rect.setPosition(position);

		TileRackPosition rackPos;
		rackPos.Rectangle = rect;

		auto pRect = std::make_unique<TileRackPosition>(rackPos);
		RackPositions.push_back(std::move(pRect));
	}
}

void TileRack::Draw(sf::RenderWindow& window)
{
	window.draw(Rack);
}

