CC=g++
CFLAGS=-c -Wall
LIBS = -lSDL2

all: ANTU

ANTU: main.o Grille.o Case.o Ant.o Miel.o
	$(CC) main.o Grille.o Case.o Ant.o Miel.o -o ANTU $(LIBS)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp $(LIBS)

Case.o:Case.cpp Case.h
	$(CC) $(CFLAGS) Case.cpp $(LIBS)

Grille.o: Grille.cpp Grille.h Case.h
	$(CC) $(CFLAGS) Grille.cpp $(LIBS)

Ant.o: Ant.cpp Ant.h Grille.h Case.h
	$(CC) $(CFLAGS) Ant.cpp $(LIBS)

Miel.o: Miel.cpp Miel.h Grille.h
	$(CC) $(CFLAGS) Miel.cpp $(LIBS)


clean:
	rm -rf *o ANTU
