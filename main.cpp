#include <SFML/Graphics.hpp>
#include "dinosaur.h"

int main(int argc, char const *argv[]) {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Hello From SFML");
    window.setFramerateLimit(20);
    Dinosaur dinosaur;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        dinosaur.update();
        window.draw(dinosaur);
        window.display();
    }

    return 0;
}

