#include "Ant.h"

Ant::Ant(Grille *grille, SDL_Renderer *renderer)
{
    this->grille = grille;
    this->renderer = renderer;
    carrying = false;
}


void Ant::move(){
    int position = rand()%8 +1;
    switch(position){
        case 1:
            posX-=1;
            posY+=1;
            break;
        case 2:
            posY+=1;
            break;
        case 3:
            posX+=1;
            posY+=1;
            break;
        case 4:
            posX-=1;
            break;
        case 5:
            posX+=1;
            break;
        case 6:
            posX-=1;
            posY-=1;
            break;
        case 7:
            posY-=1;
            break;
        case 8:
            posX+=1;
            posY-=1;
            break;

    }
    if(posX < 0)posX=0;
    if(posX >=100)posX=99;
    if(posY < 0)posY=0;
    if(posY >= 100)posY=99;
    draw();
    int travel = grille->getCase(posX,posY)->getPheromoneTravelLevel();
    travel += 50;
    if(travel>=255)travel=255;
    grille->getCase(posX,posY)->setPheromoneTravelLevel(travel);
}

void Ant::draw(){
    SDL_Rect fillRect = { posX*6, posY*6 ,6, 6};
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderFillRect( renderer, &fillRect );
}


int Ant::getPosX(){
    return posX;
}

int Ant::getPosY(){
    return posY;
}

void Ant::setPosX(int x){
    posX = x;
}

void Ant::setPosY(int y){
    posY = y;
}
