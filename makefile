all: compile

compile: ./main.cpp
	g++ -c ./main.cpp ./dinosaur.cpp ./t_rex.cpp ./animation.cpp ./game_manager.cpp
	g++ main.o dinosaur.o t_rex.o animation.o game_manager.o \
	-o app -lsfml-graphics -lsfml-window -lsfml-system




