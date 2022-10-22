cmake_minimum_required(VERSION 3.23)
project(dino_gun)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(dino_gun src/main.cpp
        src/constants_loader.cpp src/constants_loader.h
        src/game_manager.cpp src/game_manager.h
        src/t_rex.cpp src/t_rex.h
        src/ground.cpp src/ground.h
        src/cacti.cpp src/cacti.h
        src/dinosaur.cpp src/dinosaur.h
        src/animation.cpp src/animation.h)
target_link_libraries(dino_gun sfml-graphics sfml-audio)
