#include "dinosaur.h"


Dinosaur::Dinosaur(sf::Texture* texture, sf::Vector2f position, sf::Vector2u textureImageCount) :
animation(texture, textureImageCount, 0.1f){
    setTexture(*texture);
    setPosition(position);
}

void Dinosaur::update(float deltaTime, int textureRow) {
    animation.update(textureRow, deltaTime);
    setTextureRect(animation.textureRect);
}

