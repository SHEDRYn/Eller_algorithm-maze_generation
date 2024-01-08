FILES = ../src/maze/Model/parser.cc \
	../src/maze/model/pathFinder.cc \
	../src/maze/Controller/controller.cc \
	../src/maze/model/mazeGenerator.cc

FLAGS = -std=c++17 -lstdc++

all: 1

1:
	gcc mainPathFinder.cc $(FILES) $(FLAGS)
	./a.out

2:
	gcc mainMazeGenerator.cc $(FILES) $(FLAGS)
	./a.out

g:
	gcc main.cc \
	../src/maze/Model/parser.cc \
	../src/maze/model/pathFinder.cc \
	../src/maze/Controller/controller.cc \
	-std=c++17 -lstdc++ -g
