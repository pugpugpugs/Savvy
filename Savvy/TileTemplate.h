#pragma once
//#include "BoardTiles/BoardTile.h"

template <class T>
class TileTemplate //: public BoardTile
{

public:
	static size_t id;
};

template <class T>
size_t TileTemplate<T>::id;

