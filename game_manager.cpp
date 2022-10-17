#include "game_manager.h"
#include "t_rex.h"
#include "cacti.h"


GameManager::GameManager(T_Rex* tRex, Ground* ground, sf::RenderWindow* window, float backgroundSpeed) {
    this->tRex = tRex;
    this->ground = ground;
    this->window = window;
    this->backgroundSpeed = backgroundSpeed;

    this->cactiTexture.loadFromFile("./sprites/cacti.png");

    int numCactus = 1;
    for (int i = 0; i < numCactus; i++) {
        Cacti cacti(backgroundSpeed, window->getSize().x);
        cacti.setTexture(this->cactiTexture);
        cacti.setPosition(window->getSize().x, this->ground->groundHeight - 55);
        this->cactus.push_back(cacti);
    }
}

void GameManager::update() {
    float deltaTime = clock.restart().asSeconds();
    ground->update(deltaTime);
    for (Dinosaur& dinosaur : dinosaurs) {
        dinosaur.update(deltaTime, 0);
    }
    for (Cacti& cacti : cactus) {
        cacti.update(deltaTime);
        if (tRex->getGlobalBounds().intersects(cacti.getGlobalBounds())) {
            tRex->setColor(sf::Color(255, 0, 0));
        }
    }
    tRex->update(deltaTime, 1);
}

void GameManager::draw() {
    ground->draw(window);
    for (Dinosaur dinosaur : dinosaurs) {
        dinosaur.draw(window);
    }
    for (Cacti cacti : cactus) {
        cacti.draw(window);
    }
    tRex->draw(window);
}