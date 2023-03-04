#pragma once
#include <SFML/Graphics.hpp>

class BoardTileSettings
{
public:
	int height = 14;
	int width = 14;
	int texturePixelSize = 16;
	int worldUnitPixelAmount = 128;
	int worldUnit = 1;
	sf::Vector2f boardTileScale;
	sf::Vector2f offset;

private:
	sf::Vector2f textureSize;
	sf::Vector2f worldUnitPixelRatio;
	sf::Vector2f worldUnitRatio;
	sf::Vector2f boardPixelSize;

public:
	BoardTileSettings();
	~BoardTileSettings();

};