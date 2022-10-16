#include "game_manager.h"
#include "t_rex.h"

GameManager::GameManager(T_Rex* tRex, int groundHeight) {
    this->tRex = tRex;
    this->tRex->groundHeight = groundHeight;
}

void GameManager::update() {
    float deltaTime = clock.restart().asSeconds();
    for (Dinosaur& dinosaur : dinosaurs) {
        dinosaur.update(deltaTime, 0);
    }
    tRex->update(deltaTime, 1);
}

void GameManager::draw(sf::RenderWindow *window) {
    for (Dinosaur& dinosaur : dinosaurs) {
        window->draw(dinosaur);
    }
    window->draw(*tRex);
}