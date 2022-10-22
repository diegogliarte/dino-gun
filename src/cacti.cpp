
#include <SFML/Graphics/Texture.hpp>
#include "cacti.h"

Cacti::Cacti(float* backgroundSpeed, int* windowWidth) {
    this->backgroundSpeed = backgroundSpeed;
    this->windowWidth = windowWidth;
}

void Cacti::update(float deltaTime) {
    totalTime += deltaTime;
    if (totalTime >= *backgroundSpeed) {
        totalTime -= *backgroundSpeed;
        move(-1, 0);
        int disappearanceThreshold = -5;
        if (getPosition().x + getTextureRect().width <= disappearanceThreshold) {
            setPosition(*windowWidth, getPosition().y);
        }
    }

}

void Cacti::draw(sf::RenderWindow* window) {
    window->draw(*this);
}