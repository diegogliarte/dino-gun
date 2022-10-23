#include "enemies_manager.h"
#include "utils.h"


EnemiesManager::EnemiesManager(VariablesLoader *variablesLoader) {
    this->variablesLoader = variablesLoader;
    cactiSpawner.spawnTime = &variablesLoader->cactiSpawnTime;
}

void EnemiesManager::update(float deltaTime) {
    cactiSpawner.currentTime += deltaTime;

    if (cactiSpawner.currentTime >= cactiSpawner.nextTimeToSpawn) {
        spawnCacti();
        cactiSpawner.nextTimeToSpawn = generateRandomNumberBetween(0.75, 1.25) * *cactiSpawner.spawnTime;

    }

    float disappearanceThreshold = -5;

    for (Dinosaur &dinosaur : this->dinosaurSpawner.dinosaurs) {
        dinosaur.update(deltaTime, 0);
    }

    for (Cacti &cacti : this->cactiSpawner.cactus) {
        cacti.update(deltaTime);
    }

    Cacti *firstCacti = &this->cactiSpawner.cactus[0];
    if (firstCacti->getPosition().x + firstCacti->getTextureRect().width <= disappearanceThreshold) {
        this->cactiSpawner.cactus.pop_front();
    }

}

void EnemiesManager::draw(sf::RenderWindow* window) {
    for (Dinosaur dinosaur : this->dinosaurSpawner.dinosaurs) {
        dinosaur.draw(window);
    }
    for (Cacti cacti : this->cactiSpawner.cactus) {
        cacti.draw(window);
    }
}

void EnemiesManager::spawnCacti() {
    cactiSpawner.currentTime -= *cactiSpawner.spawnTime;
    Cacti cacti(&variablesLoader->gameSpeed, &variablesLoader->windowWidth);
    cacti.setTexture(this->variablesLoader->cactiTexture);
    cacti.setPosition(this->variablesLoader->windowWidth, this->variablesLoader->groundHeight - 55);
    cactiSpawner.cactus.push_back(cacti);
}
