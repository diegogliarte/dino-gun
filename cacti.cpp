
#include <SFML/Graphics/Texture.hpp>
#include "cacti.h"

Cacti::Cacti(float backgroundSpeed) {
    this->backgroundSpeed = backgroundSpeed;
}

void Cacti::update(float deltaTime) {
    totalTime += deltaTime;
    if (totalTime >= backgroundSpeed) {
        totalTime -= backgroundSpeed;
        move(-1, 0);
    }

}

void Cacti::draw(sf::RenderWindow* window) {
    window->draw(*this);
}