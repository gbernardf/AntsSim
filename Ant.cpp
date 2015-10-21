#include "Ant.h"
#include <iostream>

Ant::Ant(Grille *grille, SDL_Renderer *renderer, Settings* settings):
  settings(settings),
  grille(grille),
  renderer(renderer),
  directions(),
  posX(0),
  posY(0),
  carrying(false),
  searching(true)
{
}


void Ant::move(){
    if(grille->getCase(posX,posY)->isWall())return;
    int travel = grille->getCase(posX,posY)->getPheromoneTravelLevel();
    int food = grille->getCase(posX,posY)->getPheromoneFoodLevel();

    if(grille->getCase(posX,posY)->isFood()&&searching == true){
        carrying = true;
        searching = false;
        if(settings->foodConsume==1)grille->eat(posX,posY);
    }
    if((grille->getCase(posX,posY)->isColony()) && (carrying == true)){
        carrying = false;
        searching = true;
    }

    searchPos();
    draw();
    travel -=2;
    food -= 2;
    if(travel<=0)travel=0;
    if(food<=0)food=0;
    if(grille->getCase(posX,posY)->getPheromoneTravelLevel()<travel){
        grille->getCase(posX,posY)->setPheromoneTravelLevel(travel);
    }
    if(grille->getCase(posX,posY)->getPheromoneFoodLevel()<food){
        grille->getCase(posX,posY)->setPheromoneFoodLevel(food);
    }
    diffuse();
}

void Ant::draw(){
    int r = 0xFF;
    int g = 0xFF;
    int b = 0xFF;
    if(carrying){
        r = 0x00;
        b = 0x00;
    }
    SDL_Rect fillRect = { posX*6, posY*6 ,6, 6};
    SDL_SetRenderDrawColor( renderer, r, g, b, 0xFF );
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
    getDirections();
    int odds = rand()%1000 ;
    if(odds>settings->randomFourmis){
        Direction newDirection(posX,posY);
        if(searching){
            newDirection = findMoreFood();

        }else if(carrying){
            newDirection = findMoreTravel();
        }
        if(newDirection.getX() == posX && newDirection.getY() == posY){
            randPos();
        }else{
            posX = newDirection.getX();
            posY = newDirection.getY();
        }
    }else{
        randPos();
    }


}

Direction Ant::findMoreFood(){
    int food = grille->getCase(posX,posY)->getPheromoneFoodLevel();
    int newPosX = posX;
    int newPosY = posY;
    for (std::list<Direction*>::const_iterator it = directions.begin(), end = directions.end(); it != end; ++it) {
        int x = (*it)->getX();
        int y = (*it)->getY();
        if(grille->getCase(x,y)->getPheromoneFoodLevel() > food){
            newPosX = x;
            newPosY = y;
        }
    }
    return Direction(newPosX,newPosY);
}

Direction Ant::findMoreTravel(){
    int travel = grille->getCase(posX,posY)->getPheromoneTravelLevel();
    int newPosX = posX;
    int newPosY = posY;
    for (std::list<Direction*>::const_iterator it = directions.begin(), end = directions.end(); it != end; ++it) {
        int x = (*it)->getX();
        int y = (*it)->getY();
        if(grille->getCase(x,y)->getPheromoneTravelLevel() > travel){
            newPosX = x;
            newPosY = y;
        }
    }
    return Direction(newPosX,newPosY);
}

void Ant::randPos(){
    int randomPosition = rand()%directions.size();
    int compteur = 0;
    for (std::list<Direction*>::const_iterator it = directions.begin(), end = directions.end(); it != end; ++it) {
        if(compteur == randomPosition){
            posX = (*it)->getX();
            posY = (*it)->getY();
        }
        compteur++;
    }
}

