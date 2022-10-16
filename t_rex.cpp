#include "t_rex.h"

T_Rex::T_Rex(sf::Texture* texture)
: Dinosaur(texture, sf::Vector2f(10, 10), sf::Vector2u(2, 2)) {

}

void T_Rex::update(float deltaTime) {
    Dinosaur::update(deltaTime);
}