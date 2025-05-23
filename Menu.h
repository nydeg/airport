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
	}
    //~Menu();

    sf::Text getinputText() { return inputText; }
    sf::Text getTitle() { return title; }
    sf::Text getButtonText() { return buttonText; }
    sf::RectangleShape getButton() { return button; }
    sf::RectangleShape getInputBox() { return inputBox; }
    sf::Sprite getBackground(){ return background; }

    void renderInterface();
    void event_handler(sf::RenderWindow* window, sf::Event* event, Game* game);

private:
	sf::Font font;
	string playerName;
	sf::Texture bg_texture;
	sf::Sprite background;
    sf::Text inputText;
    sf::RectangleShape button;
    sf::Text title;
    sf::RectangleShape inputBox;
    sf::Text buttonText;
};

