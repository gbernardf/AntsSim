#include "Case.h"

Case::Case(){
    pheromoneFoodLevel = 0;
    pheromoneTravelLevel = 0;
    food = false;
    colony = false;
    wall = false;
}


bool Case::isFood(){
    return food;
}

bool Case::isColony(){
    return colony;
}

bool Case::isWall(){
    return wall;
}

int Case::getPheromoneFoodLevel(){
    return pheromoneFoodLevel;
}

int Case::getPheromoneTravelLevel(){
    return pheromoneTravelLevel;
}

void Case::setPheromoneFoodLevel(int level){
    pheromoneFoodLevel = level;
}

void Case::setPheromoneTravelLevel(int pheromoneTravelLevel){
    this->pheromoneTravelLevel = pheromoneTravelLevel;
}

void Case::setFood(bool food){
    this->food = food;
}

void Case::setColony(bool colony){
    this->colony = colony;
}

void Case::setWall(bool wall){
    this->wall = wall;
}
