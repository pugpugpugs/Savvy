#pragma once
#include <SFML/Graphics.hpp>

class TileRack
{
public:
	sf::RectangleShape rack;
	std::vector<std::unique_ptr<sf::RectangleShape>> rackPositionVectors;

	TileRack();
	~TileRack();
	static void Initialize();
	const int GetId();
	//void Draw(sf::RenderWindow& window);
	
private:
	inline static int _textureId { -1 };
	int _rackPositions = 7;
	int _offsetPixels = 12;

	void SetRackPositions();
};

