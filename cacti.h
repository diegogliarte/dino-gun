#ifndef DINO_GUN_CACTI_H
#define DINO_GUN_CACTI_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Cacti : public sf::Sprite{
public:
    sf::Texture texture;
    Cacti(float backgroundSpeed);
    void update(float deltaTime);
    void draw(sf::RenderWindow* window);
private:
    float backgroundSpeed;
    float totalTime = 0;
};


#endif //DINO_GUN_CACTI_H
