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

    // Здесь можно добавить логику для нового окна
    sf::RenderWindow newWindow(sf::VideoMode(800, 600), "Game Window");
    game.setWindow(&newWindow);
    while (game.getWindow()->isOpen()) {
        sf::Event event;
        while (game.getWindow()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                game.getWindow()->close();
        }
        game.getWindow()->clear();
        // Добавьте содержимое нового окна здесь
        game.getWindow()->display();
    }

    return 0;
}