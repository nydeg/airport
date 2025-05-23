#include <iostream>
#include "Date.h"
#include "Level.h"
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Game.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Main Menu");

    Game game;
    Menu menu_game("./assets/ofont.ru_Menlo.ttf", "./assets/airoport final.png");
    menu_game.renderInterface();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            menu_game.event_handler(&window, &event, &game);
        }

        window.clear();
        window.draw(menu_game.getBackground());
        window.draw(menu_game.getTitle());
        window.draw(menu_game.getInputBox());
        window.draw(menu_game.getinputText());
        window.draw(menu_game.getButton());
        window.draw(menu_game.getButtonText());
        window.display();
    }

    //delete menu_game;

    // MAIN GAME
    sf::RenderWindow newWindow(sf::VideoMode(1900, 1000), "Game Window");
    game.setBackground("./assets/level 1.png");
    game.setWindow(&newWindow);


    game.renderDisplay("./assets/ofont.ru_Menlo.ttf");

    while (game.getWindow()->isOpen()) {
        sf::Event event;
        while (game.getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                game.getWindow()->close();
            }
        }
        game.getWindow()->clear();
        game.getWindow()->draw(game.getBackground());
        game.getWindow()->draw(game.getBackground());

        //update game
        //...

        //update Display
        game.updateDisplay();
        game.drawDisplay();

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
