#include "Menu.h"
#include "Game.h"
#include "Level.h"
#include "Dispatcher.h"


//Menu::~Menu()
//{
//    delete &font;
//    delete &playerName;
//    delete &bg_texture;
//    delete &background;
//    delete &inputText;
//    delete &button;
//    delete &title;
//    delete &inputBox;
//    delete &buttonText;
//    cout << "tripi tropa" << endl;
//}

void Menu::renderInterface(){

    //sf::Text title("ENTER YOUR NAME", font, 40);
    //title.setString("ENTER YOUR NAME");
    //title.setFont(font);
    //title.setCharacterSize(40);
    //title.setFillColor(sf::Color::White);
    //title.setPosition(250, 200);

    //sf::RectangleShape inputBox(sf::Vector2f(400, 50));
    inputBox.setSize(sf::Vector2f(550, 70));
    inputBox.setFillColor(sf::Color::Transparent);
    inputBox.setOutlineThickness(2);
    inputBox.setOutlineColor(sf::Color::White);
    inputBox.setPosition(60, 480);

    inputText.setString("");
    inputText.setFont(font);
    inputText.setCharacterSize(30);
    inputText.setFillColor(sf::Color::White);
    inputText.setPosition(70, 490);


    startGame_texture.loadFromFile("./assets/ENTER.png");
    button.setTexture(&startGame_texture);
    button.setSize(sf::Vector2f(175, 96));
    button.setPosition(75, 627);

    //sf::Text buttonText("ENTER", font, 30);
    /*buttonText.setString(" START");
    buttonText.setFont(font);
    buttonText.setCharacterSize(30);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(335, 405);*/
}

void Menu::event_handler(sf::RenderWindow* window, sf::Event* event, Game* game){

    Dispatcher* newDispatcher = new Dispatcher;

    if (event->type == sf::Event::Closed) window->close();

    if (event->type == sf::Event::TextEntered) {
        if (event->text.unicode == '\b' && !playerName.empty()) {
            playerName.pop_back();
        }
        else if (event->text.unicode < 128 && event->text.unicode != '\b') {
            playerName += static_cast<char>(event->text.unicode);
        }
        if (playerName.empty()) inputBox.setFillColor(sf::Color::Transparent);
        else inputBox.setFillColor(sf::Color::Black);

        inputText.setString(playerName);
    }

    if (event->type == sf::Event::MouseButtonReleased) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
        if (button.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            if (!playerName.empty()) {

                string line;
                string name;
                int last_level = 1;
                int best_score = 0;
                int loses = 0;

                ifstream in("Users.txt");
                if (in.is_open()) {    
                    while (getline(in, line)) {
                        int first_space = line.find(' ');
                        name = line.substr(0, first_space);
                        if (playerName == name) {
                            istringstream iss(line.substr(first_space + 1));

                            iss >> last_level >> best_score >> loses;

                            newDispatcher->setBestScore(best_score);
                            newDispatcher->setCurrentScore(0);
                            newDispatcher->setLastLevel(last_level);
                            newDispatcher->setLosesNumber(loses);

                            game->setDispatcher(newDispatcher);

                            cout << name << last_level << best_score << loses << endl;
                            break;
                        }
                    }
                }

                if (name != playerName) {
                    ofstream out("Users.txt", ios::app);
                    if (out.is_open()) {
                        out << playerName << " " << 1 << " " << 0 << " " << 0 << endl;
                    }
                }
                in.close();

                //Level level_1(last_level); // 1
                Level* level = new Level(last_level);
                level->scheduleSort();

                cout << "\n\n";
                for (int i = 0; i < level->getAirplanes().size(); ++i) {
                    cout << "board number " << level->getAirplanes()[i]->getBoardNumber() << " will start at \n\t";
                    level->getAirplanes()[i]->getTimeOfAction().printDate();
                    cout << "\n";
                }
                
                game->setLevel(level);
                window->close();
            }
        }
    }
}
