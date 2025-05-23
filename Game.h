#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class Level;

class Game
{
public:

	void setWindow(sf::RenderWindow* new_window) { window = new_window; }
	void setLevel(Level* new_level) { level = new_level; }
	void setBackground(string url_bg);

	sf::Sprite getBackground() { return background_game; }

	sf::RenderWindow* getWindow() { return window; }
private:
	sf::RenderWindow* window;
	Level* level;
	sf::Texture bg_texture;
	sf::Sprite background_game;
};

