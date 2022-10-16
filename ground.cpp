#include <SFML/Graphics/Texture.hpp>

#include <stdlib.h>
#include <math.h>

#include "ground.h"

Ground::Ground(int groundWidth, int groundHeight, float groundSpeed) {
    srand(time(NULL));
    this->groundHeight = groundHeight;
    this->groundSpeed = groundSpeed;

    this->texture.loadFromFile("./sprites/ground.png");
    sf::Vector2u textureSize = this->texture.getSize();
    int numSegments = ceil(groundWidth / segmentSize) + 2;
    for (int i = 0; i < numSegments; i++) {
        sf::Sprite segment;
        segment.setTexture(this->texture);
        int randomTexture = rand() % textureSize.x / segmentSize;
        sf::IntRect rect(segmentSize * randomTexture, 0, segmentSize, textureSize.y);
        segment.setTextureRect(rect);
        segment.setPosition(segmentSize * i, groundHeight);
        segments.push_back(segment);
    }

}

void Ground::update(float deltaTime) {
    totalTime += deltaTime;

    if (totalTime >= groundSpeed) {
        totalTime -= groundSpeed;
        int disappearanceThreshold = -5;
        for (sf::Sprite& segment : segments) {
            segment.move(-1, 0);
            if (segment.getPosition().x + segmentSize <= disappearanceThreshold) {
                segment.setPosition((segments.size() - 1) * segmentSize + disappearanceThreshold, groundHeight);
                segment.setTextureRect(sf::IntRect(segmentSize * rand() % texture.getSize().x, 0, segmentSize, texture.getSize().y));
            }
        }
    }

}

void Ground::draw(sf::RenderWindow* window) {
    for (sf::Sprite& segment : segments) {
        window->draw(segment);
//        std::cout << segment.getPosition().x << std::endl;
    }
}
