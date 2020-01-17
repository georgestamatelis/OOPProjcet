cc = g++ -std=c++11 -g3 -DCOLORS
OBJECTS = main.cpp gameboard/gameboard.cpp dependencies/Functionalities.cpp dependencies/DeckBuilder.cpp player/Player.cpp phase1/phase1.cpp phase3/phase3.cpp phase2/phase2.cpp phase4/phase4.cpp phase5/phase5.cpp
cflags=-o
program=test

test:$(OBJECTS)
	$(cc) $(OBJECTS) $(cflags) $(program)

colors:$(OBJECTS)
	$(cc) $(OBJECTS) -D COLORS $(cflags) $(program)

run:$(program)
	./$(program)
clean:
	rm  $(program)
