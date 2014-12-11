#include <SDL2/SDL.h>
#include <iostream>

#include "Grille.h"
#include "Ant.h"
#include "Miel.h"
#include "Colony.h"

#include <list>


const int PIXEL_SIZE = 6;


int main(int argc, char* argv[]) {

    if(argc <= 1){
        std::cout<<"Arguments missing: WIDTH |  HEIGHT" <<std::endl;
    }

    const int SCREEN_WIDTH = atoi(argv[1]);
    const int SCREEN_HEIGHT = atoi(argv[2]);
    std::cout<< "SCREEN_WIDTH : " << SCREEN_WIDTH << std::endl;
    std::cout<< "SCREEN_HEIGHT: " << SCREEN_HEIGHT << std::endl;

    //Render window
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Init error ! SDL_Error: %s\n", SDL_GetError());
    } else {

        SDL_Event event;
        window = SDL_CreateWindow("ANTS ANTS PARTY !",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH,
                                    SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN
                                    );

        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);
        SDL_SetRenderDrawColor(renderer,0x00,0x00,0x00,0x00);
        SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_ADD);

        if (window == NULL) {
            printf("Window could not be created! SDL_Error:%s\n", SDL_GetError());
        } else {

            Grille grille(renderer);

            int colonyX = 90;
            int colonyY = 90;
            Colony colony(colonyX,colonyY);
            colony.setGrille(&grille);
            std::list <Miel*> miels;
            int antNumber = 75;
            Ant*family[antNumber];
            for(int i=0;i<antNumber;i++){
                family[i] = new Ant(&grille,renderer);
                family[i]->setPosX(colonyX);
                family[i]->setPosY(colonyY);
            }

            bool run = true;
            do{
                SDL_SetRenderDrawColor(renderer,0x00,0x00,0x00,0x00);
                SDL_RenderClear(renderer);

                while(SDL_PollEvent(&event) != 0){

                    if(event.type == SDL_QUIT){
                        run = false;
                    }else if(event.type == SDL_KEYDOWN){

                        switch(event.key.keysym.sym){
                            case SDLK_ESCAPE:
                            run = false;break;
                            case SDLK_SPACE:
                            if(!miels.empty()){
                                miels.front()->remove();
                                miels.pop_front();
                            }
                        }

                    }else if(event.type == SDL_MOUSEBUTTONDOWN){
                        Miel* miel2 = new Miel(&grille,event.button.x/6,event.button.y/6);
                        miels.push_back(miel2);
                    }
                }


                grille.draw();
                grille.lowerPheromonLevel();

                for(int i=0;i<antNumber;i++){
                    family[i]->move();
                }

                if(!miels.empty()){
                    for (std::list<Miel*>::const_iterator it = miels.begin(), end = miels.end(); it != end; ++it) {
                        (*it)->draw(renderer);
                    }
                }
                colony.draw(renderer);
                SDL_RenderPresent(renderer);
                //SDL_Delay(50);

            }while(run);
        }

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
