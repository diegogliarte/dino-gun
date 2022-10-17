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
    ground->update(deltaTime);
    tRex->update(deltaTime, 1);
}

void GameManager::draw() {
    for (Dinosaur dinosaur : dinosaurs) {
        dinosaur.draw(window);
    }
    ground->draw(window);
    tRex->draw(window);
}