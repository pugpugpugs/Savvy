#include <iostream>
#include "Savvy.h"
#include "Game/Game.h"
#include "Tile/TileRack.h"
#include <Tile/TileBag.h>

int main()
{

	sve::GameRender::Initialize();
	BoardTile::Initialize();

	sve::Engine engine;

	Game game;
	game.Start();

	for (size_t i = 0; i < game.Board.size(); i++)
	{
		std::cout << "size: " << game.Board[i]->CalculateScore() << std::endl;
	}



	engine.Start();

	//for (size_t i = 0; i < game.LetterBag.size(); i++)
	//{
	//	std::cout << "letter size: " << game.LetterBag[i]->Points << std::endl;
	//}

	//LetterTile letter;

	//std::cout << "tile bag: " << letter.TilesByNumber.size() << std::endl;

	//for (auto& tile : letter.TilesByNumber)
	//{
	//	std::cout << "tile: " << tile.first << " value: " << tile.second << std::endl;
	//}

	//letter.TilesByNumber.erase(prev(letter.TilesByNumber.end()));

	//std::cout << "tile bag: " << letter.TilesByNumber.size() << std::endl;

	//for (auto &tile : letter.TilesByNumber)
	//{
	//	std::cout << "tile: " << tile.first << " value: " << tile.second << std::endl;
	//}

	//for (auto& tile : LetterTile::TileBag())
	//{
		//std::cout << "tile: " << tile->Letter << " points: " << tile->Points << std::endl;
	//}

	//std::cout << "tilebagcount: " << TileBag::GetTileBag().size() << std::endl;


	//TileRack rack;

	//TileBag::DrawTile(rack.RackTiles, 7);
	//
	//std::cout << "tilebagcount: " << TileBag::GetTileBag().size() << std::endl;


	//for (auto& tile : rack.RackTiles)
	//{
	//	std::cout << "tile: " << tile->Letter << " points: " << tile->Points << std::endl;
	//}


	//for (auto& tile : TileBag::GetTileBag())
	//{
	//	if (tile->Letter == "D")
	//	{
	//		std::cout << "tile: " << tile->Letter << " points: " << tile->Points << std::endl;
	//	}
	//}


	return 0;

}