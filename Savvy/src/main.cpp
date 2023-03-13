#include <iostream>
#include <SFML/Graphics.hpp>
#include <Game/Game.h>
#include <Game/GameRender.h>
#include <Board/NormalTile.h>
#include <Board/BoardTileFactory.h>
#include <Common/Enums.h>
#include <Board/Layout.h>
#include <Event/EventHandler.h>
#include <State/MainMenuState.h>


int main() 
{
	//sf::ContextSettings settings;
	//settings.antialiasingLevel = 8;
	//sf::RenderWindow window(sf::VideoMode(1600, 900), "Savvy", sf::Style::Default, settings);
	//window.setFramerateLimit(60);

	Game game;

	game.Initialize();

	game.Start();

	//sf::Event event;
	//EventHandler handler;
	//sf::Vector2f mousePosition;
	//bool isMouseClick = false;

	//while (window.isOpen())
	//{
	//	while (window.pollEvent(event))
	//	{
	//		handler.HandleEvent(event, window);

	//		//if (handler.MouseEvents.IsLeftClicked)
	//		//{
	//		//	GameRender::HandleClickEvent(handler.MouseEvents.MouseLeftClickCoords, window);
	//		//}
	//		//else if (handler.MouseEvents.IsReleased)
	//		//{
	//		//	GameRender::HandleReleaseEvent(handler.MouseEvents.MouseCoords, window);
	//		//}
	//		//switch (event.type)
	//		//{
	//		//case sf::Event::KeyPressed:
	//		//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	//		//	{
	//		//		game.boardTiles[0].release();
	//		//		game.boardTiles[0] = BoardTileFactory::CreateBoardTile(Enums::NormalTile);
	//		//		game.boardTiles[0]->SetPosition(Layout::OffsetX(0), Layout::OffsetY(0));
	//		//		GameRender::UpdateSprite(*game.boardTiles[0]);
	//		//	}
	//		//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	//		//	{
	//		//		window.close();
	//		//	}
	//		//	break;
	//		//case sf::Event::Closed:
	//		//	window.close();
	//		//	break;
	//		//case sf::Event::MouseButtonPressed:
	//		//	isMouseClick = true;
	//		//	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	//		//	{
	//		//		mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
	//		//		GameRender::HandleClickEvent(mousePosition, window);
	//		//	}
	//		//	break;
	//		//case sf::Event::MouseButtonReleased:
	//		//	isMouseClick = false;
	//		//	GameRender::HandleReleaseEvent(mousePosition, window);
	//		//	break;
	//		//default:
	//		//	if (isMouseClick)
	//		//	{
	//		//		GameRender::HandleClickEvent(mousePosition, window);
	//		//	}
	//		//	break;
	//		//}
	//	}

	//	window.clear(sf::Color::Black);

	//	GameRender::Draw(window);

	//	window.display();
	//}

	return 0;

}

