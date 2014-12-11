#include "Grille.h"

Grille::Grille(SDL_Renderer* renderer){
    for(int i = 0;i<100;i++){
        for(int j = 0; j<100;j++){
            cases[i][j] = new Case();

        }

    }
    compteur = 0;
    this->renderer = renderer;
}


Case* Grille::getCase(int x, int y){
    return cases[y][x];
}


void Grille::draw(){
    for(int i = 0;i<100;i++){
        for(int j = 0; j<100;j++){
            SDL_Rect fillRect = { j*6, i*6 ,6, 6};
            Uint8 foodLevel = cases[i][j]->getPheromoneFoodLevel();
            Uint8 travelLevel = cases[i][j]->getPheromoneTravelLevel();
            SDL_SetRenderDrawColor( renderer, foodLevel, 0x00, travelLevel, 0xFF );
            SDL_RenderFillRect( renderer, &fillRect );

        }

    }
}

void Grille::lowerPheromonLevel(){
    compteur ++;
    if(compteur == 10){
         for(int i = 0;i<100;i++){
            for(int j = 0; j<100;j++){
                if(!cases[i][j]->isColony() && !cases[i][j]->isFood()){
                    if(cases[i][j]->getPheromoneFoodLevel() > 0){
                        cases[i][j]->setPheromoneFoodLevel(cases[i][j]->getPheromoneFoodLevel() - 1 );
                    }
                    if(cases[i][j]->getPheromoneTravelLevel() > 0){
                        cases[i][j]->setPheromoneTravelLevel(cases[i][j]->getPheromoneTravelLevel() - 1 );
                    }
                }
            }
        }
        compteur = 0;
    }
   
}
