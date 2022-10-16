#include "dinosaur.h"

#ifndef DINO_GUN_T_REX_H
#define DINO_GUN_T_REX_H

class T_Rex : public Dinosaur {
public:
    sf::Vector2f velocity;

    T_Rex(sf::Texture* texture, int groundHeight);

    void update(float deltaTime, int textureRow);
    void setPositionY(int y);
private:
    int groundHeight = 0;


};


#endif //DINO_GUN_T_REX_H
