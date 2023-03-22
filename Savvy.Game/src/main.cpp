#include <iostream>
#include "Savvy.h"
#include "Game/Game.h"
#include "Tile/TileRack.h"
#include <Tile/TileBag.h>

int main()
{

	sve::GameRender::Initialize();
	BoardTile::Initialize();
	LetterTile::Initialize();

	sve::Engine engine;

	Game game;
	game.Start();
	
	engine.Start();

	return 0;

}