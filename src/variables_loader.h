#ifndef DINO_GUN_CONSTANTS_LOADER_H
#define DINO_GUN_CONSTANTS_LOADER_H


#include <SFML/Graphics/Texture.hpp>

class ConstantsLoader {
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

    ConstantsLoader();
private:


};


#endif //DINO_GUN_CONSTANTS_LOADER_H
