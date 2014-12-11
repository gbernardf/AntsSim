#include "Direction.h"

Direction::Direction(int x, int y){
    dirX = x;
    dirY = y;
}

int Direction::getX(){
    return dirX;
}

int Direction::getY(){
    return dirY;
}
