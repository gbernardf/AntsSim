#ifndef GRILLE_H
#define GRILLE_H
#include <SDL2/SDL.h>
#include "Settings.h"
#include "Case.h"

class Grille
{
public:
    Grille(SDL_Renderer* renderer, Settings* settings);
    Case *getCase(int x, int y);
    void draw();
    void lowerPheromonLevel();
    void eat(int x, int y);
    void addMiel(int x, int y);
    void removeMiel(int x, int y);
    void clear();


private:
    Case dummyCase;
    Case* cases[100][100];
    int niveauMiel[100][100];
    SDL_Renderer* renderer = NULL;
    Settings* settings;
    int compteur;

};

#endif // GRILLE_H
