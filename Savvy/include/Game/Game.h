#pragma once
#include <Board/BoardTile.h>
#include <Letter/LetterTile.h>

class Game
{
public:
	Game();
	void Start();
	void Initialize();
	//void HandleClickEvent(sf::Mouse& mouse, sf::RenderWindow& window);
	std::vector<std::unique_ptr<BoardTile>> boardTiles;
	std::vector<std::unique_ptr<LetterTile>> letterTiles;

private:
	void CreateBoard();
	void CreateLetters();
};

