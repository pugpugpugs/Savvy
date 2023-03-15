#pragma once
#include <SFML/Graphics.hpp>


struct TileRackPosition
{
	sf::RectangleShape Rectangle;
	bool IsEmpty = true;
};


class TileRack
{
public:
	sf::RectangleShape rack;
	std::vector<std::unique_ptr<TileRackPosition>> rackPositions;

	TileRack();
	~TileRack();
	static void Initialize();
	const int GetId();
	
private:
	inline static int _textureId { -1 };
	int _rackPositions = 7;
	int _offsetPixels = 12;

	void SetRackPositions();
};

