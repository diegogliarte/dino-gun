#ifndef DINO_GUN_ANIMATION_H
#define DINO_GUN_ANIMATION_H

#include <SFML/Graphics.hpp>


class Animation {
public:
    sf::IntRect textureRect;
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    void update(int textureRow, float deltaTime);

private:
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;

};


#endif //DINO_GUN_ANIMATION_H
