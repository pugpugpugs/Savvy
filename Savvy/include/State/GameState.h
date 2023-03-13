#pragma once
#include "Game/Game.h"

class GameState
{
public:
	Game* game;

	virtual ~GameState() { };
	virtual void Draw(const float elapsedSecond) = 0;
	virtual void Update(const float elapsedSecond) = 0;
	virtual void Handle() = 0;
};

