#include "Game.h"

void Game::setBackground(string url_bg){
	bg_texture.loadFromFile(url_bg);
	background_game.setTexture(bg_texture);
}
