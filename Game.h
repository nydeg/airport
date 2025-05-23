#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Display.h"
#include "Level.h"


using namespace std;

class Level;
class Display;
class Dispatcher;

class Game
{
public:


	void updateGame();

	void renderDisplay(string fontPath);
	void updateScoreAndFine();
	void updateSchedule();
	void updateDisplay();

	void drawDisplay();

	void setWindow(sf::RenderWindow* new_window) { window = new_window; }
	void setLevel(Level* new_level) { level = new_level; }
	void setBackground(string url_bg);

	//setters

	void setDispatcher(Dispatcher* tmp){dispatcher = tmp;}


	//access
	Level* getLevel(){return level;}
	sf::Sprite getBackground(){ return background; }
	sf::RenderWindow* getWindow() { return window; }

	sf::Text __t_getCurrTime__() {return _t_currTime_;}
	sf::RectangleShape __s_getCurrTimeShape__() {return _s_currTime_;}

	sf::Text __t_getScore__(){return _t_score_;}
	sf::Text __t_getFine__(){return _t_fine_;}
	sf::RectangleShape __s_getScoreAndFineShape__(){return _s_ScoreAndFine_;}

	sf::Text __t_getTimeTableTitle__(){return _t_titleOfTimeTable_;}
	sf::RectangleShape __s_getTimeTableTitle__(){return _s_titleOfTimeTable_;}

	vector<sf::RectangleShape*>& __s_getTimeTableShape__(){return _s_timeTable_;}
	vector<sf::Text*>& __t_getTimeTableText__() {return _t_timeTable_;}

	sf::RectangleShape __s_getApproveButton__() {return _s_approveButton;}
	sf::RectangleShape __s_getDismissButton__() {return _s_dismissButton;}

	sf::RectangleShape __s_getAirplaneInfo__() {return _s_airplaneInfo_; }
private:
	sf::RenderWindow* window;
	sf::Texture bg_texture;
	sf::Sprite background;
	Level* level;

	//CurrentTime
	sf::Font font;
	sf::Text _t_currTime_;
	sf::RectangleShape _s_currTime_;

	//Score/Fine
	sf::RectangleShape _s_ScoreAndFine_;
	sf::Text _t_score_; //from dispatcher
	sf::Text _t_fine_;


	//TimeTable
	sf::RectangleShape _s_titleOfTimeTable_;
	sf::Text _t_titleOfTimeTable_;

	vector<sf::RectangleShape*> _s_timeTable_;
	vector<sf::Text*> _t_timeTable_;

	//buttons
	sf::RectangleShape _s_approveButton;
	sf::RectangleShape _s_dismissButton;

	//Airplane info
	sf::RectangleShape _s_airplaneInfo_;

	Display* display;
	Dispatcher* dispatcher;

};

