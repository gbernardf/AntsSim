#ifndef ANT_H
#define ANT_H
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <list>
#include "Direction.h"
#include "Grille.h"
#include "Settings.h"

class Ant
{
public:
    Ant(Grille* grille,SDL_Renderer* renderer, Settings* settings);
    void move();
    int getPosX();
    int getPosY();
    void setPosX(int x);
    void setPosY(int y);


private:
    Settings* settings;
    Grille* grille;
    SDL_Renderer* renderer;
    std::list <Direction*> directions;
    int posX;
    int posY;
    bool carrying;
    bool searching;

    Direction findMoreFood();
    Direction findLessFood();
    Direction findMoreTravel();
    Direction findLessTravel();

    void updateDirections();
    void getDirections();
    void shuffleDirections();

    void searchPos();
    void randPos();

    void draw();
    void diffuse();
    void spreadPheromoneFood(int x, int y, int food);
};

#endif // ANT_H
