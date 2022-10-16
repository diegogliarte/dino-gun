#include <math.h>

#include "t_rex.h"


T_Rex::T_Rex(sf::Texture* texture)
: Dinosaur(texture, sf::Vector2f(50, 300), sf::Vector2u(2, 2)) {

}

void T_Rex::update(float deltaTime, int textureRow) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && getPosition().y == 300) {
        velocity.y = -sqrt(2.0f * 981.0f * 200);
    }

    velocity.y += 2 * 981.0f * deltaTime;
    move(velocity * deltaTime);

    if (getPosition().y > 300) {
        setPosition(getPosition().x, 300);
    }

    Dinosaur::update(deltaTime, textureRow);
}