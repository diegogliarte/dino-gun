all: compile

compile: ./main.cpp
	g++ -c ./main.cpp ./dinosaur.cpp ./t_rex.cpp
	g++ main.o dinosaur.o t_rex.o -o app -lsfml-graphics -lsfml-window -lsfml-system




