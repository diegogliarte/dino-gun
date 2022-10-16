#ifndef DINO_GUN_GROUND_H
#define DINO_GUN_GROUND_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Ground {
public:
    int groundHeight;
    sf::Texture texture;
    std::vector<sf::Sprite> segments;
    Ground(int groundWidth, int groundHeight, float groundSpeed);
    void update(float deltaTime);
    void draw(sf::RenderWindow* window);
private:
    float totalTime = 0;
    int segmentSize = 400;
    float groundSpeed;
};


#endif //DINO_GUN_GROUND_H
