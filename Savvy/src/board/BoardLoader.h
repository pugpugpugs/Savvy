#pragma once
#include <SFML/Graphics.hpp>
#include "BoardTileSettings.h"

class BoardLoader
{
public:
	std::vector<sf::Sprite*> boardTileMap;

private:
	const BoardTileSettings* tileSettings;

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

public:
	BoardLoader(const BoardTileSettings& tileSettings);
	~BoardLoader();

	void Initialize();

	void Load(sf::Texture& texture, sf::Sprite& sprite,const std::string& path);

	void Draw(sf::RenderWindow& window);

private:
};

