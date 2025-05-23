#include "Game.h"
#define DISPLAYS_CHARACTER_SIZE 17

#define START_SHAPES_X 1600
#define START_SHAPES_Y 0
#define START_TEXTS_X 1610
#define START_TEXTS_Y 35
void Game::renderDisplay(string fontPath) {

    //create Display
    Display* tmp = new Display(&level->getAirplanes(), &level->getAirstrips());
    display = tmp;

    font.loadFromFile(fontPath);

    //create currTimePart
    _s_currTime_.setSize(sf::Vector2f(300, 100));
    _s_currTime_.setFillColor(sf::Color::Black);
    _s_currTime_.setPosition(START_SHAPES_X, START_SHAPES_Y);

    _t_currTime_.setString("Curr time: " + display->d_getCurrTime().getStringDate());
    _t_currTime_.setFont(font);
    _t_currTime_.setCharacterSize(DISPLAYS_CHARACTER_SIZE);
    _t_currTime_.setFillColor(sf::Color::White);
    _t_currTime_.setPosition(START_TEXTS_X, START_TEXTS_Y);

    //create Score/Fine part

    _s_ScoreAndFine_.setSize(sf::Vector2f(300, 100));
    _s_ScoreAndFine_.setFillColor(sf::Color::Yellow);
    _s_ScoreAndFine_.setPosition(START_SHAPES_X, START_SHAPES_Y+100);

    _t_score_.setString("SCORE: ");
    _t_score_.setFont(font);
    _t_score_.setCharacterSize(DISPLAYS_CHARACTER_SIZE);
    _t_score_.setFillColor(sf::Color::Black);
    _t_score_.setPosition(START_TEXTS_X, START_TEXTS_Y+100);

    _t_fine_.setString("FINE: ");
    _t_fine_.setFont(font);
    _t_fine_.setCharacterSize(DISPLAYS_CHARACTER_SIZE);
    _t_fine_.setFillColor(sf::Color::Black);
    _t_fine_.setPosition(START_TEXTS_X + 170, START_TEXTS_Y+100);

    //create TimeTable Title

    _s_titleOfTimeTable_.setSize(sf::Vector2f(300, 100));
    _s_titleOfTimeTable_.setFillColor(sf::Color::White);
    _s_titleOfTimeTable_.setPosition(START_SHAPES_X, START_SHAPES_Y+200);

    _t_titleOfTimeTable_.setString("Time Table");
    _t_titleOfTimeTable_.setFont(font);
    _t_titleOfTimeTable_.setCharacterSize(DISPLAYS_CHARACTER_SIZE + 8);
    _t_titleOfTimeTable_.setFillColor(sf::Color::Black);
    _t_titleOfTimeTable_.setPosition(START_TEXTS_X + 70, START_TEXTS_Y + 200);

    //create time Table
    for(int i = 0; i < level->getAirplanes().size(); ++i) {
        //shapes
        sf::RectangleShape* newShape = new sf::RectangleShape;
        newShape->setSize(sf::Vector2f(300, 50));
        newShape->setFillColor(sf::Color::Black);
        newShape->setPosition(START_SHAPES_X, START_SHAPES_Y + 300 + 50 * i);
        _s_timeTable_.push_back(newShape);

        //texts
        string type;
        if(level->getAirplanes()[i]->getStatus() == "awaiting_takeoff")
            type = "V";
        if(level->getAirplanes()[i]->getStatus() == "awaiting_boarding")
            type = "P";

        sf::Text* newText = new sf::Text;
        newText->setString(to_string(level->getAirplanes()[i]->getBoardNumber()) + " " + type + " " + level->getAirplanes()[i]->getTimeOfAction().getStringDate());
        newText->setFont(font);
        newText->setCharacterSize(DISPLAYS_CHARACTER_SIZE);
        newText->setFillColor(sf::Color::White);
        newText->setPosition(START_TEXTS_X, START_TEXTS_Y + 300 + 50 * i - 20);
        _t_timeTable_.push_back(newText);
    }

    //create airplane info
    _s_airplaneInfo_.setSize(sf::Vector2f(300, 350));
    _s_airplaneInfo_.setFillColor(sf::Color::White);
    _s_airplaneInfo_.setPosition(START_SHAPES_X, START_SHAPES_Y + 550);

    //create buttons
    _s_approveButton.setSize(sf::Vector2f(150, 150));
    _s_approveButton.setFillColor(sf::Color::Green);
    _s_approveButton.setPosition(START_SHAPES_X, 850);

    _s_dismissButton.setSize(sf::Vector2f(150, 150));
    _s_dismissButton.setFillColor(sf::Color::Red);
    _s_dismissButton.setPosition(START_SHAPES_X + 150 , 850);


}

