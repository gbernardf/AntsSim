#include "Ant.h"

Ant::Ant(Grille *grille, SDL_Renderer *renderer)
{
    this->grille = grille;
    this->renderer = renderer;
    carrying = false;
    searching = true;
}


void Ant::move(){
    int travel = grille->getCase(posX,posY)->getPheromoneTravelLevel();
    int food = grille->getCase(posX,posY)->getPheromoneFoodLevel();

    if(food == 255)carrying = true;
    if((travel == 255) && (carrying == true)){
        carrying = false;
        searching = true;
    }
    if(carrying)searching = false;
    
    searchPos();
    if(posX < 0)posX=0;
    if(posX >=100)posX=99;
    if(posY < 0)posY=0;
    if(posY >= 100)posY=99;
    draw();
    travel -=3;
    food -= 3;
    if(travel<=0)travel=0;
    if(food<=0)food=0;
    if(grille->getCase(posX,posY)->getPheromoneTravelLevel()<travel){
        grille->getCase(posX,posY)->setPheromoneTravelLevel(travel);
    }
    if(grille->getCase(posX,posY)->getPheromoneFoodLevel()<food){
        grille->getCase(posX,posY)->setPheromoneFoodLevel(food);
    }
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
    if(carrying){
        int newPosX = 0;
        int newPosY = 0;
        int backTravel = grille->getCase(posX,posY)->getPheromoneTravelLevel();

        if((posX - 1 >= 0) && (posX + 1 < 100) && (posY - 1 >= 0) && (posY + 1 < 100)){
            if(grille->getCase(posX-1,posY+1)->getPheromoneTravelLevel()>backTravel){
                backTravel = grille->getCase(posX-1,posY+1)->getPheromoneTravelLevel();
                newPosX = posX-1;
                newPosY = posY+1;
            }
            if(grille->getCase(posX,posY+1)->getPheromoneTravelLevel()>backTravel){
                backTravel = grille->getCase(posX,posY+1)->getPheromoneTravelLevel();
                newPosX = posX;
                newPosY = posY+1;
            }
            if(grille->getCase(posX+1,posY+1)->getPheromoneTravelLevel()>backTravel){
                backTravel = grille->getCase(posX+1,posY+1)->getPheromoneTravelLevel();
                newPosX = posX+1;
                newPosY = posY+1;
            }
            if(grille->getCase(posX-1,posY)->getPheromoneTravelLevel()>backTravel){
                backTravel = grille->getCase(posX-1,posY)->getPheromoneTravelLevel();
                newPosX = posX-1;
                newPosY = posY;
            }
            if(grille->getCase(posX+1,posY)->getPheromoneTravelLevel()>backTravel){
                backTravel = grille->getCase(posX+1,posY)->getPheromoneTravelLevel();
                newPosX = posX+1;
                newPosY = posY;
            }
            if(grille->getCase(posX-1,posY-1)->getPheromoneTravelLevel()>backTravel){
                backTravel = grille->getCase(posX-1,posY-1)->getPheromoneTravelLevel();
                newPosX = posX-1;
                newPosY = posY-1;
            }
            if(grille->getCase(posX,posY-1)->getPheromoneTravelLevel()>backTravel){
                backTravel = grille->getCase(posX,posY-1)->getPheromoneTravelLevel();
                newPosX = posX;
                newPosY = posY-1;
            }
            if(grille->getCase(posX+1,posY-1)->getPheromoneTravelLevel()>backTravel){
                backTravel = grille->getCase(posX+1,posY-1)->getPheromoneTravelLevel();
                newPosX = posX+1;
                newPosY = posY-1;
            }
        }



        if(backTravel !=0){
            posX = newPosX;
            posY = newPosY;
        }else{
            randPos();
        }

    }else if(searching){
        int newPosX = 0;
        int newPosY = 0;
        int foodLevel = grille->getCase(posX,posY)->getPheromoneFoodLevel();

        if((posX - 1 >= 0) && (posX + 1 < 100) && (posY - 1 >= 0) && (posY + 1 < 100)){
            if(grille->getCase(posX-1,posY+1)->getPheromoneFoodLevel()>foodLevel){
                foodLevel = grille->getCase(posX-1,posY+1)->getPheromoneFoodLevel();
                newPosX = posX-1;
                newPosY = posY+1;
            }
            if(grille->getCase(posX,posY+1)->getPheromoneFoodLevel()>foodLevel){
                foodLevel = grille->getCase(posX,posY+1)->getPheromoneFoodLevel();
                newPosX = posX;
                newPosY = posY+1;
            }
            if(grille->getCase(posX+1,posY+1)->getPheromoneFoodLevel()>foodLevel){
                foodLevel = grille->getCase(posX+1,posY+1)->getPheromoneFoodLevel();
                newPosX = posX+1;
                newPosY = posY+1;
            }
            if(grille->getCase(posX-1,posY)->getPheromoneFoodLevel()>foodLevel){
                foodLevel = grille->getCase(posX-1,posY)->getPheromoneFoodLevel();
                newPosX = posX-1;
                newPosY = posY;
            }
            if(grille->getCase(posX+1,posY)->getPheromoneFoodLevel()>foodLevel){
                foodLevel = grille->getCase(posX+1,posY)->getPheromoneFoodLevel();
                newPosX = posX+1;
                newPosY = posY;
            }
            if(grille->getCase(posX-1,posY-1)->getPheromoneFoodLevel()>foodLevel){
                foodLevel = grille->getCase(posX-1,posY-1)->getPheromoneFoodLevel();
                newPosX = posX-1;
                newPosY = posY-1;
            }
            if(grille->getCase(posX,posY-1)->getPheromoneFoodLevel()>foodLevel){
                foodLevel = grille->getCase(posX,posY-1)->getPheromoneFoodLevel();
                newPosX = posX;
                newPosY = posY-1;
            }
            if(grille->getCase(posX+1,posY-1)->getPheromoneFoodLevel()>foodLevel){
                foodLevel = grille->getCase(posX+1,posY-1)->getPheromoneFoodLevel();
                newPosX = posX+1;
                newPosY = posY-1;
            }
        }



        if(foodLevel !=0){
            posX = newPosX;
            posY = newPosY;
        }else{
            randPos();
        }
    }else{
        randPos();
    }

}

void Ant::randPos(){
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
