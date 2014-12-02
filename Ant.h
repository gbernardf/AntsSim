#ifndef ANT_H
#define ANT_H
#include <SDL2/SDL.h>
#include "Grille.h"
#include <stdlib.h>

class Ant
{
public:
    Ant(Grille* grille,SDL_Renderer* renderer);
    void move();
    int getPosX();
    int getPosY();
    void setPosX(int x);
    void setPosY(int y);


private:
    Grille* grille;
    SDL_Renderer* renderer;
    int posX;
    int posY;
    bool carrying;
    void searchPos();

    void draw();
};

#endif // ANT_H
