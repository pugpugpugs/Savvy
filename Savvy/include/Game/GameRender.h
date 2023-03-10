#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class GameRender
{
public:

	GameRender();
	static void Initialize();
	static GameRender* GetInstance();
	static size_t RegisterTexture(std::string filename);
	static void RegisterSprite(sf::Sprite sprite, size_t id);
	static void Draw(sf::RenderWindow& window, size_t id);

private:
	static GameRender* _instance;
	std::vector<sf::Sprite> _sprites;
	std::vector<sf::Texture> _textures;
};

