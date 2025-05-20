#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Level;

class Game
{
public:
	void setWindow(sf::RenderWindow* new_window) { window = new_window; }
	void setLevel(Level* new_level) { level = new_level; }

	sf::RenderWindow* getWindow() { return window; }
private:
	sf::RenderWindow* window;
	Level* level;
};

