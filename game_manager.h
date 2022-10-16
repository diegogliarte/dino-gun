#ifndef DINO_GUN_GAMEMANAGER_H
#define DINO_GUN_GAMEMANAGER_H

#include "dinosaur.h"
#include "t_rex.h"
#include "ground.h"

class GameManager {
public:
    std::vector<Dinosaur> dinosaurs;
    T_Rex* tRex;
    Ground* ground;
    sf::RenderWindow* window;
    GameManager(T_Rex* tRex, Ground* ground, sf::RenderWindow* window);
    void update();
    void draw();

private:
    sf::Clock clock;

};


#endif //DINO_GUN_GAMEMANAGER_H
