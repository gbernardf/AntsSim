#include "Miel.h"


Miel::Miel(Grille *grille, int x, int y){
    this->grille = grille;
    posX = x;
    posY = y;
    grille->addMiel(posX,posY);


}

void Miel::remove(){
    grille->getCase(posX,posY)->setFood(false);
    grille->getCase(posX+1,posY)->setFood(false);
    grille->getCase(posX+2,posY)->setFood(false);
    grille->getCase(posX+3,posY)->setFood(false);
    grille->getCase(posX,posY+1)->setFood(false);
    grille->getCase(posX,posY+2)->setFood(false);
    grille->getCase(posX,posY+3)->setFood(false);
    grille->getCase(posX+1,posY+1)->setFood(false);
    grille->getCase(posX+2,posY+2)->setFood(false);
    grille->getCase(posX+3,posY+3)->setFood(false);
    grille->getCase(posX+1,posY+2)->setFood(false);
    grille->getCase(posX+1,posY+3)->setFood(false);
    grille->getCase(posX+2,posY+1)->setFood(false);
    grille->getCase(posX+2,posY+3)->setFood(false);
    grille->getCase(posX+3,posY+1)->setFood(false);
    grille->getCase(posX+3,posY+2)->setFood(false);
}

void Miel::draw(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xB4, 0x00, 0xFF );
    SDL_Rect fillMielRect = { posX*6, posY*6 ,24, 24};
    SDL_RenderFillRect( renderer, &fillMielRect );
}
