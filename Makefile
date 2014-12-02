CC=g++
CFLAGS=-c -Wall
LIBS = -lSDL2

all: ANTU

ANTU: main.o Grille.o Case.o Ant.o
	$(CC) main.o Grille.o Case.o Ant.o -o ANTU $(LIBS)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp $(LIBS)

Case.o:Case.cpp Case.h
	$(CC) $(CFLAGS) Case.cpp $(LIBS)

Grille.o: Grille.cpp Grille.h Case.h
	$(CC) $(CFLAGS) Grille.cpp $(LIBS)

Ant.o: Ant.cpp Ant.h Grille.h Case.h
	$(CC) $(CFLAGS) Ant.cpp $(LIBS)

clean:
	rm -rf *o ANTU
