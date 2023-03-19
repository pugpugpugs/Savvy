#include "Engine.h"
#include <iostream>
#include "Game/GameRender.h"
#include "Game/Game.h"

namespace sve
{

	//void Engine::Start(Options options)
	//{
	//	game.Start();
	//}
	void Engine::Start()
	{
		Game game;
		game.Start();
	}

	void Engine::Test()
	{
		std::cout << "Test dll." << std::endl;
	}

	//void Engine::Render()
	//{
	//	GameRender::Initialize;
	//}
}
