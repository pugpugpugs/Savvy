#pragma once
#include <SFML/Graphics.hpp>

class BoardLoader
{
public:
	std::vector<sf::Sprite*> boardTileMap;

private:
	sf::Texture plainTileTexture;
	sf::Sprite plainTileSprite;

	sf::Texture dwTileTexture;
	sf::Sprite dwTileSprite;

	sf::Texture twTileTexture;
	sf::Sprite twTileSprite;

	sf::Texture dlTileTexture;
	sf::Sprite dlTileSprite;

	sf::Texture tlTileTexture;
	sf::Sprite tlTileSprite;

	sf::Texture startTileTexture;
	sf::Sprite startTileSprite;

	sf::Vector2f textureSize;
	sf::Vector2f ratio;
	sf::Vector2f worldUnits;
	sf::Vector2f pixelSize;
	sf::Vector2f scale;

	int positionX = 0;
	int positionY = 0;

public:
	BoardLoader();
	~BoardLoader();

	void Initialize();

	void Load(sf::Texture& texture, sf::Sprite& sprite, std::string path);

	void Draw(sf::RenderWindow& window);

private:
};

