#pragma once
#include <vector>
#include <memory>
#include "Tile/BoardTile.h"

class Game
{
public:
	std::vector<std::unique_ptr<BoardTile>> Board;
	std::vector<std::unique_ptr<LetterTile>> LetterBag;
	void Start();
	void CreateBoard();
	void CreateLetterBag();
	void CreateLetters();

};

