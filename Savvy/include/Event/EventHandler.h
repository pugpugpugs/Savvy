#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

struct MouseEvents
{
	bool IsLeftClicked{ false };
	bool IsReleased{ false };
	sf::Vector2f MouseLeftClickCoords{ 0, 0 };
	sf::Vector2f MouseCoords{ 0,0 };
}; 

class EventHandler
{
public:
	EventHandler();
	~EventHandler();	
	void HandleEvent(const sf::Event& event, const sf::RenderWindow& window);
	//bool IsLeftClicked();
	//sf::Vector2f GetMouseLeftClickCoords();
	MouseEvents MouseEvents;

private:
	//bool _isLeftClicked;
	//sf::Vector2f _mouseCoordinates;
	//sf::Vector2f _mouseLeftClickCoords;
	bool HandleMouseEvent(const sf::Event& event, const sf::RenderWindow& window);
	bool MouseClickEvent(const sf::Event& event, const sf::RenderWindow& window);
	bool MouseReleaseEvent(const sf::Event& event, const sf::RenderWindow& window);
	bool MouseMoveEvent(const sf::Event& event, const sf::RenderWindow& window);
};


