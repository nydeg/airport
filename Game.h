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
	void event_handler(sf::Event* event);

	void drawDisplay();
	void drawAirplaneInfo();

	void setWindow(sf::RenderWindow* new_window) { window = new_window; }
	void setLevel(Level* new_level) { level = new_level; }
	void setBackground(string url_bg);

	void drawAirplanes();
	void updateAirplanes();

	//void event_handler(sf::Event* event);
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
	sf::Text __t_getAirplaneInfo() {return _t_airplaneInfo_; }

	vector<float> getDegrees() { return this->degrees;}


private:
	vector<float> degrees = {0, 90, 180, 270};
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
	sf::Texture _s_texture_approve;
	sf::RectangleShape _s_dismissButton;
	sf::Texture _s_texture_dismiss;

	//Airplane info
	sf::RectangleShape _s_airplaneInfo_;
	sf::Text _t_airplaneInfo_;


	// airplanes to draw
	sf::Image militaryImage;
	sf::Image airbusImage;
	sf::Image cornImage;

	sf::Texture cornTexture;
	sf::Texture airbusTexture;
	sf::Texture militaryTexture;

	vector<sf::Sprite> airplaneSprites;

	Display* display;
	Dispatcher* dispatcher;

	Airstrip* selectedAirstrip;

	int flag_approve = 0;

};

