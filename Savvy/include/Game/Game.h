#pragma once
#include <Board/Tile.h>
#include <Board/LetterTile.h>

class GameState;

class Game
{
public:
	sf::RenderWindow window;
	//std::vector<std::unique_ptr<Tile>> BoardTiles;
	//std::vector<std::unique_ptr<Tile>> LetterTiles;

	Game();
	void CreateWindow();
	void Start();
	void Initialize();
	void PushState(GameState* state);
	void PopState();
	GameState* CurrentState();

private:
	std::vector<GameState*> _states;

	void CreateBoard();
	void CreateLetters();
};

