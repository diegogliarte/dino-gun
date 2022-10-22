#include <SFML/Graphics/Texture.hpp>

#include <stdlib.h>
#include <math.h>
#include <iostream>

#include "ground.h"

Ground::Ground(sf::Texture* texture, int* groundWidth, int* groundHeight, float* backgroundSpeed) {

    srand(time(nullptr));
    this->texture = *texture;
    this->groundHeight = groundHeight;
    this->backgroundSpeed = backgroundSpeed;

    sf::Vector2u textureSize = this->texture.getSize();
    int numSegments = ceil(*groundWidth / segmentSize) + 2;

    for (int i = 0; i < numSegments; i++) {
        sf::Sprite segment;
        segment.setTexture(this->texture);
        int randomTexture = rand() % numSegments;
        sf::IntRect rect(segmentSize * randomTexture, 0, segmentSize, textureSize.y);
        segment.setTextureRect(rect);
        segment.setPosition(segmentSize * i, *groundHeight);
        segments.push_back(segment);
    }

}

void Ground::update(float deltaTime) {
    totalTime += deltaTime;

    if (totalTime >= *backgroundSpeed) {
        totalTime -= *backgroundSpeed;
        int disappearanceThreshold = -5;
        for (sf::Sprite& segment : segments) {
            segment.move(-1, 0);
            if (segment.getPosition().x + segmentSize <= disappearanceThreshold) {
                segment.setPosition((segments.size() - 1) * segmentSize + disappearanceThreshold, *groundHeight);
                int randomTexture = rand() % segments.size();
                segment.setTextureRect(sf::IntRect(segmentSize * randomTexture % texture.getSize().x, 0, segmentSize, texture.getSize().y));
            }
        }
    }

}

void Ground::draw(sf::RenderWindow* window) {
    for (sf::Sprite& segment : segments) {
        window->draw(segment);
    }
}
