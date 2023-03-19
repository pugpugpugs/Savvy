#pragma once
#include "GameState.h"
#include <Game/Game.h>

namespace sve
{
	class MainMenuState : public GameState
	{
	public:
		MainMenuState(Game* game);
		void Draw(const float elapsedSeconds);
		void Update(const float elapsedSeconds);
		void Handle();

	private:
		sf::View view;

		void LoadGame();
	};
}

