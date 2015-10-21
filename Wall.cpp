#include "Wall.h"

Wall::Wall(Grille *grille, int x, int y):
    grille(grille),
    posX(x),
    posY(y)
{
    setUp();
}

void Wall::setUp(){
    grille->getCase(posX,posY)->setWall(true);
    grille->getCase(posX+1,posY)->setWall(true);
    grille->getCase(posX+2,posY)->setWall(true);
    grille->getCase(posX+3,posY)->setWall(true);
    grille->getCase(posX,posY+1)->setWall(true);
    grille->getCase(posX,posY+2)->setWall(true);
    grille->getCase(posX,posY+3)->setWall(true);
    grille->getCase(posX+1,posY+1)->setWall(true);
    grille->getCase(posX+2,posY+2)->setWall(true);
    grille->getCase(posX+3,posY+3)->setWall(true);
    grille->getCase(posX+1,posY+2)->setWall(true);
    grille->getCase(posX+1,posY+3)->setWall(true);
    grille->getCase(posX+2,posY+1)->setWall(true);
    grille->getCase(posX+2,posY+3)->setWall(true);
    grille->getCase(posX+3,posY+1)->setWall(true);
    grille->getCase(posX+3,posY+2)->setWall(true);

    grille->getCase(posX,posY)->setPheromoneFoodLevel(0);
    grille->getCase(posX+1,posY)->setPheromoneFoodLevel(0);
    grille->getCase(posX+2,posY)->setPheromoneFoodLevel(0);
    grille->getCase(posX+3,posY)->setPheromoneFoodLevel(0);
    grille->getCase(posX,posY+1)->setPheromoneFoodLevel(0);
    grille->getCase(posX,posY+2)->setPheromoneFoodLevel(0);
    grille->getCase(posX,posY+3)->setPheromoneFoodLevel(0);
    grille->getCase(posX+1,posY+1)->setPheromoneFoodLevel(0);
    grille->getCase(posX+2,posY+2)->setPheromoneFoodLevel(0);
    grille->getCase(posX+3,posY+3)->setPheromoneFoodLevel(0);
    grille->getCase(posX+1,posY+2)->setPheromoneFoodLevel(0);
    grille->getCase(posX+1,posY+3)->setPheromoneFoodLevel(0);
    grille->getCase(posX+2,posY+1)->setPheromoneFoodLevel(0);
    grille->getCase(posX+2,posY+3)->setPheromoneFoodLevel(0);
    grille->getCase(posX+3,posY+1)->setPheromoneFoodLevel(0);
    grille->getCase(posX+3,posY+2)->setPheromoneFoodLevel(0);
}

void Wall::clear(){
    grille->getCase(posX,posY)->setWall(false);
    grille->getCase(posX+1,posY)->setWall(false);
    grille->getCase(posX+2,posY)->setWall(false);
    grille->getCase(posX+3,posY)->setWall(false);
    grille->getCase(posX,posY+1)->setWall(false);
    grille->getCase(posX,posY+2)->setWall(false);
    grille->getCase(posX,posY+3)->setWall(false);
    grille->getCase(posX+1,posY+1)->setWall(false);
    grille->getCase(posX+2,posY+2)->setWall(false);
    grille->getCase(posX+3,posY+3)->setWall(false);
    grille->getCase(posX+1,posY+2)->setWall(false);
    grille->getCase(posX+1,posY+3)->setWall(false);
    grille->getCase(posX+2,posY+1)->setWall(false);
    grille->getCase(posX+2,posY+3)->setWall(false);
    grille->getCase(posX+3,posY+1)->setWall(false);
    grille->getCase(posX+3,posY+2)->setWall(false);
}
