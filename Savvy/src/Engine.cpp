#include "Engine.h"
#include <iostream>

namespace sve
{
	void Engine::Run()
	{
		game.Start();
	}

	void Engine::Test()
	{
		std::cout << "Test dll." << std::endl;
	}

	std::string Engine::GetState()
	{
		return game.GetState();
	}

	sf::RenderWindow* Engine::Window()
	{
		return &game.window;
	}
}
