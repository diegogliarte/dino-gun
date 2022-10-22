
#include <SFML/Graphics/Texture.hpp>
#include "cacti.h"

Cacti::Cacti(float* gameSpeed, int* windowWidth) {
    this->gameSpeed = gameSpeed;
    this->windowWidth = windowWidth;
}

void Cacti::update(float deltaTime) {
    totalTime += deltaTime;
    if (totalTime >= *gameSpeed) {
        totalTime -= *gameSpeed;
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