void Ant::getDirections(){
    for (std::list<Direction*>::const_iterator it = directions.begin(), end = directions.end(); it != end; ++it) {
       delete(*it);
    }
    directions.clear();
    Direction* nw = new Direction(posX-1, posY-1);
    Direction* n = new Direction(posX, posY-1);
    Direction* ne = new Direction(posX+1,posY-1);
    Direction* w = new Direction(posX-1, posY);
    Direction* e = new Direction(posX+1, posY);
    Direction* sw = new Direction(posX-1, posY+1);
    Direction* s = new Direction(posX, posY+1);
    Direction* se = new Direction(posX+1, posY+1);
    directions.push_back(w);
    directions.push_back(ne);
    directions.push_back(n);
    directions.push_back(sw);
    directions.push_back(e);
    directions.push_back(nw);
    directions.push_back(se);
    directions.push_back(s);
    updateDirections();
    shuffleDirections();
}

void Ant::updateDirections(){
    for (std::list<Direction*>::const_iterator it = directions.begin(), end = directions.end(); it != end; ++it) {
        int x = (*it)->getX();
        int y = (*it)->getY();
        if( x<1 || x>98 || y<1 || y>98 ){
            directions.remove(*it);
            --it;
        }else if(grille->getCase(x,y)->isWall()){
            directions.remove(*it);
            --it;
        }
    }
}

void Ant::shuffleDirections(){
    std::list<Direction*>shuffledDir;
    unsigned int directionSize = directions.size();
    do{
        int randomPosition = rand()%directions.size();
        int compteur = 0;
        for (std::list<Direction*>::const_iterator it = directions.begin(), end = directions.end(); it != end; ++it) {
            if(compteur == randomPosition){
                shuffledDir.push_back(*it);
                directions.remove(*it);
                --it;
            }
            compteur++;
        }
    }while(shuffledDir.size() < directionSize);
    directions = shuffledDir;

}

void Ant::diffuse(){
    int foodLevel = grille->getCase(posX,posY)->getPheromoneFoodLevel();
    spreadPheromoneFood(posX-1, posY-1,foodLevel);
    spreadPheromoneFood(posX+1,posY-1,foodLevel);
    spreadPheromoneFood(posX-1, posY,foodLevel);
    spreadPheromoneFood(posX+1, posY,foodLevel);
    spreadPheromoneFood(posX-1, posY+1,foodLevel);
    spreadPheromoneFood(posX, posY+1,foodLevel);
    spreadPheromoneFood(posX+1, posY+1,foodLevel);

    spreadPheromoneFood(posX-2, posY-2,foodLevel/2);
    spreadPheromoneFood(posX-1, posY-2,foodLevel/2);
    spreadPheromoneFood(posX, posY-2,foodLevel/2);
    spreadPheromoneFood(posX+1, posY-2,foodLevel/2);
    spreadPheromoneFood(posX+2, posY-2,foodLevel/2);

    spreadPheromoneFood(posX-2, posY-1,foodLevel/2);
    spreadPheromoneFood(posX-2, posY,foodLevel/2);
    spreadPheromoneFood(posX-2, posY+1,foodLevel/2);
    spreadPheromoneFood(posX-2, posY+2,foodLevel/2);
    spreadPheromoneFood(posX-1, posY+2,foodLevel/2);
    spreadPheromoneFood(posX, posY+2,foodLevel/2);
    spreadPheromoneFood(posX+1, posY+2,foodLevel/2);
    spreadPheromoneFood(posX+2, posY+2,foodLevel/2);

    spreadPheromoneFood(posX+2, posY-1,foodLevel/2);
    spreadPheromoneFood(posX+2, posY,foodLevel/2);
    spreadPheromoneFood(posX+2, posY+1,foodLevel/2);



}

void Ant::spreadPheromoneFood(int x, int y, int food){
    if(x>0 && x <99 && y > 0 && y<99){
        food /= 2;
        if(!grille->getCase(x,y)->isFood()&&grille->getCase(x, y)->getPheromoneFoodLevel()<food)grille->getCase(x, y)->setPheromoneFoodLevel(food);
    }
}
