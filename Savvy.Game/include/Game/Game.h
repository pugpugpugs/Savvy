#pragma once
#include <vector>
#include <memory>
#include "Tile/BoardTile.h"
#include "Tile/TileRack.h"

class Game
{
public:
	std::vector<std::unique_ptr<BoardTile>> Board;
	std::vector<std::unique_ptr<LetterTile>> LetterBag;
	std::vector<std::unique_ptr<LetterTile>> Letters;
	TileRack Rack;
	Game();
	void Start();
	void CreateBoard();
	void CreateLetterBag();
	void CreateLetters();
	void Test();
	void CreateRacks();

};

