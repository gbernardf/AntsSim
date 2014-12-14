#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "Grille.h"
#include "Ant.h"
#include "Miel.h"
#include "Colony.h"
#include "Wall.h"
#include "functions.h"
#include "Settings.h"
#include "BoutonWraper.h"

#include <list>

int main(int argc, char* argv[]) {

    if(argc <= 1){
        std::cout<<"Arguments missing: ANTS NUMBER" <<std::endl;
        return 1;
    }

    const int ANTS_NUMBER = atoi(argv[1]);
    const int SCREEN_WIDTH = 1200;
    const int SCREEN_HEIGHT = 600;
    functions toolbox(SCREEN_WIDTH,SCREEN_HEIGHT);


    std::cout<< "SCREEN_WIDTH : " << SCREEN_WIDTH << std::endl;
    std::cout<< "SCREEN_HEIGHT: " << SCREEN_HEIGHT << std::endl;
    std::cout<< "Ants number: " << ANTS_NUMBER << std::endl;

    //Render window
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Surface* screenSurface = NULL;
    
    

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Init error ! SDL_Error: %s\n", SDL_GetError());
    } else {

        SDL_Event event;
        window = toolbox.createWindow("Swarm Intelligence.");
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);
        SDL_SetRenderDrawColor(renderer,0x00,0x00,0x00,0x00);
        SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_ADD);
        toolbox.setRenderer(renderer);
        int imgFlags = IMG_INIT_PNG;
        

        SDL_Rect mapViewPort;
        mapViewPort.x = 600;
        mapViewPort.y = 0;
        mapViewPort.w = 600;
        mapViewPort.h = 600;
        SDL_Rect statsViewPort;
        statsViewPort.x = 0;
        statsViewPort.y = 0;
        statsViewPort.w = 600;
        statsViewPort.h = 600;

        
        IMG_Init(imgFlags);
        TTF_Init();
        if (window == NULL) {
            printf("Window could not be created! SDL_Error:%s\n", SDL_GetError());
        } else {
            screenSurface = SDL_GetWindowSurface(window);
            toolbox.setScreenSurface(screenSurface);
            toolbox.setFont("/usr/share/cups/fonts/FreeMonoBold.ttf");
            Settings* settings = new Settings();
            Grille grille(renderer, settings);
            BoutonWraper boutons(renderer,&toolbox,settings);
            boutons.generate();


            std::list <Miel*> miels;
            std::list <Wall*> walls;
            Ant*family[ANTS_NUMBER];
            for(int i=0;i<ANTS_NUMBER;i++){
                family[i] = new Ant(&grille,renderer,settings);
            }
            bool goAntsGo = false;
            bool run = true;
            bool noColony = true;
            do{
                SDL_SetRenderDrawColor(renderer,0x00,0x00,0x00,0x00);
                SDL_RenderClear(renderer);
                SDL_RenderSetViewport(renderer,&statsViewPort);
                SDL_Rect fillRect = { statsViewPort.x, statsViewPort.y ,statsViewPort.w, statsViewPort.h};
                SDL_SetRenderDrawColor( renderer, 0x00, 0x72, 0x92, 0xFF );
                SDL_RenderFillRect( renderer, &fillRect );
                SDL_RenderSetViewport(renderer,&mapViewPort);

                while(SDL_PollEvent(&event) != 0){

                    if(event.type == SDL_QUIT){
                        run = false;
                    }else if(event.type == SDL_KEYDOWN){
                        int x;
                        int y;
                        SDL_GetMouseState( &x, &y );
                        SDL_Keycode key = event.key.keysym.sym;
                        if(key == SDLK_ESCAPE){
                            run = false;
                        }else if(key == SDLK_w){
                            if(toolbox.inSpace(x,y,&mapViewPort)){
                                x = (x-600)/6;
                                y = y/6;
                                Wall* wall = new Wall(&grille,x,y);
                                walls.push_back(wall);
                            }
                        }else if(key == SDLK_d){
                            for (std::list <Wall*> ::const_iterator it = walls.begin(), end = walls.end(); it != end; ++it) {
                                (*it)->clear();
                            }

                        }else if(key == SDLK_m){
                            if(toolbox.inSpace(x,y,&mapViewPort)){
                                x = (x-600)/6;
                                y = y/6;
                                Miel* miel = new Miel(&grille,x,y);
                                miels.push_back(miel);
                            }
                        }else if(key == SDLK_a){
                            if(!noColony)goAntsGo = !goAntsGo;
                        }else if(key == SDLK_SPACE){
                            if(!miels.empty()){
                                miels.front()->remove();
                                miels.pop_front();
                            }
                        }else if(key == SDLK_c && noColony){
                            noColony = false;
                            x = (x-600)/6;
                            y = y/6;
                            Colony colony(&grille,x,y);
                            for(int i=0;i<ANTS_NUMBER;i++){
                                family[i]->setPosX(x);
                                family[i]->setPosY(y);
                            }
                        }else if(key == SDLK_x){
                            noColony = true;
                            goAntsGo = false;
                            for (std::list <Wall*> ::const_iterator it = walls.begin(), end = walls.end(); it != end; ++it) {
                                delete(*it);
                            }
                            for (std::list <Miel*> ::const_iterator it = miels.begin(), end = miels.end(); it != end; ++it) {
                                delete(*it);
                            }
                            walls.clear();
                            miels.clear();
                            grille.clear();
                        }
                    }else if(event.type == SDL_MOUSEBUTTONDOWN){
                        int x;
                        int y;
                        SDL_GetMouseState( &x, &y );
                        boutons.handleClic(x,y);
                    }
                }
                grille.draw();
                grille.lowerPheromonLevel();

                if(goAntsGo){
                    for(int i=0;i<ANTS_NUMBER;i++){
                        family[i]->move();
                    }
                }
                SDL_RenderSetViewport(renderer,&statsViewPort);
                boutons.draw();
                SDL_RenderPresent(renderer);
                //SDL_Delay(50);

            }while(run);
        }

    }
    toolbox.cleanSurfaces();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}





