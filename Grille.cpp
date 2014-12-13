#include "Grille.h"
#include "Settings.h"

Grille::Grille(SDL_Renderer* renderer, Settings* settings){
    for(int i = 0;i<100;i++){
        for(int j = 0; j<100;j++){
            cases[i][j] = new Case();
            niveauMiel[i][j] = 0;
        }
    }
    compteur = 0;
    this->renderer = renderer;
    this->settings = settings;
}


Case* Grille::getCase(int x, int y){
    if(x < 1 || x >98 || y < 1 || y > 98){
        return &dummyCase;
    }
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
    if(compteur == settings->tauxEvaPheromones){
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

void Grille::eat(int x, int y){
    niveauMiel[x][y]--;
    if(niveauMiel[x][y]==0)getCase(x,y)->setFood(false);
}

void Grille::addMiel(int x, int y){

    getCase(x,y)->setFood(true);
    getCase(x+1,y)->setFood(true);
    getCase(x+2,y)->setFood(true);
    getCase(x+3,y)->setFood(true);
    getCase(x,y+1)->setFood(true);
    getCase(x,y+2)->setFood(true);
    getCase(x,y+3)->setFood(true);
    getCase(x+1,y+1)->setFood(true);
    getCase(x+2,y+2)->setFood(true);
    getCase(x+3,y+3)->setFood(true);
    getCase(x+1,y+2)->setFood(true);
    getCase(x+1,y+3)->setFood(true);
    getCase(x+2,y+1)->setFood(true);
    getCase(x+2,y+3)->setFood(true);
    getCase(x+3,y+1)->setFood(true);
    getCase(x+3,y+2)->setFood(true);

    getCase(x,y)->setPheromoneFoodLevel(255);
    getCase(x+1,y)->setPheromoneFoodLevel(255);
    getCase(x+2,y)->setPheromoneFoodLevel(255);
    getCase(x+3,y)->setPheromoneFoodLevel(255);
    getCase(x,y+1)->setPheromoneFoodLevel(255);
    getCase(x,y+2)->setPheromoneFoodLevel(255);
    getCase(x,y+3)->setPheromoneFoodLevel(255);
    getCase(x+1,y+1)->setPheromoneFoodLevel(255);
    getCase(x+2,y+2)->setPheromoneFoodLevel(255);
    getCase(x+3,y+3)->setPheromoneFoodLevel(255);
    getCase(x+1,y+2)->setPheromoneFoodLevel(255);
    getCase(x+1,y+3)->setPheromoneFoodLevel(255);
    getCase(x+2,y+1)->setPheromoneFoodLevel(255);
    getCase(x+2,y+3)->setPheromoneFoodLevel(255);
    getCase(x+3,y+1)->setPheromoneFoodLevel(255);
    getCase(x+3,y+2)->setPheromoneFoodLevel(255);

    niveauMiel[x][y]=255;
    niveauMiel[x+1][y]=255;
    niveauMiel[x+2][y]=255;
    niveauMiel[x+3][y]=255;
    niveauMiel[x][y+1]=255;
    niveauMiel[x][y+2]=255;
    niveauMiel[x][y+3]=255;
    niveauMiel[x+1][y+1]=255;
    niveauMiel[x+2][y+2]=255;
    niveauMiel[x+3][y+3]=255;
    niveauMiel[x+1][y+2]=255;
    niveauMiel[x+1][y+3]=255;
    niveauMiel[x+2][y+1]=255;
    niveauMiel[x+2][y+3]=255;
    niveauMiel[x+3][y+1]=255;
    niveauMiel[x+3][y+2]=255;

}

void Grille::removeMiel(int x, int y){
    getCase(x,y)->setFood(false);
    getCase(x+1,y)->setFood(false);
    getCase(x+2,y)->setFood(false);
    getCase(x+3,y)->setFood(false);
    getCase(x,y+1)->setFood(false);
    getCase(x,y+2)->setFood(false);
    getCase(x,y+3)->setFood(false);
    getCase(x+1,y+1)->setFood(false);
    getCase(x+2,y+2)->setFood(false);
    getCase(x+3,y+3)->setFood(false);
    getCase(x+1,y+2)->setFood(false);
    getCase(x+1,y+3)->setFood(false);
    getCase(x+2,y+1)->setFood(false);
    getCase(x+2,y+3)->setFood(false);
    getCase(x+3,y+1)->setFood(false);
    getCase(x+3,y+2)->setFood(false);

    getCase(x,y)->setPheromoneFoodLevel(0);
    getCase(x+1,y)->setPheromoneFoodLevel(0);
    getCase(x+2,y)->setPheromoneFoodLevel(0);
    getCase(x+3,y)->setPheromoneFoodLevel(0);
    getCase(x,y+1)->setPheromoneFoodLevel(0);
    getCase(x,y+2)->setPheromoneFoodLevel(0);
    getCase(x,y+3)->setPheromoneFoodLevel(0);
    getCase(x+1,y+1)->setPheromoneFoodLevel(0);
    getCase(x+2,y+2)->setPheromoneFoodLevel(0);
    getCase(x+3,y+3)->setPheromoneFoodLevel(0);
    getCase(x+1,y+2)->setPheromoneFoodLevel(0);
    getCase(x+1,y+3)->setPheromoneFoodLevel(0);
    getCase(x+2,y+1)->setPheromoneFoodLevel(0);
    getCase(x+2,y+3)->setPheromoneFoodLevel(0);
    getCase(x+3,y+1)->setPheromoneFoodLevel(0);
    getCase(x+3,y+2)->setPheromoneFoodLevel(0);

    niveauMiel[x][y]=0;
    niveauMiel[x+1][y]=0;
    niveauMiel[x+2][y]=0;
    niveauMiel[x+3][y]=0;
    niveauMiel[x][y+1]=0;
    niveauMiel[x][y+2]=0;
    niveauMiel[x][y+3]=0;
    niveauMiel[x+1][y+1]=0;
    niveauMiel[x+2][y+2]=0;
    niveauMiel[x+3][y+3]=0;
    niveauMiel[x+1][y+2]=0;
    niveauMiel[x+1][y+3]=0;
    niveauMiel[x+2][y+1]=0;
    niveauMiel[x+2][y+3]=0;
    niveauMiel[x+3][y+1]=0;
    niveauMiel[x+3][y+2]=0;
}
