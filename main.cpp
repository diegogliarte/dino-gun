#include <SFML/Graphics.hpp>
#include "t_rex.h"
#include "dinosaur.h"


int main(int argc, char const *argv[]) {
    sf::RenderWindow window(sf::VideoMode(720, 720), "Hello From SFML");
    window.setFramerateLimit(20);
    T_Rex tRex;
    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        tRex.update();
        window.draw(tRex);
        window.display();
    }

    return 0;
}

