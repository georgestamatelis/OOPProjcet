
cc = g++ -std=c++11 #-g3
OBJECTS = main.cpp gameboard/gameboard.cpp dependencies/Functionalities.cpp dependencies/DeckBuilder.cpp player/Player.cpp phase1/phase1.cpp phase3/phase3.cpp phase2/phase2.cpp phase4/phase4.cpp phase5/phase5.cpp
cflags= -o
program=proj
n_c_program=no_colors

#colors compile and run
proj:$(OBJECTS)
	$(cc) $(OBJECTS) -DCOLORS $(cflags) $(program)

run:$(program)
	./$(program)

#no colors compile and run
no_colors:$(OBJECTS)
	$(cc) $(OBJECTS) $(cflags) $(n_c_program)

run_no_colors:$(n_c_program)
	./$(n_c_program)

#delete all the programs
clean:
	rm -f $(program)
	rm -f $(n_c_program)
