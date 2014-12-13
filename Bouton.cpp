#include "Bouton.h"

Bouton::Bouton(int* value){
    this->value = value;
}

void Bouton::setLocation(SDL_Rect location){
    this->location = location;

}

void Bouton::setToolbox(functions* toolbox){
    this->toolbox = toolbox;
}

void Bouton::loadTexture(std::string filePath){
    texture = toolbox->loadTexture(filePath);
}

void Bouton::setValuesModifications(int max, int min, int pas){
    maxValue = max;
    minValue = min;
    this->pas = pas;
}

void Bouton::draw(SDL_Renderer* renderer){
    SDL_QueryTexture(texture,NULL,NULL,&location.w,&location.h);
    SDL_RenderCopy(renderer,texture,NULL,&location);
}

void Bouton::upValue(){
    std::cout<<"Up !"<<std::endl;
    if(*value+pas <= maxValue)*value+=pas;
    std::cout<<*value<<std::endl;
}

void Bouton::lowerValue(){
    std::cout<<"Down !"<<std::endl;
    if(*value-pas >= minValue)*value-=pas;
    std::cout<<*value<<std::endl;
}

void Bouton::activate(){
    if(up){
        upValue();
    }else{
        lowerValue();
    }
}

void Bouton::setUp(bool isUpButton){
    up = isUpButton;
}

bool Bouton::hit(int x, int y){
    if(x>= location.x && x<= (location.x+location.w) && y>= location.y && y<= (location.y+location.h)){
        return true;
    }
    return false;
}

