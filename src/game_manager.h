#ifndef DINO_GUN_GAMEMANAGER_H
#define DINO_GUN_GAMEMANAGER_H

#include "dinosaur.h"
#include "t_rex.h"
#include "ground.h"
#include "cacti.h"
#include "variables_loader.h"
#include "enemies_manager.h"


class GameManager {
public:
    EnemiesManager enemiesManager;

    T_Rex tRex;
    Ground ground;
    sf::RenderWindow* window;
    GameManager(VariablesLoader* variablesLoader, sf::RenderWindow* window);
    void update();
    void draw();

private:
    sf::Clock clock;
    VariablesLoader *variablesLoader;
    void gameOver();
};


#endif //DINO_GUN_GAMEMANAGER_H
