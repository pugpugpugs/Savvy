#include "Event/EventHandler.h"
#include <Game/GameRender.h>
#include <iostream>


EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}

void EventHandler::HandleEvent(const sf::Event& event, const sf::RenderWindow& window)
{
	MouseEvents.IsReleased = false;

	switch (event.type)
	{
	case sf::Event::MouseButtonReleased:
	case sf::Event::MouseButtonPressed:
	case sf::Event::MouseMoved:
		HandleMouseEvent(event, window);
		break;
	default:
		break;
	}
}

bool EventHandler::HandleMouseEvent(const sf::Event& event, const sf::RenderWindow& window)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
		return MouseClickEvent(event, window);
	case sf::Event::MouseButtonReleased:
		return MouseReleaseEvent(event, window);
	case sf::Event::MouseMoved:
		return MouseMoveEvent(event, window);
	default:
		break;
	}
}

bool EventHandler::MouseClickEvent(const sf::Event& event, const sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Button::Left)
		{
			MouseEvents.IsLeftClicked = true;
			MouseEvents.MouseLeftClickCoords = sf::Vector2f(sf::Mouse::getPosition(window));
			//std::cout << "Left Clcik " << MouseEvents.IsLeftClicked << " move " << MouseEvents.MouseCoords.x << "," << MouseEvents.MouseCoords.y << std::endl;
			MouseEvents.MouseCoords = sf::Vector2f(sf::Mouse::getPosition(window));
		}
		return true;
	}

	return false;
}

bool EventHandler::MouseReleaseEvent(const sf::Event& event, const sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == sf::Mouse::Button::Left)
		{
			MouseEvents.IsLeftClicked = false;
			MouseEvents.IsReleased = true;
			//std::cout << "Left Clcik Release" << MouseEvents.IsReleased << std::endl;
			MouseEvents.MouseCoords = sf::Vector2f(sf::Mouse::getPosition(window));
			GameRender::DropSprite();
		}
		return true;
	}

	return false;
}

bool EventHandler::MouseMoveEvent(const sf::Event& event, const sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseMoved)
	{
		//std::cout << "Left: " << MouseEvents.IsLeftClicked << " Move " << MouseEvents.MouseCoords.x << " " << MouseEvents.MouseCoords.y << std::endl;
		MouseEvents.MouseCoords = sf::Vector2f(sf::Mouse::getPosition(window));

		if (MouseEvents.IsLeftClicked)
		{
			GameRender::DragSprite(MouseEvents.MouseLeftClickCoords, window);
		}
		return true;
	}

	return false;
}