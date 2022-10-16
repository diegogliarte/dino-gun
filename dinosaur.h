#ifndef DINO_GUN_DINOSAUR_H
#define DINO_GUN_DINOSAUR_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <stdexcept>
#include <iostream>
#include <SFML/Window/Keyboard.hpp>

#include "animation.h"

class Dinosaur : public sf::Sprite {
public:
    Dinosaur(sf::Texture* texture, sf::Vector2f position, sf::Vector2u textureImageCount);
    void update(float deltaTime, int textureRow);

private:
    Animation animation;
    sf::Texture texture;
};


#endif //DINO_GUN_DINOSAUR_H
