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
	static void RegisterLetterSprite(BoardTile& tile);
	static void Draw(sf::RenderWindow& window);
	static void HandleClickEvent(sf::Vector2f& mousePosition, sf::RenderWindow& window);
	static void HandleReleaseEvent(sf::Vector2f& initialMousePosition, sf::RenderWindow& window);
	static sf::Vector2f tileScale;
	static sf::Vector2f letterTileScale;
	static sf::Vector2f scaledAmount;
	static sf::Vector2f letterScaledAmount;
	static sf::Sprite* activeSprite;

private:
	static GameRender* _instance;
	std::vector<sf::Sprite> _sprites;
	std::vector<sf::Texture> _textures;
	std::vector<sf::Sprite> _letterSprites;
	static inline sf::Vector2f initialLetterPosition{ 0, 0 };

	static void SetTileDisplay(BoardTile& tile, GameRender& instance);
	static void SetLetterTileDisplay(BoardTile& tile, GameRender& instance);
};

