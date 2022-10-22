#include <SFML/Graphics.hpp>
#include "t_rex.h"
#include "game_manager.h"
#include "ground.h"
#include "constants_loader.h"


int main(int argc, char const *argv[]) {
    ConstantsLoader constantsLoader;
    sf::RenderWindow window(sf::VideoMode(constantsLoader.windowWidth, constantsLoader.windowHeight), "DinoGun");

    GameManager gameManager(&constantsLoader, &window);
    int i = 0;
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

