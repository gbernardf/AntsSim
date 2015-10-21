#include "Colony.h"

Colony::Colony(Grille* grille,int x, int y):
  grille(grille),
  posX(x),
  posY(y)
{
  setUp();
}

void Colony::setUp(){
    grille->getCase(posX,posY)->setColony(true);
    grille->getCase(posX+1,posY)->setColony(true);
    grille->getCase(posX+2,posY)->setColony(true);
    grille->getCase(posX+3,posY)->setColony(true);
    grille->getCase(posX,posY+1)->setColony(true);
    grille->getCase(posX,posY+2)->setColony(true);
    grille->getCase(posX,posY+3)->setColony(true);
    grille->getCase(posX+1,posY+1)->setColony(true);
    grille->getCase(posX+2,posY+2)->setColony(true);
    grille->getCase(posX+3,posY+3)->setColony(true);
    grille->getCase(posX+1,posY+2)->setColony(true);
    grille->getCase(posX+1,posY+3)->setColony(true);
    grille->getCase(posX+2,posY+1)->setColony(true);
    grille->getCase(posX+2,posY+3)->setColony(true);
    grille->getCase(posX+3,posY+1)->setColony(true);
    grille->getCase(posX+3,posY+2)->setColony(true);

    grille->getCase(posX,posY)->setPheromoneTravelLevel(255);
    grille->getCase(posX+1,posY)->setPheromoneTravelLevel(255);
    grille->getCase(posX+2,posY)->setPheromoneTravelLevel(255);
    grille->getCase(posX+3,posY)->setPheromoneTravelLevel(255);
    grille->getCase(posX,posY+1)->setPheromoneTravelLevel(255);
    grille->getCase(posX,posY+2)->setPheromoneTravelLevel(255);
    grille->getCase(posX,posY+3)->setPheromoneTravelLevel(255);
    grille->getCase(posX+1,posY+1)->setPheromoneTravelLevel(255);
    grille->getCase(posX+2,posY+2)->setPheromoneTravelLevel(255);
    grille->getCase(posX+3,posY+3)->setPheromoneTravelLevel(255);
    grille->getCase(posX+1,posY+2)->setPheromoneTravelLevel(255);
    grille->getCase(posX+1,posY+3)->setPheromoneTravelLevel(255);
    grille->getCase(posX+2,posY+1)->setPheromoneTravelLevel(255);
    grille->getCase(posX+2,posY+3)->setPheromoneTravelLevel(255);
    grille->getCase(posX+3,posY+1)->setPheromoneTravelLevel(255);
    grille->getCase(posX+3,posY+2)->setPheromoneTravelLevel(255);
}
