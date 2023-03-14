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
	//textureId = GameRender::RegisterTexture(TILERACK_FILEPATH);
}

const int TileRack::GetId()
{
	return _textureId;
}

void TileRack::SetRackPositions()
{
	for (size_t i = 0; i < _rackPositions; i++)
	{
		sf::Vector2f position = sf::Vector2f(_offsetPixels + (i * (BOARD_TILE_SCALE_SIZE + _offsetPixels)), rack.getPosition().y + _offsetPixels);
		sf::RectangleShape rackPosition;
		rackPosition.setFillColor(sf::Color::Blue);
		rackPosition.setOutlineColor(sf::Color::Red);
		rackPosition.setOutlineThickness(5.0);
		rackPosition.setSize(sf::Vector2f(BOARD_TILE_SCALE_SIZE, BOARD_TILE_SCALE_SIZE));
		rackPosition.setPosition(position);
		auto pRect = std::make_unique<sf::RectangleShape>(rackPosition);
		rackPositionVectors.push_back(std::move(pRect));

		std::cout << "Rack " << i << ": " << rackPosition.getPosition().x << ", " << rackPosition.getPosition().y << std::endl;
	}
}

//void TileRack::Draw(sf::RenderWindow& window)
//{
//	window.draw(rack);
//}