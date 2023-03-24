#pragma once
#include "Game/GameRender.h"

namespace sve
{
	class GameState;

	class Game
	{
	public:
		sf::RenderWindow window;
		sf::Clock clock;
		//std::vector<std::unique_ptr<Tile>> BoardTiles;
		//std::vector<std::unique_ptr<Tile>> LetterTiles;

		Game();
		void CreateWindow();
		void Start();
		void Initialize();
		void PushState(GameState* state);
		void PopState();
		GameState* CurrentState();
		std::string GetState();

	private:
		std::vector<GameState*> _states;

		void CreateBoard();
		void CreateLetters();
	};
}

