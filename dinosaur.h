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

class Dinosaur : public sf::Sprite {
private:
    sf::Texture texture;
public:
    Dinosaur();
    Dinosaur(std::string texturePath, sf::Vector2f position);

    void update() {

    }

};


#endif //DINO_GUN_DINOSAUR_H
