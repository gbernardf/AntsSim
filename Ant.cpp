#include "Ant.h"

Ant::Ant(Grille *grille, SDL_Renderer *renderer)
{
    this->grille = grille;
    this->renderer = renderer;
    carrying = false;
}


void Ant::move(){
    int travel = grille->getCase(posX,posY)->getPheromoneTravelLevel();
    int food = grille->getCase(posX,posY)->getPheromoneFoodLevel();
    
    searchPos();
    if(posX < 0)posX=0;
    if(posX >=100)posX=99;
    if(posY < 0)posY=0;
    if(posY >= 100)posY=99;
    draw();
    travel -=1;
    food -= 1;
    if(travel<=0)travel=0;
    if(food<=0)food=0;
    grille->getCase(posX,posY)->setPheromoneTravelLevel(travel);
    grille->getCase(posX,posY)->setPheromoneFoodLevel(food);
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

void Ant::searchPos(){
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
}
