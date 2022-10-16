#include <SFML/Graphics.hpp>
#include "t_rex.h"


int main(int argc, char const *argv[]) {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Hello From SFML");
    sf::Texture tRexTexture;
    tRexTexture.loadFromFile("./sprites/t_rex.png");
    T_Rex tRex(&tRexTexture);
    float deltaTime;
    sf::Clock clock;

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

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
        tRex.update(deltaTime, 1);
        window.draw(tRex);
        window.display();
    }

    return 0;
}

