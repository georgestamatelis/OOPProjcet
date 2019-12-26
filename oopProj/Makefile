cc = g++ #-std=c++11 -g3
OBJECTS = main.cpp gameboard/gameboard.cpp phase1/*.cpp phase2/*.cpp phase3/*.cpp phase4/*.cpp player/*.cpp ./external_dependencies/DeckBuilder.cpp #./external_dependencies/*.cpp
cflags=-o
program=prog

prog$(OBJECTS)
	$(cc) $(OBJECTS) $(cflags) $(program)

run:$(program)
	./$(program)
clean:
	rm  $(program)
