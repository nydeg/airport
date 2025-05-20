#include "Menu.h"
#include "Game.h"

void Menu::renderInterface(){
    // ����� ��� ����� �����
    //sf::Text title("ENTER YOUR NAME", font, 40);
    title.setString("ENTER YOUR NAME");
    title.setFont(font);
    title.setCharacterSize(40);
    title.setFillColor(sf::Color::White);
    title.setPosition(250, 200);

    // ���� �����
    //sf::RectangleShape inputBox(sf::Vector2f(400, 50));
    inputBox.setSize(sf::Vector2f(400, 50));
    inputBox.setFillColor(sf::Color::Black);
    inputBox.setOutlineThickness(2);
    inputBox.setOutlineColor(sf::Color::White);
    inputBox.setPosition(200, 300);

    // �����, ������� ������ ������������
    inputText.setString("");
    inputText.setFont(font);
    inputText.setCharacterSize(30);
    inputText.setFillColor(sf::Color::White);
    inputText.setPosition(210, 305);

    // ������ ����� �����
    //sf::RectangleShape button(sf::Vector2f(150, 50)); => Sprite
    button.setSize(sf::Vector2f(150, 50));
    button.setFillColor(sf::Color::Green);
    button.setPosition(325, 400);
    //button.setTexture();

    // ����� ������ - ����� ������ � �������� ��������
    //sf::Text buttonText("ENTER", font, 30);
    buttonText.setString("ENTER");
    buttonText.setFont(font);
    buttonText.setCharacterSize(30);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(335, 405);
}

void Menu::event_handler(sf::RenderWindow* window, sf::Event* event, Game* game){
    if (event->type == sf::Event::Closed) window->close();

    // ��������� ����� ������
    if (event->type == sf::Event::TextEntered) {
        if (event->text.unicode == '\b' && !playerName.empty()) {
            playerName.pop_back();
        }
        else if (event->text.unicode < 128 && event->text.unicode != '\b') {
            playerName += static_cast<char>(event->text.unicode);
        }
        inputText.setString(playerName);
    }

    // ��������� ����� �� ������
    if (event->type == sf::Event::MouseButtonReleased) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
        if (button.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            if (!playerName.empty()) {
                // =====
                // ��������: ������� ��� ���������� ��� ���, ��������/��������� ������
                // =====
                window->close();
            }
        }
    }
}
