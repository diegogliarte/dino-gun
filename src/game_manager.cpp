#include "game_manager.h"
#include "t_rex.h"
#include "cacti.h"
#include "variables_loader.h"


GameManager::GameManager(VariablesLoader* variablesLoader, sf::RenderWindow* window) :
tRex(&variablesLoader->tRexTexture, &variablesLoader->tRexHeight, &variablesLoader->tRexJumpHeight),
ground(&variablesLoader->groundTexture, &variablesLoader->windowWidth, &variablesLoader->groundHeight, &variablesLoader->gameSpeed),
enemiesManager(variablesLoader, &tRex)
{
    this->variablesLoader = variablesLoader;
    this->window = window;

//    int numCactus = 1;
//    for (int i = 0; i < numCactus; i++) {
//        Cacti cacti(&this->variablesLoader->gameSpeed, &this->variablesLoader->windowWidth);
//        cacti.setTexture(this->variablesLoader->cactiTexture);
//        cacti.setPosition(this->variablesLoader->windowWidth, this->variablesLoader->groundHeight - 55);
//        this->cactus.push_back(cacti);
//    }
}

void GameManager::update() {

    float deltaTime = clock.restart().asSeconds();
    tRex.update(deltaTime, 1);
    enemiesManager.update(deltaTime);
    ground.update(deltaTime);
    if (enemiesManager.is_hit) {
        gameOver();
    }

}

void GameManager::draw() {
    this->tRex.draw(this->window);
    this->enemiesManager.draw(this->window);
    this->ground.draw(this->window);
}

void GameManager::gameOver() {
    variablesLoader->gameSpeed = 0;
    tRex.setColor(sf::Color(255, 0, 0));
}