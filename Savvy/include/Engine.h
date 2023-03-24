#pragma once
#include "Game/Game.h"

namespace sve
{
	class SAVVY_API Engine
	{
	public:
		sve::Game game;

		void Run();
		sf::RenderWindow* Window();
		void Test();
		std::string GetState();
	};
}