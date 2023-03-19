#include "Game/Game.h"
#include "Board/BoardLayout.h"
#include "Tile/TileFactory.h"
#include "Constants.h"

void Game::Start()
{
	CreateBoard();
	CreateLetters();
	CreateLetterBag();
}

void Game::CreateBoard()
{
	NormalBoard normalBoard;

	int i = 0;
	for (int y = 0; y < normalBoard.height; y++)
	{
		for (int x = 0; x < normalBoard.width; x++)
		{
			std::unique_ptr<BoardTile> tile = TileFactory::CreateBoardTile(normalBoard.standardBoardMap[i]);

			tile->SetPosition(sf::Vector2f(x * tile->GetSpriteSize().x * (GAME_TILE_SIZE / tile->GetSpriteSize().x),
									       y * tile->GetSpriteSize().y * (GAME_TILE_SIZE / tile->GetSpriteSize().y)));

			sve::GameRender::RegisterSprite(*tile);

			Board.push_back(std::move(tile));

			i++;
		}
	}
}

void Game::CreateLetterBag()
{
	for (size_t i = 0; i < 27; i++)
	{
		std::unique_ptr<LetterTile> tile = std::make_unique<LetterTile>();
		tile->Points = i;
		LetterBag.push_back(std::move(tile));
	}
}

void Game::CreateLetters()
{

}