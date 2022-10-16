all: compile

compile: ./main.cpp
	g++ -c ./main.cpp ./dinosaur.cpp ./t_rex.cpp ./animation.cpp
	g++ main.o dinosaur.o t_rex.o animation.o \
	-o app -lsfml-graphics -lsfml-window -lsfml-system




