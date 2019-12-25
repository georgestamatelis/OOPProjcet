cc = g++ #-std=c++11 -g3
OBJECTS = main.cpp ./external_dependencies/*.cpp gameboard/gameboard.cpp phase1/*.cpp phase2/*.cpp phase3/*.cpp player/*.cpp
cflags=-o
program=prog

test:$(OBJECTS)
	$(cc) $(OBJECTS) $(cflags) $(program)

run:$(program)
	./$(program)
clean:
	rm  $(program)
