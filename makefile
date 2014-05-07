CFLAGS = -Wall -g
CC = gcc
default: minesweeper.o io.o game.o scanner.o
	$(CC) $(CFLAGS) -o cMinesweeper minesweeper.o io.o game.o scanner.o
all: minesweeper level1 level2 level3 level4 level5
minesweeper: minesweeper.o io.o game.o scanner.o
	$(CC) $(CFLAGS) -o cMinesweeper minesweeper.o io.o game.o scanner.o
minesweeper.o: game.h io.h minesweeper.c
	$(CC) $(CFLAGS) -c minesweeper.c
io.o: io.h io.c
	$(CC) $(CFLAGS) -c io.c
game.o: scanner.h game.h io.h game.c
	$(CC) $(CFLAGS) -c game.c
level5: level5.o io.o game.o scanner.o 
	$(CC) $(CFLAGS) -o level5 level5.o io.o game.o scanner.o
level5.o: game.h io.h level5.c
	$(CC) $(CFLAGS) -c level5.c
level4: level4.o io.o game.o scanner.o
	$(CC) $(CFLAGS) -o level4 level4.o io.o game.o scanner.o
level4.o: game.h io.h level4.c
	$(CC) $(CFLAGS) -c level4.c
level3: level3.o io.o game.o scanner.o
	$(CC) $(CFLAGS) -o level3 level3.o io.o game.o scanner.o
level3.o: game.h io.h level3.c
	$(CC) $(CFLAGS) -c level3.c
level2: level2.o io.o game.o scanner.o
	$(CC) $(CFLAGS) -o level2 level2.o io.o game.o scanner.o
level2.o: game.h io.h level2.c
	$(CC) $(CFLAGS) -c level2.c
level1: level1.o io.o game.o scanner.o
	$(CC) $(CFLAGS) -o level1 level1.o io.o game.o scanner.o
level1.o: game.h io.h level1.c
	$(CC) $(CFLAGS) -c level1.c
level0: level0.o io.o game.o scanner.o
	$(CC) $(CFLAGS) -o level0 level0.o io.o game.o scanner.o
level0.o: game.h io.h level0.c
	$(CC) $(CFLAGS) -c level0.c
clean:
	$(RM) *.o
