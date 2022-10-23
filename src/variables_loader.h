#ifndef DINO_GUN_VARIABLES_LOADER_H
#define DINO_GUN_VARIABLES_LOADER_H


#include <SFML/Graphics/Texture.hpp>

class VariablesLoader {
public:
    sf::Texture tRexTexture;
    sf::Texture groundTexture;
    sf::Texture cactiTexture;

    int windowWidth = 1280;
    int windowHeight = 720;
    int groundHeight = 300;
    int tRexHeight = 245;
    int tRexJumpHeight = 350;
    float gameSpeed = 0.0025f;
    float maxGameSpeed = 0.005f;
    float cactiSpawnTime = 2.0f;
    float dinosaurSpawnTime = 2.0f;

    VariablesLoader();
private:


};


#endif //DINO_GUN_VARIABLES_LOADER_H
