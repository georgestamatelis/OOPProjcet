cc = g++ #-std=c++11 -g3
OBJECTS = main.cpp gameboard/gameboard.cpp
cflags=-o
program=test

test:$(OBJECTS)
	$(cc) $(OBJECTS) $(cflags) $(program)

run:$(program)
	./$(program)
clean:
	rm  $(program)
