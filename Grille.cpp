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
            if(cases[i][j]->isColony()){
                SDL_SetRenderDrawColor( renderer, 0x00, 0xFF, 0x00, 0xFF );
            }else if(cases[i][j]->isFood()){
                SDL_SetRenderDrawColor( renderer, 0xFF, 0xB4, 0x00, 0xFF );
            }else if(cases[i][j]->isWall()){
                SDL_SetRenderDrawColor( renderer, 0x85, 0x85, 0x85, 0xFF );
            }else{
                Uint8 foodLevel = cases[i][j]->getPheromoneFoodLevel();
                Uint8 travelLevel = cases[i][j]->getPheromoneTravelLevel();
                SDL_SetRenderDrawColor( renderer, foodLevel, 0x00, travelLevel, 0xFF );
            }
            SDL_RenderFillRect( renderer, &fillRect );

        }

    }
}

void Grille::lowerPheromonLevel(){
    compteur ++;
    int lowerLevel = 1;
    if(compteur == 25){
         for(int i = 0;i<100;i++){
            for(int j = 0; j<100;j++){
                if(!cases[i][j]->isColony() && !cases[i][j]->isFood()){
                    if(cases[i][j]->getPheromoneFoodLevel() > lowerLevel-1){
                        cases[i][j]->setPheromoneFoodLevel(cases[i][j]->getPheromoneFoodLevel() - lowerLevel );
                    }
                    if(cases[i][j]->getPheromoneTravelLevel() > lowerLevel-1){
                        cases[i][j]->setPheromoneTravelLevel(cases[i][j]->getPheromoneTravelLevel() - lowerLevel);
                    }
                }else if(cases[i][j]->isColony()){
                    if(cases[i][j]->getPheromoneFoodLevel() > lowerLevel-1){
                        cases[i][j]->setPheromoneFoodLevel(cases[i][j]->getPheromoneFoodLevel() - lowerLevel );
                    }
                }else if(cases[i][j]->isFood()){
                    if(cases[i][j]->getPheromoneTravelLevel() > lowerLevel-1){
                        cases[i][j]->setPheromoneTravelLevel(cases[i][j]->getPheromoneTravelLevel() - lowerLevel );
                    }
                }
            }
        }
        compteur = 0;
    }
   
}
