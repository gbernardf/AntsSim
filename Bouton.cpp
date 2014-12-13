#include "Bouton.h"

Bouton::Bouton(int* value){
    this->value = value;
}

void Bouton::setViewport(SDL_Rect* viewPort){
    this->viewPort = viewPort;
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
    if(*value+pas <= maxValue)*value+=pas;
}

void Bouton::lowerValue(){
    if(*value-pas >= minValue)*value-=pas;
}

