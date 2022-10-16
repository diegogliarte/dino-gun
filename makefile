all: compile

compile: ./main.cpp
	g++ -c ./main.cpp ./dinosaur.cpp ./t_rex.cpp ./animation.cpp ./game_manager.cpp ./ground.cpp
	g++ main.o dinosaur.o t_rex.o animation.o game_manager.o ground.o \
	-o app -lsfml-graphics -lsfml-window -lsfml-system




