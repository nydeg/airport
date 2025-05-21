#include "Game.h"


void Game::renderDisplay(string fontPath) {

    Display* tmp = new Display(&level->getAirplanes(), &level->getAirstrips());
    display = tmp;

    font.loadFromFile(fontPath);

    _s_currTime_.setSize(sf::Vector2f(500, 100));
    _s_currTime_.setFillColor(sf::Color::Black);
    _s_currTime_.setPosition(1200, 0);

    _t_currTime_.setString("Curr time: " + display->d_getCurrTime().getStringDate());
    _t_currTime_.setFont(font);
    _t_currTime_.setCharacterSize(30);
    _t_currTime_.setFillColor(sf::Color::White);
    _t_currTime_.setPosition(1210, 35);








}

void Game::updateDisplay() {
    //Date tmp;
    //display->setCurrDate(tmp);
    display->setCurrDate(display->d_getCurrTime()+1);
    _t_currTime_.setString("Curr time: " + display->d_getCurrTime().getStringDate());
    _t_currTime_.setFont(font);
    _t_currTime_.setCharacterSize(30);
    _t_currTime_.setFillColor(sf::Color::White);
    _t_currTime_.setPosition(1210, 35);
}
