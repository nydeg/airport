#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <SFML/Graphics.hpp>

class Game;

using namespace std;

class Menu
{
public:
	Menu(string font_url, string bg_url) {
		font.loadFromFile(font_url);
		bg_texture.loadFromFile(bg_url);
		background.setTexture(bg_texture);
		background.scale(0.666,0.666);
	}
    //~Menu();

    sf::Text getinputText() { return inputText; }
    sf::Text getTitle() { return title; }
    sf::RectangleShape getButton() { return button; }
    sf::RectangleShape* getInputBox() { return &inputBox; }
    sf::Sprite getBackground(){ return background; }

	sf::RectangleShape getExit(){return exit;}

    void renderInterface();
    void event_handler(sf::RenderWindow* window, sf::Event* event, Game* game);

private:
	sf::Font font;
	string playerName;
	sf::Texture bg_texture;
	sf::Sprite background;

    sf::Text inputText;
    sf::Text title;
    sf::RectangleShape inputBox;
    
    sf::Texture startGame_texture;
    sf::RectangleShape button;

	sf::Texture exitTexture;
	sf::RectangleShape exit;
};

