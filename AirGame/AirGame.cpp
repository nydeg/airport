#include <iostream>
#include "Date.h"
#include "Level.h"

#include <SFML/Graphics.hpp>
#include <iostream>
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

    // MAIN GAME
    sf::RenderWindow newWindow(sf::VideoMode(800, 600), "Game Window");
    game.setWindow(&newWindow);
    while (game.getWindow()->isOpen()) {
        sf::Event event;
        while (game.getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                game.getWindow()->close();
        }
        game.getWindow()->clear();
        game.getWindow()->display();
    }

    return 0;
}

int main()
{

    Level level_1(2);

    cout << "\n\n";

    level_1.scheduleSort();

    for (int i = 0; i < level_1.getAirplanes().size(); ++i) {
        cout << "board number " << level_1.getAirplanes()[i]->getBoardNumber() << " will start at \n\t";
        level_1.getAirplanes()[i]->getTimeOfAction().printDate();
        cout << "\n";
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
}
