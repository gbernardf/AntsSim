#ifndef GRILLE_H
#define GRILLE_H
#include <SDL2/SDL.h>

#include "Case.h"

class Grille
{
public:
    Grille(SDL_Renderer* renderer);
    Case *getCase(int x, int y);
    void draw();
    void lowerPheromonLevel();


private:
    Case* cases[100][100];
    SDL_Renderer* renderer = NULL;
    int compteur;
};

#endif // GRILLE_H
