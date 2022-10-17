#ifndef DINO_GUN_GAMEMANAGER_H
#define DINO_GUN_GAMEMANAGER_H

#include "dinosaur.h"
#include "t_rex.h"
#include "ground.h"
#include "cacti.h"

class GameManager {
public:
    std::vector<Dinosaur> dinosaurs;
    std::vector<Cacti> cactus;
    T_Rex* tRex;
    Ground* ground;
    sf::RenderWindow* window;
    GameManager(T_Rex* tRex, Ground* ground, sf::RenderWindow* window, float backgroundSpeed);
    void update();
    void draw();

private:
    sf::Clock clock;
    sf::Texture cactiTexture;
    float backgroundSpeed;

};


#endif //DINO_GUN_GAMEMANAGER_H
