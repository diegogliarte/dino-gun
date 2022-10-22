#include "dinosaur.h"

#ifndef DINO_GUN_T_REX_H
#define DINO_GUN_T_REX_H

class T_Rex : public Dinosaur {
public:
    T_Rex(sf::Texture* texture, int* groundHeight, int* jumpHeight);

    void update(float deltaTime, int textureRow) override;
    void setPositionY(int y);
private:
    sf::Vector2f velocity;
    int* groundHeight = 0;
    int* jumpHeight = 0;
};


#endif //DINO_GUN_T_REX_H
