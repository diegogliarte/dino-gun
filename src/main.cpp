#include <SFML/Graphics.hpp>
#include "t_rex.h"
#include "game_manager.h"
#include "ground.h"
#include "variables_loader.h"


int main(int argc, char const *argv[]) {
    VariablesLoader variablesLoader;
    sf::RenderWindow window(sf::VideoMode(variablesLoader.windowWidth, variablesLoader.windowHeight), "DinoGun");

    GameManager gameManager(&variablesLoader, &window);
    int i = 0;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:


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

