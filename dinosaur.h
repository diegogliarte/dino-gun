#ifndef DINOGUN_DINOSAUR_H
#define DINOGUN_DINOSAUR_H


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
    sf::IntRect textureRects[4] = {
            sf::IntRect(0, 0, 88, 94),
            sf::IntRect(89, 0, 88, 94),
            sf::IntRect(176, 0, 88, 94),
            sf::IntRect(264, 0, 88, 94),
    };
    int currentStep = 0;
    sf::Vector2f velocity = sf::Vector2f(0, 0);

    void updateNextStepAnimation() {
        currentStep = (currentStep + 1) % 2;
        setTextureRect(textureRects[2 + currentStep]);
    }

    void updateHeight() {
        move(velocity);
        std::cout << getPosition().y << std::endl;
        if (getPosition().y < 300) {
            velocity.y += 1;
        } else {
            setPosition(getPosition().x, 300);
        }
    }

    void jump() {
        velocity.y = -10.0f;
    }

public:
    int lives;
    Dinosaur() {
        texture.loadFromFile("./sprites/dinosaur-sprites.png");
        setTexture(texture);
        setTextureRect(textureRects[currentStep]);
        setPosition(50, 300);
    }

    void update() {
        updateNextStepAnimation();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && getPosition().y == 300) {
            jump();
        }
        updateHeight();

    }



};


#endif //DINOGUN_DINOSAUR_H
