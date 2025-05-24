#include "Game.h"

#include "Dispatcher.h"
#define DISPLAYS_CHARACTER_SIZE 17

#define START_SHAPES_X 1600
#define START_SHAPES_Y 0
#define START_TEXTS_X 1610
#define START_TEXTS_Y 35

void Game::event_handler(sf::Event* event) {
    if (event->type == sf::Event::Closed) {
        getWindow()->close();
    }

    //cout << level->getAirplanes().front()->getStatus() << "\n";

    if (event->type == sf::Event::MouseButtonReleased && (level->getAirplanes().front()->getStatus() == "requesting_boarding" || level->getAirplanes().front()->getStatus() == "requesting_takeoff")) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

        //cout << 1 << "\n";
        // pressed approve button

        if (_s_approveButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            cout << "APPROVE" << endl;
            flag_approve = 1;
        }
        else if (_s_dismissButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {

            dispatcher->setFine(dispatcher->getFine() + 1);
            updateScoreAndFine();

            //cout << level->getAirplanes().size() << "\n";
            cout << "I DON'\t KNOW " << level->getAirplanes().front()->getStatus()<< endl;
            // pressed denied button
            //cout << 1 << endl;
            if(level->getAirplanes().front()->getStatus() == "requesting_boarding") {
                if(level->getAirplanes().front()->getMaxLaps() != 0) {
                    level->getAirplanes().front()->setMaxLaps(level->getAirplanes().front()->getMaxLaps() - 1); // уменьшаем кол-во кругов!!!
                }
                else {
                    cout << "\n\nYOU LOOSE!!!!!!\n\n";
                }
                level->getAirplanes().front()->setStatus("awaiting_boarding");
            }
            if(level->getAirplanes().front()->getStatus() == "requesting_takeoff") {
                level->getAirplanes().front()->setStatus("awaiting_takeoff");

            }
            //cout << 2 << endl;
            //Date prevTime = level->getAirplanes().front()->getTimeOfAction();
            level->getAirplanes().front()->setTimeOfAction(level->getAirplanes().front()->getTimeOfAction() + 120);

            flag_approve = 0;
        }

        for(int i = 0; i < level->getAirstrips().size(); ++i) {
            if(level->getAirstrips()[i]->__s_getAirstripShape__().getGlobalBounds().contains(mousePos.x, mousePos.y) && flag_approve) {
                if (level->getAirplanes().front()->getStatus() == "requesting_boarding") {
                    level->getAirplanes().front()->setStatus("boarding_startPoint");
                    selectedAirstrip = level->getAirstrips()[i];

                    dispatcher->setCurrentScore(dispatcher->getCurrentScore() + 1);
                    updateScoreAndFine();

                    flag_approve = 0;
                }
                else if (level->getAirplanes().front()->getStatus() == "requesting_takeoff") {
                    level->getAirplanes().front()->setStatus("take_off");
                    selectedAirstrip = level->getAirstrips()[i];

                    dispatcher->setCurrentScore(dispatcher->getCurrentScore() + 1);
                    updateScoreAndFine();

                    flag_approve = 0;
                }
            }
        }

    }
}


void Game::updateGame() {

    //airstrips drawing
    /*
    for(int i = 0; i < level->getAirstrips().size(); ++i) {
        getWindow()->draw(level->getAirstrips()[i]->__s_getAirstripShape__());
    }
    */


    for(int i = 0; i < level->getAirplanes().size(); ++i) {
        if(display->d_getCurrTime() == level->getAirplanes()[i]->getTimeOfAction()) {
            if(level->getAirplanes()[i]->getStatus() == "awaiting_boarding")
                level->getAirplanes()[i]->setStatus("requesting_boarding");
            if(level->getAirplanes()[i]->getStatus() == "awaiting_takeoff")
                level->getAirplanes()[i]->setStatus("requesting_takeoff");
        }
    }

    //updateAirplanes();

    if (level->getAirplanes().front()->getStatus() == "requesting_takeoff" || level->getAirplanes().front()->getStatus() == "requesting_boarding") return;

    //cout << level->getAirplanes().front()->getStatus() << "\n";

    if(level->getAirplanes().front()->getStatus() == "awaiting_boarding" || level->getAirplanes().front()->getStatus() == "awaiting_takeoff" ) {
        updateDisplay(); //Curr time += 1
        //updateAirplanes();
    }

updateAirplanes();

/*
    for(int i = 0; i < level->getAirplanes().size(); ++i) {
        level->getAirplanes()[i]->work(level, dispatcher, selectedAirstrip, level->getAirplanes()[i]->getX(), level->getAirplanes()[i]->getY());
    }

    */
    //updateAirplanes();
}

