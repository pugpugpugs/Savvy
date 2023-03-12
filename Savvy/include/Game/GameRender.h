#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Board/BoardTile.h"

class GameRender
{
public:

	GameRender();
	static void Initialize();
	static GameRender* GetInstance();
	static size_t RegisterTexture(std::string filename);
	static void UpdateSprite(BoardTile& tile);
	static void RegisterSprite(BoardTile& tile);
	static void Draw(sf::RenderWindow& window);
	static void HandleClickEvent(sf::Vector2f mousePosition, sf::RenderWindow& window);
	static sf::Vector2f tileScale;
	static sf::Vector2f scaledAmount;
	static sf::Sprite* activeSprite;

private:
	static GameRender* _instance;
	std::vector<sf::Sprite> _sprites;
	std::vector<sf::Texture> _textures;

	static void SetTileDisplay(BoardTile& tile, GameRender& instance);
};

