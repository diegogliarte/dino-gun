#include <SFML/Graphics.hpp>
#include "t_rex.h"
#include "game_manager.h"


int main(int argc, char const *argv[]) {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Hello From SFML");

    sf::Texture tRexTexture;
    tRexTexture.loadFromFile("./sprites/t_rex.png");
    T_Rex tRex(&tRexTexture);

    int groundHeight = 300;
    GameManager gameManager(&tRex, groundHeight);

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
        gameManager.draw(&window);
        window.display();
    }

    return 0;
}