void Game::renderDisplay(string fontPath) {

    //create Display
    Display* tmp = new Display(&level->getAirplanes(), &level->getAirstrips());
    display = tmp;
    display->setCurrDate(level->getAirplanes().front()->getTimeOfAction());

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

    _t_score_.setString("SCORE: " + dispatcher->getCurrentScore());
    _t_score_.setFont(font);
    _t_score_.setCharacterSize(DISPLAYS_CHARACTER_SIZE);
    _t_score_.setFillColor(sf::Color::Black);
    _t_score_.setPosition(START_TEXTS_X, START_TEXTS_Y+100);

    _t_fine_.setString("FINE: " + dispatcher->getFine());
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
    _s_texture_approve.loadFromFile("./assets/Approve.png");
    _s_approveButton.setTexture(&_s_texture_approve);
    //_s_approveButton.setFillColor(sf::Color::Green);
    _s_approveButton.setSize(sf::Vector2f(150, 150));
    _s_approveButton.setPosition(START_SHAPES_X, 880);
    _s_approveButton.setScale({ 1,0.8 });

    _s_texture_dismiss.loadFromFile("./assets/Denied.png");
    _s_dismissButton.setTexture(&_s_texture_dismiss);
    _s_dismissButton.setSize(sf::Vector2f(150, 150));
    //_s_dismissButton.setFillColor(sf::Color::Red);
    _s_dismissButton.setPosition(START_SHAPES_X + 150 , 880);
    _s_dismissButton.setScale({ 1,0.8 });

    // airplanes to draw
    militaryImage.loadFromFile("./assets/military.png");
    airbusImage.loadFromFile("./assets/airbus.png");
    cornImage.loadFromFile("./assets/corn.png");

    militaryTexture.loadFromImage(militaryImage);
    airbusTexture.loadFromImage(airbusImage);
    cornTexture.loadFromImage(cornImage);

}

void Game::updateScoreAndFine() {
    _s_ScoreAndFine_.setSize(sf::Vector2f(300, 100));
    _s_ScoreAndFine_.setFillColor(sf::Color::Yellow);
    _s_ScoreAndFine_.setPosition(START_SHAPES_X, START_SHAPES_Y+100);

    _t_score_.setString("SCORE: " + to_string(dispatcher->getCurrentScore()));
    _t_score_.setFont(font);
    _t_score_.setCharacterSize(DISPLAYS_CHARACTER_SIZE);
    _t_score_.setFillColor(sf::Color::Black);
    _t_score_.setPosition(START_TEXTS_X, START_TEXTS_Y+100);

    _t_fine_.setString("FINE: " + to_string(dispatcher->getFine()));
    _t_fine_.setFont(font);
    _t_fine_.setCharacterSize(DISPLAYS_CHARACTER_SIZE);
    _t_fine_.setFillColor(sf::Color::Black);
    _t_fine_.setPosition(START_TEXTS_X + 170, START_TEXTS_Y+100);
}

