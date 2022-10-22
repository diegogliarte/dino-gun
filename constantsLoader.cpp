#include "constantsLoader.h"


ConstantsLoader::ConstantsLoader() {
    std::string folder = "./sprites/";
    tRexTexture.loadFromFile(folder + "t_rex.png");
    groundTexture.loadFromFile(folder + "ground.png");
    cactiTexture.loadFromFile(folder + "cacti.png");
}