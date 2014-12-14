CC=g++
CFLAGS=-c -Wall -std=c++11
LIBS = -lSDL2 -lSDL2_ttf -lSDL2_image


all: ants

ants: main.o Grille.o Case.o Ant.o Miel.o Wall.o Colony.o Direction.o functions.o Bouton.o Settings.o BoutonWraper.o
	$(CC) main.o Grille.o Case.o Ant.o Miel.o Wall.o Colony.o Direction.o functions.o Bouton.o Settings.o BoutonWraper.o -o ants $(LIBS)

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

functions.o: functions.cpp functions.h
	$(CC) $(CFLAGS) functions.cpp $(LIBS)

Settings.o: Settings.cpp Settings.h
	$(CC) $(CFLAGS) Settings.cpp $(LIBS)

Bouton.o: Bouton.cpp Bouton.h
	$(CC) $(CFLAGS) Bouton.cpp $(LIBS)

BoutonWraper.o: BoutonWraper.cpp BoutonWraper.h Bouton.h Settings.h functions.h
	$(CC) $(CFLAGS) BoutonWraper.cpp $(LIBS)


clean:
	rm -rf *.o ants
