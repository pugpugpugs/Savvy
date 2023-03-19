#pragma once
#include "GameState.h"
#include <Game/Game.h>
#include <Event/EventHandler.h>

namespace sve
{
	class PlayState : public GameState
	{
	public:
		PlayState(Game* game);
		void Draw(const float elapsedSeconds);
		void Update(const float elapsedSeconds);
		void Handle();

	private:
		EventHandler _handler;
	};
}