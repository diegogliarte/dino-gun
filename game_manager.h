//
// Created by diego on 16/10/22.
//

#ifndef DINO_GUN_GAMEMANAGER_H
#define DINO_GUN_GAMEMANAGER_H

#include "dinosaur.h"
#include "t_rex.h"

class GameManager {
public:
    std::vector<Dinosaur> dinosaurs;
    T_Rex* tRex;
    int groundHeight;
    GameManager(T_Rex* tRex, int groundHeight);
    void update();
    void draw(sf::RenderWindow* window);

private:
    sf::Clock clock;

};


#endif //DINO_GUN_GAMEMANAGER_H
