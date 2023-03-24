#pragma once
#include <vector>
#include <memory>
#include "Tile/LetterTile.h"
#include "Savvy.h"

struct TileRackPosition : public sve::Drawable
{
	sf::RectangleShape Rectangle;
	bool IsEmpty = true;
	TileRackPosition();
	void Draw(sf::RenderWindow& window) override;
};

class TileRack : public sve::Drawable
{
public:
	std::vector<std::unique_ptr<LetterTile>> RackTiles;

	sf::RectangleShape Rack;
	std::vector<std::unique_ptr<TileRackPosition>> RackPositions;

	TileRack();
	static void Initialize();
	const int GetId();
	void Draw(sf::RenderWindow& window) override;

private:
	inline static int _textureId{ -1 };
	int _rackPositions = 7;
	int _offsetPixels = 12;

	void SetRackPositions();
};