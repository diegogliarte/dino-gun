#include "dinosaur.h"


Dinosaur::Dinosaur(sf::Texture* texture, sf::Vector2f position, sf::Vector2u textureImageCount) :
animation(texture, textureImageCount, 0.3f){
    setTexture(*texture);
    setPosition(position);
}

void Dinosaur::update(float deltaTime) {
    animation.update(0, deltaTime);
    setTextureRect(animation.textureRect);
}

