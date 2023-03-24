#include "Tile/TileBag.h"

std::vector<std::unique_ptr<LetterTile>> TileBag::_tileBag;

bool TileBag::_isFilled = false;

TileBag::TileBag()
{
}

void TileBag::DrawTile(std::vector<std::unique_ptr<LetterTile>>& rack, int numberOfTiles)
{
	for (size_t i = 0; i < numberOfTiles; i++)
	{
		int random = std::rand() % TilesByNumber.size();

		rack.push_back(std::move(_tileBag[random]));

		_tileBag.erase(_tileBag.begin() + random);
	}
}

std::vector<std::unique_ptr<LetterTile>>& TileBag::GetTileBag()
{
	if (_isFilled == false)
	{
		FillTileBag();
	}

	return TileBag::_tileBag;
}

void TileBag::FillTileBag()
{
	for (auto& tile : TileBag::TilesByNumber)
	{
		for (size_t i = 0; i < tile.second; i++)
		{
			auto pTile = std::make_unique<LetterTile>();
			pTile->Points = TileBag::TilesByPoints[tile.first];
			pTile->Letter = tile.first;
			TileBag::_tileBag.push_back(move(pTile));
		}
	}
	_isFilled = true;
}

std::map<char, int> TileBag::TilesByNumber = SetTilesByNumber();

std::map<char, int> TileBag::SetTilesByNumber()
{
	std::map<char, int> tilesInBag;
	tilesInBag['A'] = 9;
	tilesInBag['B'] = 2;
	tilesInBag['C'] = 2;
	tilesInBag['D'] = 4;
	tilesInBag['E'] = 12;
	tilesInBag['F'] = 2;
	tilesInBag['G'] = 3;
	tilesInBag['H'] = 2;
	tilesInBag['I'] = 9;
	tilesInBag['J'] = 1;
	tilesInBag['K'] = 1;
	tilesInBag['L'] = 4;
	tilesInBag['M'] = 2;
	tilesInBag['N'] = 6;
	tilesInBag['O'] = 8;
	tilesInBag['P'] = 2;
	tilesInBag['Q'] = 1;
	tilesInBag['R'] = 6;
	tilesInBag['S'] = 4;
	tilesInBag['T'] = 6;
	tilesInBag['U'] = 4;
	tilesInBag['V'] = 2;
	tilesInBag['W'] = 2;
	tilesInBag['X'] = 1;
	tilesInBag['Y'] = 2;
	tilesInBag['Z'] = 1;
	tilesInBag['_'] = 2;

	return tilesInBag;
}

std::map<char, int> TileBag::TilesByPoints = SetTilesByPoints();

std::map<char, int> TileBag::SetTilesByPoints()
{
	std::map<char, int> tilePoints;
	tilePoints['A'] = 1;
	tilePoints['B'] = 3;
	tilePoints['C'] = 3;
	tilePoints['D'] = 2;
	tilePoints['E'] = 1;
	tilePoints['F'] = 4;
	tilePoints['G'] = 2;
	tilePoints['H'] = 4;
	tilePoints['I'] = 1;
	tilePoints['J'] = 8;
	tilePoints['K'] = 5;
	tilePoints['L'] = 1;
	tilePoints['M'] = 3;
	tilePoints['N'] = 1;
	tilePoints['O'] = 1;
	tilePoints['P'] = 3;
	tilePoints['Q'] = 10;
	tilePoints['R'] = 1;
	tilePoints['S'] = 1;
	tilePoints['T'] = 1;
	tilePoints['U'] = 1;
	tilePoints['V'] = 4;
	tilePoints['W'] = 4;
	tilePoints['X'] = 8;
	tilePoints['Y'] = 4;
	tilePoints['Z'] = 10;
	tilePoints['_'] = 0;

	return tilePoints;
}