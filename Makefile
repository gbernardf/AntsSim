CC=g++
CFLAGS=-c -Wall
LIBS = -lSDL2

all: ANTU

ANTU: main.o Grille.o Case.o Ant.o Miel.o Wall.o Colony.o Direction.o
	$(CC) main.o Grille.o Case.o Ant.o Miel.o Wall.o Colony.o Direction.o -o ANTU $(LIBS)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp $(LIBS)

Case.o:Case.cpp Case.h
	$(CC) $(CFLAGS) Case.cpp $(LIBS)

Grille.o: Grille.cpp Grille.h Case.h
	$(CC) $(CFLAGS) Grille.cpp $(LIBS)

Ant.o: Ant.cpp Ant.h Grille.h Case.h Direction.h
	$(CC) $(CFLAGS) Ant.cpp $(LIBS)

Miel.o: Miel.cpp Miel.h Grille.h
	$(CC) $(CFLAGS) Miel.cpp $(LIBS)

Colony.o: Colony.cpp Colony.h Grille.h
	$(CC) $(CFLAGS) Colony.cpp $(LIBS)

Wall.o: Wall.cpp Wall.h Grille.h
	$(CC) $(CFLAGS) Wall.cpp $(LIBS)

Direction.o: Direction.cpp Direction.h
	$(CC) $(CFLAGS) Direction.cpp $(LIBS)


clean:
	rm -rf *o ANTU
