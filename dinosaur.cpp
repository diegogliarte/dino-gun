#include "dinosaur.h"

Dinosaur::Dinosaur() {}

Dinosaur::Dinosaur(std::string texturePath, sf::Vector2f position) {
    texture.loadFromFile(texturePath);
    setTexture(texture);
    setPosition(position);
}
