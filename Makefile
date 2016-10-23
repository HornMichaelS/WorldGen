CC = g++
CFLAGS = -lncurses
OBJ = worldgen.o world.o worldcell.o

worldgen: $(OBJ)
	$(CC) -o worldgen $(OBJ) $(CFLAGS)

worldgen.o: world.h
world.o: world.h worldcell.h
worldcell.o: worldcell.h

clean:
	rm -f *.o