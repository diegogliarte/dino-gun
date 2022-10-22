#ifndef DINO_GUN_GAMEMANAGER_H
#define DINO_GUN_GAMEMANAGER_H

#include "dinosaur.h"
#include "t_rex.h"
#include "ground.h"
#include "cacti.h"
#include "constants_loader.h"


class GameManager {
public:
    std::vector<Dinosaur> dinosaurs;
    std::vector<Cacti> cactus;
    T_Rex tRex;
    Ground ground;
    sf::RenderWindow* window;
    GameManager(ConstantsLoader* constantsLoader, sf::RenderWindow* window);
    void update();
    void draw();

private:
    sf::Clock clock;
    ConstantsLoader *constantsLoader;
    void gameOver();
};


#endif //DINO_GUN_GAMEMANAGER_H
