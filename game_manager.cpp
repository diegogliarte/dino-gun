#include "game_manager.h"
#include "t_rex.h"

GameManager::GameManager(T_Rex* tRex, Ground* ground, sf::RenderWindow* window) {
    this->tRex = tRex;
    this->ground = ground;
    this->window = window;
}

void GameManager::update() {
    float deltaTime = clock.restart().asSeconds();
    for (Dinosaur& dinosaur : dinosaurs) {
        dinosaur.update(deltaTime, 0);
    }
    tRex->update(deltaTime, 1);
    ground->update(deltaTime);
}

void GameManager::draw() {
    for (Dinosaur dinosaur : dinosaurs) {
        dinosaur.draw(window);
    }
    tRex->draw(window);
    ground->draw(window);
}