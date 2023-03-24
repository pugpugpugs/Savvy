#include <iostream>
#include "Savvy.h"
#include "Game/Game.h"
#include "Tile/TileRack.h"
#include <Tile/TileBag.h>
#include <typeinfo>

int main()
{

	sve::GameRender::Initialize();
	BoardTile::Initialize();
	LetterTile::Initialize();

	sve::Engine engine;

	Game game;
	game.Start();
	

	while (true)
	{
		engine.Run();
		//auto test = engine.GetState();
		//std::cout << "state: " << test << std::endl;
	}

	return 0;

}