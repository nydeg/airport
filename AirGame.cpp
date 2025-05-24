#include <iostream>
#include "Date.h"
#include "Level.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Game.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1024*0.666, 1536*0.666), "Main Menu");
    window.setFramerateLimit(10);

    Game game;
    Menu menu_game("./assets/ofont.ru_Menlo.ttf", "./assets/menu.png");
    menu_game.renderInterface();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            menu_game.event_handler(&window, &event, &game);
        }

        window.clear();
        window.draw(menu_game.getBackground());
        window.draw(menu_game.getTitle());
        window.draw(*menu_game.getInputBox());
        window.draw(menu_game.getinputText());
        window.draw(menu_game.getButton());
        window.display();
    }

    //delete menu_game;

    // MAIN GAME
    sf::RenderWindow newWindow(sf::VideoMode(1900, 1000), "Game Window");
    game.setBackground("./assets/level " + to_string(game.getLevel()->getLevelNum()) + ".png");
    game.setWindow(&newWindow);


    game.renderDisplay("./assets/ofont.ru_Menlo.ttf");

    int i = 0;
    while (game.getWindow()->isOpen()) {
        sf::Event event;
        game.getWindow()->clear();
        game.getWindow()->draw(game.getBackground());

        //if(i % 29 == 0) {
        if(i%1 == 0){
            game.updateGame();
            i = 0;
        }
        ++i;
        while (game.getWindow()->pollEvent(event)) {
            game.event_handler(&event);
            game.updateSchedule();
        }

        //update Display

        game.drawDisplay();



        //game.updateAirplanes();
        //game.drawAirplanes();

        /*
        //Airplanes drawing
        for(int j = 0; j < game.getLevel()->getAirplanes().size(); ++j) {
            game.getLevel()->getAirplanes()[i]->updatePos();
            game.getWindow()->draw(game.getLevel()->getAirplanes()[i]->__s_getTestShape__());
        }
        */

        game.getWindow()->display();
    }

    return 0;
}


    /*
    Date currDate;
    Date cD;

    currDate = currDate + 30;
    currDate.printDate();

    int raz = currDate - cD;
    cout << "\nThis is ZADERJKA IN MINUTES --> " << raz << "\n";
    */
//    std::cout << "Hello World!\n";