void Game::updateSchedule() {
    //create time Table

    for(int i = 0; i < _s_timeTable_.size(); ++i) {
        delete _s_timeTable_[i];
    }
    _s_timeTable_.clear();

    for(int i = 0; i < _t_timeTable_.size(); ++i) {
        delete _t_timeTable_[i];
    }
    _t_timeTable_.clear();

    level->scheduleSort();

    for(int i = 0; i < level->getAirplanes().size(); ++i) {
        //shapes
        sf::RectangleShape* newShape = new sf::RectangleShape;
        newShape->setSize(sf::Vector2f(300, 50));
        newShape->setFillColor(sf::Color::Black);
        newShape->setPosition(START_SHAPES_X, START_SHAPES_Y + 300 + 50 * i);
        _s_timeTable_.push_back(newShape);

        //texts
        string type;
        if(level->getAirplanes()[i]->getStatus() == "awaiting_takeoff" || level->getAirplanes()[i]->getStatus() == "requesting_takeoff")
            type = "V";
        if(level->getAirplanes()[i]->getStatus() == "awaiting_boarding" || level->getAirplanes()[i]->getStatus() == "requesting_boarding")
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
    if(!level->getAirplanes().empty()) {
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
    }
    //airplaneInfo
    getWindow()->draw(__s_getAirplaneInfo__());
    if(display->d_getCurrTime() == level->getAirplanes().front()->getTimeOfAction()) {
        drawAirplaneInfo();
    }
    //buttons
    getWindow()->draw(__s_getApproveButton__());
    getWindow()->draw(__s_getDismissButton__());
}

void Game::drawAirplaneInfo() {

    if(level->getAirplanes().front()->getStatus() == "requesting_takeoff")
        _t_airplaneInfo_.setString("Flight " + to_string(level->getAirplanes().front()->getBoardNumber()) + "\nrequests permission to \ntakeoff");
    if(level->getAirplanes().front()->getStatus() == "requesting_boarding")
        _t_airplaneInfo_.setString("Flight " + to_string(level->getAirplanes().front()->getBoardNumber()) + " \nrequests permission to \nboarding" + "\nAdditional laps: " + to_string(level->getAirplanes().front()->getMaxLaps()));
    _t_airplaneInfo_.setFont(font);
    _t_airplaneInfo_.setCharacterSize(DISPLAYS_CHARACTER_SIZE + 3 );
    _t_airplaneInfo_.setFillColor(sf::Color::Black);
    _t_airplaneInfo_.setPosition(START_TEXTS_X, START_TEXTS_Y + 560);

    getWindow()->draw(_t_airplaneInfo_);


}

void Game::setBackground(string url_bg){
	bg_texture.loadFromFile(url_bg);
	background.setTexture(bg_texture);
}

void Game::updateAirplanes() {

    auto win = getWindow();

    auto level = getLevel();
    auto airplanes = level->getAirplanes();

    if (airplaneSprites.size() != airplanes.size()) {
        airplaneSprites.clear();
        for (auto& airplane : airplanes) {
            sf::Sprite plane;
            string type = airplane->getType();

            if (type == "military") {
                plane.setTexture(militaryTexture);
            } else if (type == "cargo") {
                plane.setTexture(airbusTexture);
            } else if (type == "civilian") {
                plane.setTexture(cornTexture);
            }

            plane.scale(sf::Vector2f(0.5f, 0.5f));
            plane.setPosition(airplane->getX(), airplane->getY());

            airplaneSprites.push_back(plane);
        }
    }
    /*
    for (auto& airplane : airplanes) {
        airplane->work(level, dispatcher, level->getAirstrips()[0], airplane->getX(), airplane->getY());
        //cout << "huy" << endl;
    }
    */

    for (auto& airplane : airplanes) {
        airplane->work(level, dispatcher, level->getAirstrips()[0], airplane->getX(), airplane->getY());
    }

    for (int i = 0; i < airplaneSprites.size(); i++) {
        airplaneSprites[i].setPosition(airplanes[i]->getX(), airplanes[i]->getY());
    }

    for (auto planeSprite : airplaneSprites) {
        win->draw(planeSprite);
    }

    //cout << airplanes[0]->getX() << " " << airplanes[0]->getY() << endl;
}

void Game::drawAirplanes() {
    auto win = getWindow();

    for (auto planeSprite : airplaneSprites) {
        win->draw(planeSprite);
    }
}