void Game::updateScoreAndFine() {
    //create time Table

    for(int i = 0; i < _s_timeTable_.size(); ++i) {
        delete _s_timeTable_[i];
    }
    _s_timeTable_.clear();

    for(int i = 0; i < _t_timeTable_.size(); ++i) {
        delete _t_timeTable_[i];
    }
    _t_timeTable_.clear();

    for(int i = 0; i < level->getAirplanes().size(); ++i) {
        //shapes
        sf::RectangleShape* newShape = new sf::RectangleShape;
        newShape->setSize(sf::Vector2f(300, 50));
        newShape->setFillColor(sf::Color::Black);
        newShape->setPosition(START_SHAPES_X, START_SHAPES_Y + 300 + 50 * i);
        _s_timeTable_.push_back(newShape);

        //texts
        string type;
        if(level->getAirplanes()[i]->getStatus() == "awaiting_takeoff")
            type = "V";
        if(level->getAirplanes()[i]->getStatus() == "awaiting_boarding")
            type = "P";

        sf::Text* newText = new sf::Text;
        newText->setString(to_string(level->getAirplanes()[i]->getBoardNumber()) + " " + type + " " + level->getAirplanes()[i]->getTimeOfAction().getStringDate());
        newText->setFont(font);
        newText->setCharacterSize(DISPLAYS_CHARACTER_SIZE);
        newText->setFillColor(sf::Color::White);
        newText->setPosition(START_TEXTS_X, START_TEXTS_Y + 300 + 50 * i - 20);
        _t_timeTable_.push_back(newText);
    }
}

void Game::updateSchedule() {

}

void Game::updateDisplay() {
    //Date tmp;
    //display->setCurrDate(tmp);
    display->setCurrDate(display->d_getCurrTime()+1);
    _t_currTime_.setString("Curr time: " + display->d_getCurrTime().getStringDate());
    _t_currTime_.setFont(font);
    _t_currTime_.setCharacterSize(DISPLAYS_CHARACTER_SIZE);
    _t_currTime_.setFillColor(sf::Color::White);
    _t_currTime_.setPosition(START_TEXTS_X, START_TEXTS_Y);

    //this->updateSchedule();

}

void Game::drawDisplay() {
    //current time
    getWindow()->draw(__s_getCurrTimeShape__());
    getWindow()->draw(__t_getCurrTime__());
    //score/fine
    getWindow()->draw(__s_getScoreAndFineShape__());
    getWindow()->draw(__t_getScore__());
    getWindow()->draw(__t_getFine__());
    //timetable title
    getWindow()->draw(__s_getTimeTableTitle__());
    getWindow()->draw(__t_getTimeTableTitle__());

    //timeTable (first five)
    if(getLevel()->getAirplanes().size() < 5)
        for(int i = 0; i < getLevel()->getAirplanes().size(); ++i) {
            getWindow()->draw(*__s_getTimeTableShape__()[i]);
            getWindow()->draw(*__t_getTimeTableText__()[i]);
        }
    else {
        for(int i = 0; i < 5; ++i) {
            getWindow()->draw(*__s_getTimeTableShape__()[i]);
            getWindow()->draw(*__t_getTimeTableText__()[i]);
        }
    }
    //airplaneInfo
    getWindow()->draw(__s_getAirplaneInfo__());
    //buttons
    getWindow()->draw(__s_getApproveButton__());
    getWindow()->draw(__s_getDismissButton__());
}

void Game::setBackground(string url_bg){
	bg_texture.loadFromFile(url_bg);
	background.setTexture(bg_texture);
}
