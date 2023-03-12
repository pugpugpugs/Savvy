#pragma once
#include <Board/BoardTile.h>

class Game
{
public:
	Game();
	void Start();
	void Initialize();
	//void HandleClickEvent(sf::Mouse& mouse, sf::RenderWindow& window);

	std::vector<std::unique_ptr<BoardTile>> boardTiles;

private:
	void CreateBoard();
};

