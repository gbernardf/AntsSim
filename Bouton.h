#ifndef BOUTON_H
#define BOUTON_H

#include "SDL2/SDL_image.h"
#include "functions.h"

class Bouton
{
public:
    Bouton(int* value);
    void setLocation(SDL_Rect location);
    void loadTexture(std::string filePath);
    void setToolbox(functions* toolbox);
    void setValuesModifications(int max, int min, int pas);
    void draw(SDL_Renderer* renderer);
    void setUp(bool isUpButton);
    void activate();
    bool hit(int x, int y);
    SDL_Rect location;
private:
    void upValue();
    void lowerValue();
    int* value;
    SDL_Texture* texture;
    SDL_Rect* viewPort;

    functions* toolbox;
    int pas;
    int maxValue;
    int minValue;
    bool up;

};

#endif // BOUTON_H
