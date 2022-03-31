CXX = g++
LIB_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
INCLUDE = include/
SRC = src/
FILES = $(SRC)Box.cpp $(SRC)World.cpp $(SRC)Window.cpp

Main: Main.cpp
	$(CXX) Main.cpp $(FILES) -o Main $(LIB_FLAGS)