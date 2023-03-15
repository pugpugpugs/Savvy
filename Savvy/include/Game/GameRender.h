#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Board/Tile.h"
#include <Board/TileRack.h>

class GameRender
{
public:

	GameRender();
	static void Initialize();
	static GameRender* GetInstance();
	static size_t RegisterTexture(std::string filename);
	//static void UpdateSprite(Tile& tile);
	static void RegisterSprite(std::unique_ptr<Drawable> object);
	//static void RegisterLetterSprite(Tile& tile);
	static void Draw(sf::RenderWindow& window);
	static void DragSprite(sf::Vector2f& mousePosition, const sf::RenderWindow& window);
	static void DropSprite();
	static sf::Sprite* activeSprite;

private:
	static GameRender* _instance;
	std::vector<sf::Texture> _textures;
	std::vector<Drawable> _drawables;

	TileRack rack;

	static inline sf::Vector2f initialLetterPosition{ 0, 0 };

	//static void SetTileDisplay(Tile& tile, GameRender& instance);
	//static void SetLetterTileDisplay(Tile& tile, GameRender& instance);
};

