#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Display.h"
#include "Level.h"


using namespace std;

class Level;
class Display;

class Game
{
public:



	void renderDisplay(string fontPath);
	void updateDisplay();


	void setWindow(sf::RenderWindow* new_window) { window = new_window; }
	void setLevel(Level* new_level) { level = new_level; }
	void setBackground(string path) {
		bg_texture.loadFromFile(path);
		background.setTexture(bg_texture);
	}

	//access
	Level* getLevel(){return level;}
	sf::Sprite getBackground(){ return background; }
	sf::RenderWindow* getWindow() { return window; }
	sf::Text __t_getCurrTime__() {return _t_currTime_;}
	sf::RectangleShape __s_getCurrTimeShape__() {return _s_currTime_;}

private:
	sf::RenderWindow* window;
	sf::Texture bg_texture;
	sf::Sprite background;
	Level* level;

	sf::Font font;
	sf::Text _t_currTime_;
	sf::RectangleShape _s_currTime_;

	Display* display;

};

