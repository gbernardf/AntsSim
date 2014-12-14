#ifndef WALL_H
#define WALL_H
#include "Grille.h"

class Wall
{
public:
    Wall(Grille *grille, int x, int y);
    void clear();

private:
    Grille* grille;
    int posX;
    int posY;
    void setUp();
};

#endif // WALL_H
