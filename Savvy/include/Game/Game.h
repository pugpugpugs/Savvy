#pragma once
#include <Board/BoardTile.h>
#include <Letter/LetterTile.h>

class GameState;

class Game
{
public:
	sf::RenderWindow window;
	std::vector<std::unique_ptr<BoardTile>> BoardTiles;
	std::vector<std::unique_ptr<LetterTile>> LetterTiles;

	Game();
	void Start();
	void Initialize();
	void PushState(GameState* state);
	void PopState();
	GameState* CurrentState();
	//void HandleClickEvent(sf::Mouse& mouse, sf::RenderWindow& window);

private:
	std::vector<GameState*> _states;

	void CreateBoard();
	void CreateLetters();
};

