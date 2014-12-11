#ifndef MIEL_H
#define MIEL_H

#include "Grille.h"

class Miel
{
public:
    Miel(Grille* grille, int x, int y);
    void remove();
    void draw(SDL_Renderer* renderer);

private:
    Grille* grille;
    int posX;
    int posY;
};

#endif // MIEL_H
