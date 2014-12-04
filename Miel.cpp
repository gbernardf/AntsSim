#include "Miel.h"


Miel::Miel(Grille *grille, int x, int y){
    this->grille = grille;
    posX = x;
    posY = y;
}

void Miel::update(){
    grille->getCase(posX,posY)->setPheromoneFoodLevel(255);
    grille->getCase(posX+1,posY)->setPheromoneFoodLevel(255);
    grille->getCase(posX+2,posY)->setPheromoneFoodLevel(255);
    grille->getCase(posX+3,posY)->setPheromoneFoodLevel(255);
    grille->getCase(posX,posY+1)->setPheromoneFoodLevel(255);
    grille->getCase(posX,posY+2)->setPheromoneFoodLevel(255);
    grille->getCase(posX,posY+3)->setPheromoneFoodLevel(255);
    grille->getCase(posX+1,posY+1)->setPheromoneFoodLevel(255);
    grille->getCase(posX+2,posY+2)->setPheromoneFoodLevel(255);
    grille->getCase(posX+3,posY+3)->setPheromoneFoodLevel(255);
    grille->getCase(posX+1,posY+2)->setPheromoneFoodLevel(255);
    grille->getCase(posX+1,posY+3)->setPheromoneFoodLevel(255);
    grille->getCase(posX+2,posY+1)->setPheromoneFoodLevel(255);
    grille->getCase(posX+2,posY+3)->setPheromoneFoodLevel(255);
    grille->getCase(posX+3,posY+1)->setPheromoneFoodLevel(255);
    grille->getCase(posX+3,posY+2)->setPheromoneFoodLevel(255);
}

void Miel::draw(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xB4, 0x00, 0xFF );
    SDL_Rect fillMielRect = { posX*6, posY*6 ,24, 24};
    SDL_RenderFillRect( renderer, &fillMielRect );
}
