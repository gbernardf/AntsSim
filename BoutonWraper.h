#ifndef BOUTONWRAPER_H
#define BOUTONWRAPER_H
#include <SDL2/SDL_ttf.h>
#include "Bouton.h"
#include "functions.h"
#include "Settings.h"


class BoutonWraper
{
public:
    BoutonWraper(SDL_Renderer* renderer, functions* toolbox, Settings* settings);
    void generate();
    void handleClic(int x, int y);
    void draw();
private:
    SDL_Renderer* renderer;
    functions* toolbox;
    Settings* settings;
    std::list<Bouton*> boutons;
    std::list<SDL_Texture*> boutonsTitre;
    std::list<SDL_Texture*>instructions;
};

#endif // BOUTONWRAPER_H
