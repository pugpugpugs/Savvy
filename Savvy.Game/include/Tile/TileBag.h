#pragma once
#include <map>
#include <memory>
#include <vector>
#include <Tile/LetterTile.h>

class TileBag
{
public:
	TileBag();
	static std::map<char, int> TilesByNumber;
	static std::map<char, int> TilesByPoints;
	static std::vector<std::unique_ptr<LetterTile>>& GetTileBag();
	static void DrawTile(std::vector<std::unique_ptr<LetterTile>>& rack, int numberOfTiles);
private:
	static std::vector<std::unique_ptr<LetterTile>> _tileBag;
	static bool _isFilled;
	static std::map<char, int> SetTilesByNumber();
	static std::map<char, int> SetTilesByPoints();
	static void FillTileBag();
};