#ifndef COLONY_H
#define COLONY_H

#include "Grille.h"

class Colony
{
public:
    Colony(Grille *grille, int x, int y);
private:
    Grille* grille;
    int posX;
    int posY;

    void setUp();
};

#endif // COLONY_H
