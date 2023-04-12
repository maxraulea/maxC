//
//  StartScreen.c
//  Max's Snake
//
//  Created by Max Raulea on 07/04/2023.
//

#include <unistd.h>

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

#include "StartScreen.h"
#include "PrintText.h"

int StartGame(SDL_Renderer *Renderer, int xMiddle, int yMiddle, int Fontsize){

    TTF_Font *title = TTF_OpenFont("title.ttf", Fontsize);
    TTF_Font *description = TTF_OpenFont("description.ttf", Fontsize/2.5);
    if (!title || !description){
        return 1;
    }
    
    SDL_Event e;
    int quit = 0;
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);
    while (!quit){
        usleep(400000);
        SDL_RenderClear(Renderer);
        PrintText(Renderer, title, "SNAKE", xMiddle, yMiddle);
        SDL_RenderPresent(Renderer);
        
        while (SDL_PollEvent(&e)){
            if (e.key.keysym.sym == SDLK_RETURN){
                quit = 1;
                return 0;
            }
        }
        usleep(400000);
        PrintText(Renderer, description, "PRESS ENTER TO START", xMiddle, yMiddle + 50);
        SDL_RenderPresent(Renderer);
    }
    
    return 1;
}
