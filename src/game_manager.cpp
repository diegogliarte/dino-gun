#include "game_manager.h"
#include "t_rex.h"
#include "cacti.h"
#include "variables_loader.h"


GameManager::GameManager(VariablesLoader* constantsLoader, sf::RenderWindow* window) :
tRex(&constantsLoader->tRexTexture, &constantsLoader->tRexHeight, &constantsLoader->tRexJumpHeight),
ground(&constantsLoader->groundTexture, &constantsLoader->windowWidth, &constantsLoader->groundHeight, &constantsLoader->backgroundSpeed)
{
    this->constantsLoader = constantsLoader;
    this->window = window;

    int numCactus = 1;
    for (int i = 0; i < numCactus; i++) {
        Cacti cacti(&this->constantsLoader->backgroundSpeed, &this->constantsLoader->windowWidth);
        cacti.setTexture(this->constantsLoader->cactiTexture);
        cacti.setPosition(this->constantsLoader->windowWidth, this->constantsLoader->groundHeight - 55);
        this->cactus.push_back(cacti);
    }
}

void GameManager::update() {

    float deltaTime = clock.restart().asSeconds();
    ground.update(deltaTime);

    for (Dinosaur& dinosaur : dinosaurs) {
        dinosaur.update(deltaTime, 0);
    }

    for (Cacti& cacti : cactus) {
        cacti.update(deltaTime);
        if (tRex.getGlobalBounds().intersects(cacti.getGlobalBounds())) {
            gameOver();

        }
    }
    tRex.update(deltaTime, 1);

}

void GameManager::draw() {
    this->ground.draw(this->window);
    for (Dinosaur dinosaur : this->dinosaurs) {
        dinosaur.draw(window);
    }
    for (Cacti cacti : this->cactus) {
        cacti.draw(this->window);
    }
    this->tRex.draw(this->window);
}

void GameManager::gameOver() {
    tRex.setColor(sf::Color(255, 0, 0));
}