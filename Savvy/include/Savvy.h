#pragma once
#include "Game/Game.h"

namespace sve
{
	enum class Layout
	{
		Standard
	};
	enum class TileBag
	{
		Standard
	};

	struct Options
	{
		Layout layout = Layout::Standard;
		TileBag boardtype = TileBag::Standard;
	};

	class Savvy
	{
	public:
		void Start(Options options);
	private:
		Game game;
	};
}