#include <math.h>

#include "t_rex.h"


T_Rex::T_Rex(sf::Texture* texture, int groundHeight)
: Dinosaur(texture, sf::Vector2f(50, groundHeight), sf::Vector2u(2, 2)) {
    this->groundHeight = groundHeight;

}

void T_Rex::update(float deltaTime, int textureRow) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && getPosition().y == groundHeight) {
        velocity.y = -sqrt(2.0f * 981.0f * 200);
    }

    velocity.y += 2 * 981.0f * deltaTime;
    move(velocity * deltaTime);

    if (getPosition().y > groundHeight) {
        setPositionY(groundHeight);
    }

    Dinosaur::update(deltaTime, textureRow);
}

void T_Rex::setPositionY(int y) {
    setPosition(getPosition().x, y);
}