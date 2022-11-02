#ifndef DINO_GUN_ENEMIES_MANAGER_H
#define DINO_GUN_ENEMIES_MANAGER_H


#include <vector>
#include <deque>
#include "dinosaur.h"
#include "cacti.h"
#include "variables_loader.h"
#include "t_rex.h"


class EnemiesManager {
public:
    struct {
        std::deque<Cacti> cactus;
        float currentTime = 0;
        float *spawnTime = {};
        float nextTimeToSpawn = 0;
    } cactiSpawner;

    struct {
        std::deque<Dinosaur> dinosaurs;
        float currentTime = 0;
        float *spawnTime = {};
        float nextTimeToSpawn = 0;
    } dinosaurSpawner;

    EnemiesManager(VariablesLoader *variablesLoader, T_Rex *tRex);
    void update(float deltaTime);
    void draw(sf::RenderWindow* window);
    bool is_hit = false;
private:
    VariablesLoader *variablesLoader;
    void spawnCacti();
    T_Rex *tRex;


};


#endif //DINO_GUN_ENEMIES_MANAGER_H
