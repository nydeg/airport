#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Game
{
public:
	void setWindow(sf::RenderWindow* new_window) { window = new_window; }

	sf::RenderWindow* getWindow() { return window; }
private:
	sf::RenderWindow* window;
};

