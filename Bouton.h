#ifndef BOUTON_H
#define BOUTON_H

#include "SDL2/SDL_image.h"
#include "functions.h"

class Bouton
{
public:
    Bouton(int* value);
    void setViewport(SDL_Rect* viewPort);
    void setLocation(SDL_Rect location);
    void loadTexture(std::string filePath);
    void setToolbox(functions* toolbox);
    void setValuesModifications(int max, int min, int pas);
    void draw(SDL_Renderer* renderer);
    void upValue();
    void lowerValue();
private:
    int* value;
    SDL_Texture* texture;
    SDL_Rect* viewPort;
    SDL_Rect location;
    functions* toolbox;
    int pas;
    int maxValue;
    int minValue;

};

#endif // BOUTON_H
