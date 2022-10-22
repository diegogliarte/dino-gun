#include <math.h>

#include "t_rex.h"

const float GRAVITY = 981.0f;

T_Rex::T_Rex(sf::Texture* texture, int* groundHeight, int* jumpHeight)
: Dinosaur(texture, sf::Vector2f(50, *groundHeight), sf::Vector2u(2, 2)) {
    this->groundHeight = groundHeight;
    this->jumpHeight = jumpHeight;
}

void T_Rex::update(float deltaTime, int textureRow) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && getPosition().y == *groundHeight) {
        velocity.y = -sqrt(2.0f * GRAVITY * *jumpHeight);
    }
    velocity.y += 2 * GRAVITY * deltaTime;
    move(velocity * deltaTime);

    if (getPosition().y > *groundHeight) {
        setPositionY(*groundHeight);
    }

    Dinosaur::update(deltaTime, textureRow);
}

void T_Rex::setPositionY(int y) {
    setPosition(getPosition().x, y);
}