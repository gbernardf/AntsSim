#ifndef ANT_H
#define ANT_H
#include <SDL2/SDL.h>
#include "Grille.h"
#include <stdlib.h>
#include "Direction.h"
#include <list>

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
    std::list <Direction*> directions;
    Direction findMoreFood();
    Direction findLessFood();
    Direction findMoreTravel();
    Direction findLessTravel();

    void updateDirections();
    void getDirections();
    int posX;
    int posY;
    bool carrying;
    bool searching;
    void searchPos();
    void randPos();

    void draw();
    void diffuse();
    void spreadPheromoneFood(int x, int y, int food);
};

#endif // ANT_H
