#include "dinosaur.h"

#ifndef DINO_GUN_T_REX_H
#define DINO_GUN_T_REX_H

class T_Rex : public Dinosaur {
public:
    sf::Vector2f velocity;
    int groundHeight = 0;

    T_Rex(sf::Texture* texture);

    void update(float deltaTime, int textureRow);
    void setPositionY(int y);
private:

};


#endif //DINO_GUN_T_REX_H
