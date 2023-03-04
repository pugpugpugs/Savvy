#include "BoardTileSettings.h"

BoardTileSettings::BoardTileSettings()
{
	textureSize = sf::Vector2f(texturePixelSize, texturePixelSize);
	worldUnitPixelRatio = sf::Vector2f(worldUnitPixelAmount, worldUnitPixelAmount);
	worldUnitRatio = sf::Vector2f(worldUnit, worldUnit);
	boardPixelSize = sf::Vector2f(worldUnitRatio.x * worldUnitPixelRatio.x, worldUnitRatio.y * worldUnitPixelRatio.y);
	boardTileScale = sf::Vector2f(boardPixelSize.x / textureSize.x, boardPixelSize.y / textureSize.y);
	offset = sf::Vector2f(worldUnitPixelAmount / texturePixelSize * width, worldUnitPixelAmount / texturePixelSize * height);
}

BoardTileSettings::~BoardTileSettings()
{
}