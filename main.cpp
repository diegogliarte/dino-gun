#include <SFML/Graphics.hpp>
#include "t_rex.h"
#include "game_manager.h"
#include "ground.h"


int main(int argc, char const *argv[]) {
    int width = 1280;
    int height = 720;
    int groundHeight = 300;
    sf::RenderWindow window(sf::VideoMode(width, height), "Hello From SFML");

    sf::Texture tRexTexture;
    tRexTexture.loadFromFile("./sprites/t_rex.png");
    T_Rex tRex(&tRexTexture, groundHeight);

    float groundSpeed = 0.005f;
    Ground ground(width, groundHeight, groundSpeed);

    GameManager gameManager(&tRex, &ground, &window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
            }
        }

        window.clear(sf::Color(255, 255, 255));
        gameManager.update();
        gameManager.draw();
        window.display();
    }

    return 0;
}

