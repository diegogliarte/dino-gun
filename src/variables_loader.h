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
    float backgroundSpeed = 0.0025f;

    VariablesLoader();
private:


};


#endif //DINO_GUN_VARIABLES_LOADER_H
